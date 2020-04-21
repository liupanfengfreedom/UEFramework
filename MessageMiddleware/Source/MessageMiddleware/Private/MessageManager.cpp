// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageManager.h"
MessageManager::MessageManager()
{
}

MessageManager::~MessageManager()
{
	TArray<FString>keys;
	Messagemap.GetKeys(keys);
	for (auto var : keys)
	{
		Messagemap.Remove(var);
	}
}
void MessageManager::SendMessage(const FString &id, void* palyload)
{
	Messagemap.FindOrAdd(id).Broadcast(palyload);
}
FOnmessageonepara& MessageManager::ListenMessage(const FString &id)
{
	 return Messagemap.FindOrAdd(id);
}
TSharedPtr<MessageManager, ESPMode::ThreadSafe> MessageManager::Getsingleston()
{
	static TSharedPtr<MessageManager, ESPMode::ThreadSafe> _msingleston = nullptr;
	if (_msingleston == nullptr)
	{
		_msingleston = MakeShareable(new MessageManager());
	}
	return _msingleston;
	return nullptr;
}