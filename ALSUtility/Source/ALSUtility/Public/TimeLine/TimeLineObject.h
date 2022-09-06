// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeLineObject.generated.h"

/**
 * 
 */

class UCurveFloat;
class UCurveVector;
UCLASS(BlueprintType)
class ALSUTILITY_API UTimeLineObject : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
private:
	bool IsTickableWhenPaused() const override;


	bool IsTickableInEditor() const override;


	void Tick(float DeltaTime) override;


	ETickableTickType GetTickableTickType() const override;


	TStatId GetStatId() const override;


	bool IsTickable() const override;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTimeLineDelegate, float, F1, FVector, F3);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FTimeLineDelegateV1, float F1, FVector F3);
	UPROPERTY(BlueprintAssignable)
		FTimeLineDelegate OnChangeValueDelegate;
	FTimeLineDelegateV1 OnChangeValueDelegateV1;
	UPROPERTY(BlueprintAssignable)
		FTimeLineDelegate OnFinishedDelegate;
	FTimeLineDelegateV1 OnFinishedDelegateV1;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TimeLineObject", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "TimeLine")
	static UTimeLineObject* TimeLineObject(UCurveFloat* CurveFloat, UCurveVector* CurveVector=nullptr,float TimeStart=0);
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
	void Play();
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
		void Stop();
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
		void PlayFromStart();
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
		void SetNewTime(float Time);
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
		void Reverse();
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
		void ReverseFromEnd();
	UFUNCTION(BlueprintCallable, Category = "TimeLineObject")
	FORCEINLINE	void SetTimeScale(float Scale){ mTimeScale = Scale;}
private:
    float mTimeScale=1;
    bool mReverse=false;
	bool mIsActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (ExposeOnSpawn = true, AllowPrivateAccess = "true"))
	float mTimeLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (ExposeOnSpawn = true, AllowPrivateAccess = "true"))
	UCurveFloat* mCurveFloat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (ExposeOnSpawn = true, AllowPrivateAccess = "true"))
	UCurveVector* mCurveVector;
private:
    float mTimeStart =0;
};
