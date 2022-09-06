// Fill out your copyright notice in the Description page of Project Settings.


#include "Physics/MousePhysicsHandleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
void UMousePhysicsHandleComponent::GrabPhysicsSimulatedObject()
{
	mNeedGrab=true;

}

void UMousePhysicsHandleComponent::ReleasePhysicsSimulatedObject()
{
	mNeedGrab = false;
	mGrabed = false;
	ReleaseComponent();
	if (mHR.Component.Get())
	{
		if (!mHR.Component->IsAnyRigidBodyAwake())
		{
			mHR.Component->WakeAllRigidBodies();
		}
	}
}

void UMousePhysicsHandleComponent::BeginPlay()
{
    Super::BeginPlay();
	mPlayerController = UGameplayStatics::GetPlayerController(GetOwner(),0);
	SetLinearStiffness(10000);
	SetLinearDamping(1000);
}

void UMousePhysicsHandleComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
   Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (mGrabed)
	{
		FVector2D SZ = UWidgetLayoutLibrary::GetMousePositionOnViewport(this);
		FVector2D Locaton = SZ * UWidgetLayoutLibrary::GetViewportScale(this);
		FVector WorldLocation, WorldDir;
		mPlayerController->DeprojectScreenPositionToWorld(Locaton.X, Locaton.Y, WorldLocation, WorldDir);
		FVector EndLocation = WorldDir * mDis + mPlayerController->PlayerCameraManager->GetCameraLocation();
		SetTargetLocation(EndLocation);
		UKismetSystemLibrary::DrawDebugSphere(this, EndLocation, 20, 12, FLinearColor::Yellow, 0.05, 1);
		if (!mHR.Component->IsAnyRigidBodyAwake())
		{
			mHR.Component->WakeAllRigidBodies();
		}
	}
	else
	{
		mPlayerController->GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery1, true, mHR);

		if (mNeedGrab && mHR.bBlockingHit)
		{
			if (mHR.Component->IsSimulatingPhysics())
			{
				if (!mHR.Component->IsAnyRigidBodyAwake())
				{
					mHR.Component->WakeAllRigidBodies();
				}
				UKismetSystemLibrary::DrawDebugSphere(this, mHR.ImpactPoint, 20, 12, FLinearColor::Blue, 0.05, 1);
				GrabComponentAtLocationWithRotation(mHR.Component.Get(), "None", mHR.ImpactPoint, UKismetMathLibrary::Conv_VectorToRotator(mHR.Normal));

				mGrabed = true;
				mDis = mHR.Distance;
			}
			else
			{
				UKismetSystemLibrary::DrawDebugSphere(this, mHR.ImpactPoint, 20, 12, FLinearColor::White, 0.05, 1);

			}
		}

	}
}
