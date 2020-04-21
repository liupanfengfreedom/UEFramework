// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
DECLARE_MULTICAST_DELEGATE_OneParam(FOnmessageonepara,const void * const)
//DECLARE_MULTICAST_DELEGATE_TwoParams
/**
 * 
 */
class MESSAGEMIDDLEWARE_API MessageManager
{
	TMap<FString, FOnmessageonepara> Messagemap;

public:
	MessageManager();
	~MessageManager();
public:
	int Getmapsize() { return Messagemap.Num(); }//be aware of the thread-safe
	void SendMessage(const FString &id, void*palyload);
	FOnmessageonepara& ListenMessage(const FString &id);
	static TSharedPtr<MessageManager, ESPMode::ThreadSafe> Getsingleston();
	static void Destroy() {}
};
