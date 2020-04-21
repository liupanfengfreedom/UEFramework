// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "MessageManager.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	MessageManager::Getsingleston()->Bind("key1").AddLambda([this](const void * const pd) {
		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, *(FString*)pd);
		});
}
void AMyActor::bpf1()
{

	FString mes = "somemessage";
	MessageManager::Getsingleston()->SendMessage("key1", &mes);
	struct MyStruct
	{
		FString ms;
		FVector vec;
		FHitResult hrt;
	} stt;
	stt.ms = "MyStructaaaaaaaa";
	stt.vec =FVector(3,45,5);
	stt.hrt.Actor = this;
	stt.hrt.Distance = 120;
	GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Red, FString::FromInt(*(int*)(this)).Append(" MyActor"));
	MessageManager::Getsingleston()->SendMessage("key2", &stt);
	
	MessageManager::Getsingleston()->SendMessage("key3", &stt);
	MessageManager::Getsingleston()->SendMessage("key4", &stt);
	MessageManager::Getsingleston()->SendMessage("key5", &stt);
	MessageManager::Getsingleston()->SendMessage("key6", &stt);
	MessageManager::Getsingleston()->SendMessage("key7", &stt);
	MessageManager::Getsingleston()->SendMessage("key8", &stt);
	MessageManager::Getsingleston()->SendMessage("key9", &stt);
	MessageManager::Getsingleston()->SendMessage("key10", &stt);
	MessageManager::Getsingleston()->SendMessage("key11", &stt);
	MessageManager::Getsingleston()->SendMessage("key12", &stt);
	MessageManager::Getsingleston()->SendMessage("key13", &stt);
	MessageManager::Getsingleston()->SendMessage("key14", &stt);
	MessageManager::Getsingleston()->SendMessage("key15", &stt);
	MessageManager::Getsingleston()->SendMessage("key16", &stt);
	MessageManager::Getsingleston()->SendMessage("key17", &stt);
	MessageManager::Getsingleston()->SendMessage("key18", &stt);
	MessageManager::Getsingleston()->SendMessage("key19", &stt);
	MessageManager::Getsingleston()->SendMessage("key21", &stt);
	MessageManager::Getsingleston()->SendMessage("key22", &stt);
	MessageManager::Getsingleston()->SendMessage("key23", &stt);
	MessageManager::Getsingleston()->SendMessage("key24", &stt);
	MessageManager::Getsingleston()->SendMessage("key25", &stt);
	MessageManager::Getsingleston()->SendMessage("key26", &stt);
	MessageManager::Getsingleston()->SendMessage("key27", &stt);
	MessageManager::Getsingleston()->SendMessage("key28", &stt);
	MessageManager::Getsingleston()->SendMessage("key29", &stt);
	MessageManager::Getsingleston()->SendMessage("key30", &stt);
	MessageManager::Getsingleston()->SendMessage("key31", &stt);
	MessageManager::Getsingleston()->SendMessage("key270", &stt);
	MessageManager::Getsingleston()->SendMessage("key260", &stt);
	MessageManager::Getsingleston()->SendMessage("key230",&stt);

	int size = MessageManager::Getsingleston()->Getmapsize();
	GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, FString::FromInt(size).Append(" MyActor"));

}
// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


