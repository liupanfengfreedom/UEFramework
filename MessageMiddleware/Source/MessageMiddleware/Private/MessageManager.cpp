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
FOnmessageonepara& MessageManager::Bind(const FString &id)
{
	 return Messagemap.FindOrAdd(id);
}
void MessageManager::UnBind(void* instance)
{
	bool bc= delegatehandlemap.Contains(instance);
	if (bc)
	{
		TArray<Delegatehandlestore> temp = *delegatehandlemap.Find(instance);
		for (auto var : temp)
		{
			MessageManager::Getsingleston()->Bind(var.idkey).Remove(var.handle);
		}
	}
}
void MessageManager::recordekeyhandle(void* instance, const FString& id, FDelegateHandle handle)
{
	delegatehandlemap.FindOrAdd(instance).Add(Delegatehandlestore(id, handle));
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