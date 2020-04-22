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
void AMyActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	REMOVEMESSAGELISTEN(this);
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//MessageManager::Getsingleston()->recordekeyhandle(this, "key1",
	//	MessageManager::Getsingleston()->Bind("key1").AddLambda([this](const void* const pd) {
	//		FString temp = *(FString*)pd;
	//		temp.Append(" MyActor");
	//		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, temp);
	//		})
	//	);
	FString key = "key1";
	ADDMESSAGELISTEN(this, key,
		[this](const void* const pd) {
			FString temp = *(FString*)pd;
			temp.Append(" MyActor");
			GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, temp);
			}
	)
}
void AMyActor::bpf1()
{

	FString mes = "somemessage";
	SENDMESSAGE("key1", &mes);
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
	FString key = "key";
	for (int i = 0; i < 200; i++)
	{
		key = "key";
		key.Append(FString::FromInt(i));
		SENDMESSAGE(key, &stt);

	}


	//int size = MessageManager::Getsingleston()->Getmapsize();
	GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, FString::FromInt(GETMESSAGEMAPSIZE).Append(" MyActor"));

}
// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


