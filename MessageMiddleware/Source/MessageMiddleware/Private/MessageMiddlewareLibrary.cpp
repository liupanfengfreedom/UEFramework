// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageMiddlewareLibrary.h"
#include "MessageManager.h"
#include "JsonUtilities.h"
#include "Json.h"
TMap<FString, FString> UMessageMiddlewareLibrary::blackboard;
void UMessageMiddlewareLibrary::sendmessage(const FString& id, const FString& payload)
{
	FString tempstr = payload;
	SENDMESSAGE(id, &tempstr);
}
void UMessageMiddlewareLibrary::sendmessagefaster(const FString& id, FString& payload)
{
	SENDMESSAGE(id, &payload);
}
void UMessageMiddlewareLibrary::addmessagelistener(UObject* instance, const FString& id, FOnsetlistenerevent func)
{
	ADDMESSAGELISTEN(instance, id,
		[func](const void* const pd) {
			func.ExecuteIfBound(*(FString*)pd);
		}
	)
}
void UMessageMiddlewareLibrary::removemessagelistener(UObject* instance)
{
	REMOVEMESSAGELISTEN(instance);
}
void UMessageMiddlewareLibrary::kvtojsonstring(const TArray<Fjsonobjkv>& array, FString& outstring)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	for (int i = 0; i < array.Num(); i++)
	{
		switch (array[i].value.type)
		{
		case 1:
			ImportGroups->SetStringField(array[i].key, array[i].value.str);
			break;
		case 2:
			ImportGroups->SetNumberField(array[i].key, array[i].value.f);

			break;
		case 3:
			ImportGroups->SetBoolField(array[i].key, array[i].value.b);
			break;
		default:
			break;
		}
	}
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&outstring);
	FJsonSerializer::Serialize(ImportGroups.ToSharedRef(), Writer);
}
void UMessageMiddlewareLibrary::createjsonstringkv(const FString& k, const FString& v, Fjsonobjkv& kv)
{
	kv.key = k;
	kv.value.str = v;
	kv.value.type = 1;
}
void UMessageMiddlewareLibrary::createjsonfloatkv(const FString& k, const float& v, Fjsonobjkv& kv)
{
	kv.key = k;
	kv.value.f = v;
	kv.value.type = 2;

}
void UMessageMiddlewareLibrary::createjsonboolkv(const FString& k, const bool& v, Fjsonobjkv& kv)
{
	kv.key = k;
	kv.value.b= v;
	kv.value.type = 3;
}
void UMessageMiddlewareLibrary::getstringfromjsonstring(const FString& jsonstring,const FString& key, FString& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	ImportGroups->TryGetStringField(key, value);
}
void UMessageMiddlewareLibrary::getfloatfromjsonstring(const FString& jsonstring, const FString& key, float& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	double td;
	ImportGroups->TryGetNumberField(key, td);
	value = td;
}
void UMessageMiddlewareLibrary::getboolfromjsonstring(const FString& jsonstring, const FString& key, bool& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	ImportGroups->TryGetBoolField(key, value);
}
void UMessageMiddlewareLibrary::recorddatatoblackboard(const FString& key, const FString& jsonstring)
{
	blackboard.FindOrAdd(key) = jsonstring;
}
FString UMessageMiddlewareLibrary::getdatafromblackboard(const FString& key)
{
	return blackboard.FindOrAdd(key);
}
bool UMessageMiddlewareLibrary::cooler(float time, FString id)
{
	static TMap<FString, bool> coolers;
	if (coolers.FindOrAdd(id))
	{
		return true;
	}
	else
	{
		Async(EAsyncExecution::ThreadPool, [=]() {
			FPlatformProcess::Sleep(time);
			AsyncTask(ENamedThreads::GameThread,
				[=]()
				{
					(*coolers.Find(id)) = false;
				}
			);
			}, nullptr);
		(*coolers.Find(id)) = true;
		return false;
	}

}