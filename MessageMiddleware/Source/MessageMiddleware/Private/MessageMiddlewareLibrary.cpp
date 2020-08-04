// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageMiddlewareLibrary.h"
#include "MessageManager.h"
#include "JsonUtilities.h"
#include "Json.h"
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