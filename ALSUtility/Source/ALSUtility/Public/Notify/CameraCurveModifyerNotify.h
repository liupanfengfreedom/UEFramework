

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

	/* ���������Դ */
	UPROPERTY(EditAnywhere, Category = CameraModifierClass)
		TSoftClassPtr<UCurveCameraModifier> CameraModifierPath;

	/* ���������Ӳ���� */
	UPROPERTY()
		TSubclassOf<UCurveCameraModifier> CameraModifierClass;
private:
   UPROPERTY()
   TArray<UCurveCameraModifier*> CCMArray;
};
