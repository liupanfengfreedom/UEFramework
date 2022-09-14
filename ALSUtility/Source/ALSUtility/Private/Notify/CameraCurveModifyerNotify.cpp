


#include "Notify/CameraCurveModifyerNotify.h"
#include "CurveCameraModifier.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/AssetManager.h"

UCameraCurveModifyerNotify::UCameraCurveModifyerNotify()
{
#if WITH_EDITORONLY_DATA
	NotifyColor = FColor::Purple;
	bShouldFireInEditor = true;
#endif // WITH_EDITORONLY_DATA
}

void UCameraCurveModifyerNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp && (MeshComp->GetOwnerRole() == ROLE_AutonomousProxy || MeshComp->GetWorld()->GetNetMode() == ENetMode::NM_Standalone))
	{
		if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(MeshComp->GetOwner(), 0))
		{
			 bool Case2 = CameraModifierPath.IsValid();
			 bool Case1 = !IsValid(CameraModifierClass);
			if (Case1&&Case2)
			{
				//UE_LOG(LogTemp, Warning, TEXT("LoadClass  %s  :  %s"), *FString::FromInt(MeshComp->GetOwnerRole()), *Animation->GetFName().ToString());
				CameraModifierClass = UAssetManager::GetStreamableManager().LoadSynchronous<UCurveCameraModifier>(CameraModifierPath, false, nullptr);
			}

			if (UCurveCameraModifier* CameraCurveModifyObject = Cast<UCurveCameraModifier>(PlayerController->PlayerCameraManager->AddNewCameraModifier(CameraModifierClass)))
			{
				CCMArray.Add(CameraCurveModifyObject);
				CameraCurveModifyObject->OnFinishedEvent = [=]() {
					PlayerController->PlayerCameraManager->RemoveCameraModifier(CameraCurveModifyObject);
					CCMArray.Remove(CameraCurveModifyObject);
				};
			}
			//UE_LOG(LogTemp, Warning, TEXT("PlayCameraShake  %s  :  %s"), *FString::FromInt(MeshComp->GetOwnerRole()), *Animation->GetFName().ToString());
		}

	}
}
