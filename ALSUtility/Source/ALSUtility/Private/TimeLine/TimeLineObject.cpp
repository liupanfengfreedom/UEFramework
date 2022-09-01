// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeLine/TimeLineObject.h"
#include "Curves/CurveVector.h"
#include "Curves/CurveFloat.h"


bool UTimeLineObject::IsTickableWhenPaused() const
{
	return false;//throw std::logic_error("The method or operation is not implemented.");
}

bool UTimeLineObject::IsTickableInEditor() const
{
	return false;//throw std::logic_error("The method or operation is not implemented.");
}

void UTimeLineObject::Tick(float DeltaTime)
{
	mTimeStart += mReverse? -DeltaTime: DeltaTime;
	if (mCurveFloat && mCurveVector)
	{
		OnChangeValueDelegate.Broadcast(mCurveFloat->GetFloatValue(mTimeStart), mCurveVector->GetVectorValue(mTimeStart));
		OnChangeValueDelegateV1.Broadcast(mCurveFloat->GetFloatValue(mTimeStart), mCurveVector->GetVectorValue(mTimeStart));
	}
	else if (mCurveFloat)
	{
		OnChangeValueDelegate.Broadcast(mCurveFloat->GetFloatValue(mTimeStart), FVector::ZeroVector);
		OnChangeValueDelegateV1.Broadcast(mCurveFloat->GetFloatValue(mTimeStart), FVector::ZeroVector);
	}
	else if (mCurveVector)
	{
		OnChangeValueDelegate.Broadcast(0, mCurveVector->GetVectorValue(mTimeStart));
		OnChangeValueDelegateV1.Broadcast(0, mCurveVector->GetVectorValue(mTimeStart));
	}


	if (mTimeStart >= mTimeLength)
	{
		OnFinishedDelegate.Broadcast(0, FVector::ZeroVector);
		OnFinishedDelegateV1.Broadcast(0, FVector::ZeroVector);
		mIsActive=false;
	}
	else if (mTimeStart <= 0)
	{
		OnFinishedDelegate.Broadcast(1, FVector::ZeroVector);//here 1 mean reverse
		OnFinishedDelegateV1.Broadcast(1, FVector::ZeroVector);//here 1 mean reverse
		mIsActive = false;
	}
}

ETickableTickType UTimeLineObject::GetTickableTickType() const
{
	return ETickableTickType::Conditional;//throw std::logic_error("The method or operation is not implemented.");
}

TStatId UTimeLineObject::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTimeLineObject, STATGROUP_Tickables);//throw std::logic_error("The method or operation is not implemented.");
}

bool UTimeLineObject::IsTickable() const
{
	return mIsActive;
}

UTimeLineObject* UTimeLineObject::TimeLineObject(float TimeLength, float TimeStart, UCurveFloat* CurveFloat, UCurveVector* CurveVector)
{
	UTimeLineObject *TLO = NewObject<UTimeLineObject>();
	TLO->mTimeLength = TimeLength;
	TLO->mTimeStart = TimeStart;
	TLO->mCurveFloat = CurveFloat;
	TLO->mCurveVector = CurveVector;
	return TLO;
}

void UTimeLineObject::Play()
{
	if ((mCurveFloat || mCurveVector) && mTimeLength > 0)
	{
		mIsActive = true;
		mReverse = false;
	}
}

void UTimeLineObject::Stop()
{
	mIsActive = false;
}

void UTimeLineObject::PlayFromStart()
{
	if ((mCurveFloat || mCurveVector) && mTimeLength > 0)
	{
		mIsActive = true;
		mTimeStart = 0;
		mReverse = false;
	}
}

void UTimeLineObject::SetNewTime(float Time)
{
	mTimeStart = Time;
}

void UTimeLineObject::Reverse()
{
	if ((mCurveFloat || mCurveVector) && mTimeLength > 0)
	{
		mReverse = true;
		mIsActive = true;
	}

}

void UTimeLineObject::ReverseFromEnd()
{
	if ((mCurveFloat || mCurveVector) && mTimeLength > 0)
	{
		mReverse = true;
		mTimeStart = mTimeLength;
		mIsActive = true;
	}

}
