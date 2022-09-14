

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "CurveCameraModifier.generated.h"

/**
 * 
 */
UCLASS()
class ALSUTILITY_API UCurveCameraModifier : public UCameraModifier
{
	GENERATED_UCLASS_BODY()

public:
    bool IsActive();
	TFunction<void(void)>OnFinishedEvent;
	virtual void AddedToCamera(APlayerCameraManager* Camera) override;
	virtual void ModifyCamera(float DeltaTime, FVector ViewLocation, FRotator ViewRotation, float FOV, FVector& NewViewLocation, FRotator& NewViewRotation, float& NewFOV) override;
	float mTimeCounter;
	float mTimeLength;
	float mRatio;
	UPROPERTY(EditAnywhere, Category = "Curve", meta = (AllowPrivateAccess = "true"))
		float Duration=1;
	UPROPERTY(EditAnywhere, Category = "Curve", meta = (AllowPrivateAccess = "true"))
		class UCurveFloat* FovOffset;
	UPROPERTY(EditAnywhere, Category = "Curve", meta = (AllowPrivateAccess = "true"))
		class UCurveVector* LocationOffset;
	UPROPERTY(EditAnywhere, Category = "Curve", meta = (AllowPrivateAccess = "true"))
		UCurveVector* RotationOffset;
};
