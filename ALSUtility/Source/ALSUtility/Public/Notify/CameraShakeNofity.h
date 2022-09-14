

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CameraShakeNofity.generated.h"

/**
 * 
 */
UCLASS()
class ALSUTILITY_API UCameraShakeNofity : public UAnimNotify
{
	GENERATED_BODY()
public:
	UCameraShakeNofity();

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/* 相机震动数据源 */
	UPROPERTY(EditAnywhere, Category = CameraShakeClass)
		TSoftClassPtr<UCameraShakeBase> CameraShakePath;

	/* 相机震动数据硬引用 */
	UPROPERTY()
		TSubclassOf<UCameraShakeBase> CameraShakeClass;
};
