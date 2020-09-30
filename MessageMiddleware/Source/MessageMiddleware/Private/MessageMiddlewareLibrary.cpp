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
	TSharedPtr<FJsonObject> fvector;
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
		case 4:
			fvector = MakeShareable(new FJsonObject);
			fvector->SetNumberField("X", array[i].value.v.X);
			fvector->SetNumberField("Y", array[i].value.v.Y);
			fvector->SetNumberField("Z", array[i].value.v.Z);
			ImportGroups->SetObjectField(array[i].key, fvector);
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
void UMessageMiddlewareLibrary::createjsonvectorkv(const FString& k, const FVector& v, Fjsonobjkv& kv)
{
	kv.key = k;
	kv.value.v = v;
	kv.value.type = 4;
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
void UMessageMiddlewareLibrary::getvectorfromjsonstring(const FString& jsonstring, const FString& key, FVector& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	const TSharedPtr<FJsonObject>* fvector ;
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	ImportGroups->TryGetObjectField(key, fvector);
	double X,Y,Z;
	(*fvector)->TryGetNumberField("X", X);
	(*fvector)->TryGetNumberField("Y", Y);
	(*fvector)->TryGetNumberField("Z", Z);
	value.X = X;
	value.Y = Y;
	value.Z = Z;
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