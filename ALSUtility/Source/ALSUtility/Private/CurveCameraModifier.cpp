


#include "CurveCameraModifier.h"
#include "Curves/CurveVector.h"
#include "Curves/CurveFloat.h"


UCurveCameraModifier::UCurveCameraModifier(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}
bool UCurveCameraModifier::IsActive()
{
     return mTimeLength > mTimeCounter;
}

void UCurveCameraModifier::AddedToCamera(APlayerCameraManager* Camera)
{
	mTimeCounter=0;
	Super::AddedToCamera(Camera);
}

void UCurveCameraModifier::ModifyCamera(float DeltaTime, FVector ViewLocation, FRotator ViewRotation, float FOV, FVector& NewViewLocation, FRotator& NewViewRotation, float& NewFOV)
{
	mTimeCounter+= DeltaTime;
	mRatio = mTimeCounter / Duration;
	if (FovOffset)
	{
		NewFOV = FOV + FovOffset->GetFloatValue(mRatio);
    }
	if (LocationOffset)
	{
		NewViewLocation = ViewLocation + LocationOffset->GetVectorValue(mRatio);
	}
	if (RotationOffset)
	{
	    FVector RO = RotationOffset->GetVectorValue(mRatio);
		NewViewRotation = ViewRotation.Add(RO.Y,RO.Z,RO.X);
	}
	if (mRatio>=1)
	{
		if (OnFinishedEvent)
		{
			OnFinishedEvent();
	    }
	}
}
