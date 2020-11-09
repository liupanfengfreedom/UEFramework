// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
DECLARE_MULTICAST_DELEGATE_OneParam(FOnmessageonepara,const void * const)
DECLARE_DELEGATE_RetVal_OneParam(FString, FOngetmessagepara, const void* const)
#define SENDMESSAGE(KEY,PAYLOAD) MessageManager::Getsingleston()->SendMessage(KEY,PAYLOAD);
#define ADDMESSAGELISTEN(OBJ,KEY,DELEGATE) MessageManager::Getsingleston()->recordekeyhandle(\
																			OBJ,\
																			KEY,\
																			MessageManager::Getsingleston()->Bind(KEY).AddLambda(DELEGATE)\
																			);
#define REMOVEMESSAGELISTEN(OBJ) MessageManager::Getsingleston()->UnBind(OBJ);
#define GETMESSAGEMAPSIZE MessageManager::Getsingleston()->Getmapsize()
//////////////////////////////////////////////////////////////////////////////////////
#define GETMESSAGE(KEY) MessageManager::Getsingleston()->GetMessage(KEY);
#define GETMESSAGEWITHPARA(KEY,PARA) MessageManager::Getsingleston()->GetMessage(KEY,PARA);
#define PROVIDEMESSAGE(KEY,DELEGATE) MessageManager::Getsingleston()->ProvideMessage(KEY).BindLambda(DELEGATE);
#define REMOVEPROVIDER(KEY) MessageManager::Getsingleston()->removeprovider(KEY);
/**
 * 
 */
struct Delegatehandlestore
{
	Delegatehandlestore(const FString& pdkey,const FDelegateHandle& phandle)
	{
		idkey = pdkey;
		handle = phandle;
	}
	FString idkey;
	FDelegateHandle handle;
};
class MESSAGEMIDDLEWARE_API MessageManager
{
	TMap<FString, FOnmessageonepara> Messagemap;
	TMap<void*, TArray<Delegatehandlestore>> delegatehandlemap;

public:
	MessageManager();
	~MessageManager();
public:
	int Getmapsize() { return Messagemap.Num(); }//be aware of the thread-safe
	void SendMessage(const FString &id, void*palyload);
	FOnmessageonepara& Bind(const FString& id);
	void UnBind(void*);
	void recordekeyhandle(void* instance, const FString& id, FDelegateHandle handle);
	static TSharedPtr<MessageManager, ESPMode::ThreadSafe> Getsingleston();
	static void Destroy() {}
////////////////////////////////////////////////////////////////////////
private:
	FOngetmessagepara testdelegate;
	TMap<FString, FOngetmessagepara> GetMessagemap;
public:
	FString GetMessage(FString key, const void* const para=nullptr);
	FOngetmessagepara& ProvideMessage(FString key);
	void removeprovider(const FString& key);
};
