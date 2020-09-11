// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MessageMiddlewareLibrary.generated.h"
USTRUCT(BlueprintType)
struct Fjsonobjv {
    GENERATED_BODY()
public:
      UPROPERTY()
        FString str;
    UPROPERTY()
        float f;
    UPROPERTY()
        bool b;
    UPROPERTY()
        int type;
    Fjsonobjv()
    {

    }
};
USTRUCT(BlueprintType)
struct Fjsonobjkv {
    GENERATED_BODY()
public:
    UPROPERTY()
        FString key;
    UPROPERTY()
        Fjsonobjv value;

};
/**
 * 
 */
UCLASS()
class MESSAGEMIDDLEWARE_API UMessageMiddlewareLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
        static TMap<FString, FString> blackboard;
public:
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static void sendmessage(const FString& id , const FString& payload);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")//this function may be not nessary
        static void sendmessagefaster(const FString& id, FString& payload);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FOnsetlistenerevent, const FString&, message);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static void addmessagelistener(UObject* instance, const FString& id, FOnsetlistenerevent func);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static void removemessagelistener(UObject* instance);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void kvtojsonstring(const TArray<Fjsonobjkv>& array,FString& outstring );
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void createjsonstringkv(const FString &k,const FString & v, Fjsonobjkv& kv);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void createjsonfloatkv(const FString& k, const float& v, Fjsonobjkv& kv);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void createjsonboolkv(const FString& k, const bool& v, Fjsonobjkv& kv);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void getstringfromjsonstring(const FString& jsonstring, const FString& key, FString& value);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void getfloatfromjsonstring(const FString& jsonstring, const FString& key, float& value);
    UFUNCTION(BlueprintPure, Category = "MessageMiddlewareLibrary")
        static void getboolfromjsonstring(const FString& jsonstring, const FString& key, bool& value);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static void recorddatatoblackboard(const FString& key, const FString & jsonstring);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static FString getdatafromblackboard(const FString& key);
    UFUNCTION(BlueprintCallable, Category = "MessageMiddlewareLibrary")
        static bool cooler(float time, FString id);
};
