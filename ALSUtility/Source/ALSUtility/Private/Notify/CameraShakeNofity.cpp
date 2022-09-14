


#include "Notify/CameraShakeNofity.h"
#include "Kismet/GameplayStatics.h"

UCameraShakeNofity::UCameraShakeNofity()
{
#if WITH_EDITORONLY_DATA
	NotifyColor = FColor::Purple;
	bShouldFireInEditor = true;
#endif // WITH_EDITORONLY_DATA

}

void UCameraShakeNofity::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp && (MeshComp->GetOwnerRole() == ROLE_AutonomousProxy || MeshComp->GetWorld()->GetNetMode() == ENetMode::NM_Standalone))
	{
		if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(MeshComp->GetOwner(), 0))
		{
			if (!IsValid(CameraShakeClass) && CameraShakePath.IsValid())
			{
				CameraShakeClass = CameraShakePath.LoadSynchronous();
				//UE_LOG(LogTemp, Warning, TEXT("LoadClass  %s  :  %s"), *FString::FromInt(MeshComp->GetOwnerRole()), *Animation->GetFName().ToString());
			}
			PlayerController->PlayerCameraManager->StartCameraShake(CameraShakeClass);
			UE_LOG(LogTemp, Warning, TEXT("PlayCameraShake  %s  :  %s"), *FString::FromInt(MeshComp->GetOwnerRole()), *Animation->GetFName().ToString());
		}

	}
}