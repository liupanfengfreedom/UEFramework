// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TActor.generated.h"

UCLASS()
class APP_API ATActor : public AActor
{
	GENERATED_BODY()
		FString m1;
	//FDelegateHandle handle;
	//FDelegateHandle handle1;
public:	
	// Sets default values for this actor's properties
	ATActor();
	~ATActor();
	int i1;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay
	(
		const EEndPlayReason::Type EndPlayReason
	)override;
	void ft();
	//void ftsom(const void* const pd);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
