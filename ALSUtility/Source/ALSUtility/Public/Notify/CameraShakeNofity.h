

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

	/* ���������Դ */
	UPROPERTY(EditAnywhere, Category = CameraShakeClass)
		TSoftClassPtr<UCameraShakeBase> CameraShakePath;

	/* ���������Ӳ���� */
	UPROPERTY()
		TSubclassOf<UCameraShakeBase> CameraShakeClass;
};
