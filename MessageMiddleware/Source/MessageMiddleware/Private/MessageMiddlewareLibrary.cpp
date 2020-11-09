// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageMiddlewareLibrary.h"
#include "MessageManager.h"
#include "JsonUtilities.h"
#include "Json.h"
TMap<FString, FString> UMessageMiddlewareLibrary::blackboard;
//TArray<FOntickevent>  UMessageMiddlewareLibrary::Tickeventarray;
TArray<Tickeventtype>  UMessageMiddlewareLibrary::Tickeventarray;
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
FString UMessageMiddlewareLibrary::getmessage(const FString& id, const FString& payload)
{
	return GETMESSAGEWITHPARA(id, &payload);
}
void UMessageMiddlewareLibrary::ProvideMessage(const FString& id, FOnProvideMessageevent func)
{
	PROVIDEMESSAGE(id, [=](const void* const para)->FString {
		bool b =func.IsBound();
		if (b)
		{
			return func.Execute(*(FString*)para);
		}
		else
		{
			return "";
		}
	})
}

void UMessageMiddlewareLibrary::addtickevent(FOnsingletickevent func, const FString& param)
{
	Tickeventarray.Add(Tickeventtype([func](FString para) {func.ExecuteIfBound(para); },param));
}
void UMessageMiddlewareLibrary::addtickevent(TFunction<void(const FString&)> func, const FString& param)
{
	Tickeventarray.Add(Tickeventtype(func,param));
}
void UMessageMiddlewareLibrary::excutetickevent()
{
	static int counter = 0;
	if (counter++ % 1 == 0)
	{
		int len = Tickeventarray.Num();
		if (len > 0)
		{
			Tickeventarray[len - 1].func(Tickeventarray[len - 1].parameter);
			Tickeventarray.RemoveAt(len - 1);
		}
	}
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
FString UMessageMiddlewareLibrary::createjsonfromtransform(const FTransform& ts)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedPtr<FJsonObject> fvector;
	fvector = MakeShareable(new FJsonObject);
	fvector->SetNumberField("X", ts.GetLocation().X);
	fvector->SetNumberField("Y", ts.GetLocation().Y);
	fvector->SetNumberField("Z", ts.GetLocation().Z);
	ImportGroups->SetObjectField("location", fvector);
	fvector = MakeShareable(new FJsonObject);
	fvector->SetNumberField("X", ts.GetScale3D().X);
	fvector->SetNumberField("Y", ts.GetScale3D().Y);
	fvector->SetNumberField("Z", ts.GetScale3D().Z);
	ImportGroups->SetObjectField("scale", fvector);
	FRotator r = ts.GetRotation().Rotator();
	fvector = MakeShareable(new FJsonObject);
	fvector->SetNumberField("Roll", r.Roll);
	fvector->SetNumberField("Pitch", r.Pitch);
	fvector->SetNumberField("Yaw", r.Yaw);
	ImportGroups->SetObjectField("rotation", fvector);
	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(ImportGroups.ToSharedRef(), Writer);
	return OutputString;
}
FString UMessageMiddlewareLibrary::createjsonfromvector(const FVector& vec)
{
	TSharedPtr<FJsonObject> fvector;
	fvector = MakeShareable(new FJsonObject);
	fvector->SetNumberField("X", vec.X);
	fvector->SetNumberField("Y", vec.Y);
	fvector->SetNumberField("Z", vec.Z);
	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(fvector.ToSharedRef(), Writer);
	return OutputString;
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
void UMessageMiddlewareLibrary::getstringarrayfromjsonstring(const FString& jsonstring, const FString& key, TArray<FString>& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	TArray<TSharedPtr<FJsonValue>> ja = ImportGroups->GetArrayField(key);
	for (auto var : ja)
	{
		value.Add(var->AsString());
	}
}
void UMessageMiddlewareLibrary::getfloatarrayfromjsonstring(const FString& jsonstring, const FString& key, TArray<float>& value)
{
	TSharedPtr<FJsonObject> ImportGroups = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(jsonstring);
	FJsonSerializer::Deserialize(Reader, ImportGroups);
	TArray<TSharedPtr<FJsonValue>> ja = ImportGroups->GetArrayField(key);
	for (auto var : ja)
	{
		value.Add(var->AsNumber());
	}
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