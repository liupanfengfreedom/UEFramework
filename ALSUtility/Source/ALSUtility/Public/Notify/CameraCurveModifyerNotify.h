

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CameraCurveModifyerNotify.generated.h"

/**
 * 
 */
 class UCurveCameraModifier;
UCLASS()
class ALSUTILITY_API UCameraCurveModifyerNotify : public UAnimNotify
{
	GENERATED_BODY()
public:
	UCameraCurveModifyerNotify();

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/* 相机震动数据源 */
	UPROPERTY(EditAnywhere, Category = CameraModifierClass)
		TSoftClassPtr<UCurveCameraModifier> CameraModifierPath;

	/* 相机震动数据硬引用 */
	UPROPERTY()
		TSubclassOf<UCurveCameraModifier> CameraModifierClass;
private:
   UPROPERTY()
   TArray<UCurveCameraModifier*> CCMArray;
};
