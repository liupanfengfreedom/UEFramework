// Fill out your copyright notice in the Description page of Project Settings.


#include "TActor.h"
#include "MessageManager.h"
#include "Engine.h"
// Sets default values
ATActor::ATActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
ATActor::~ATActor()
{

	//MessageManager::Getsingleston()->ListenMessage("key1").Remove(handle1);
	//MessageManager::Getsingleston()->ListenMessage("key2").Remove(handle);
}
void ATActor::ft()
{
	int i = i1++;
	GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, FString::FromInt(i));

}
void ATActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	REMOVEMESSAGELISTEN(this);
}

// Called when the game starts or when spawned
void ATActor::BeginPlay()
{
	Super::BeginPlay();
	m1 = "mmmm";
	i1 = 990; 
	//FDelegateHandle handle1 = MessageManager::Getsingleston()->Bind("key1").AddLambda([this](const void* const pd) {
	//		ft();
	//		FString ms = (*(FString*)pd);
	//		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, ms.Append(m1));
	//	});
	//MessageManager::Getsingleston()->recordekeyhandle(this,"key1", handle1);
	ADDMESSAGELISTEN(this, "key1",
		[this](const void* const pd) {
			ft();
			FString ms = (*(FString*)pd);
			GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, ms.Append(m1));
		}
	)

	//FDelegateHandle handle = MessageManager::Getsingleston()->Bind("key2").AddLambda([this](const void* const pd) {
	//		struct MyStruct
	//		{
	//			FString ms;
	//			FVector vec;
	//			FHitResult hrt;
	//		} stt;
	//		stt = (*(MyStruct*)pd);
	//		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, stt.ms.Append(stt.vec.ToString()));
	//		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, FString::FromInt(stt.hrt.Distance));

	//		GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Red, FString::FromInt(*(int*)(stt.hrt.Actor.Get())).Append(" TActor"));
	//	});
	//MessageManager::Getsingleston()->recordekeyhandle(this, "key2", handle);
	ADDMESSAGELISTEN(this, "key2",
		[this](const void* const pd) {
			struct MyStruct
			{
				FString ms;
				FVector vec;
				FHitResult hrt;
			} stt;
			stt = (*(MyStruct*)pd);
			GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, stt.ms.Append(stt.vec.ToString()));
			GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Yellow, FString::FromInt(stt.hrt.Distance));

			GEngine->AddOnScreenDebugMessage(-1, .7f, FColor::Red, FString::FromInt(*(int*)(stt.hrt.Actor.Get())).Append(" TActor"));
		}
	)


}
//void ATActor::ftsom(const void* const pd)
//{
//
//}
// Called every frame
void ATActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

