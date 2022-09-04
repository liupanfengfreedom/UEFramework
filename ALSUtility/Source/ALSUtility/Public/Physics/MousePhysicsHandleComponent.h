// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "MousePhysicsHandleComponent.generated.h"
class APlayerController;
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class ALSUTILITY_API UMousePhysicsHandleComponent : public UPhysicsHandleComponent
{
	GENERATED_BODY()
public:
UFUNCTION(BlueprintCallable)
    void GrabPhysicsSimulatedObject();
UFUNCTION(BlueprintCallable)
    void ReleasePhysicsSimulatedObject();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	APlayerController *mPlayerController;
	bool mNeedGrab;
	bool mGrabed;
	float mDis;
};
