// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
class ALSUTILITY_API FStateMachine;
/**
 * 
 */

class ALSUTILITY_API FState
{
	//static_assert(std::is_base_of<UObject, T2>::value, "T2 must be a base of or the same as UObject, Supporting UE4 WeakPtr.");

public:
	explicit FState() {}

	explicit FState(uint8 State, class FStateMachine* StateMachine, TFunction<void(void)>OnEnter, TFunction<void(void)>OnExit, TFunction<void(float, FState*)>OnLoop)
		:mState(State), mStateMachine(StateMachine), mOnEnter(OnEnter), mOnExit(OnExit), mOnLoop(OnLoop)
	{

	}

public:
	//
	virtual ~FState() {
		UE_LOG(LogTemp, Warning, TEXT(" FState destroy"));

	}

	//
	virtual void Enter() {
		mTickTime = 0;
		if (mOnEnter)
		{
			mOnEnter();
		}
	}

	//
	virtual void Loop(float DeltaTime, FState* CurrentObject) {
		mTickTime += DeltaTime;
		if (mOnLoop)
		{
			mOnLoop(DeltaTime, this);
		}
	}

	//
	virtual void Exit() {
		if (mOnExit)
		{
			mOnExit();
		}
	}

	//
	virtual bool CanChangeState(uint8 NextState) { return true; }

	//
	FORCEINLINE uint8 GetState() { return mState; }
	FORCEINLINE FStateMachine* GetStateMachine() { return mStateMachine; }
	FORCEINLINE float GetCurrentTimeCount() { return mTickTime; }
private:
	float mTickTime = 0.0f;

	//
	uint8 mState;
	FStateMachine* mStateMachine;
	TFunction<void(void)>mOnEnter = 0;
	TFunction<void(float, FState*)>mOnLoop = 0;
	TFunction<void(void)>mOnExit = 0;

};
class ALSUTILITY_API FStateMachine
{
public:
	FStateMachine() {
		UE_LOG(LogTemp, Warning, TEXT("Create a new FStateMachine"));
	}
	virtual~FStateMachine() {
		ClearStates();
	}
	//static_assert(std::is_base_of<FState, FState>::value, "FState must be a base of or the same as FState.");

public:

	//
	FState* TryGetState(uint8 NewState) {
		FState* RefState = nullptr;
		if (mStateContainer.Num() > NewState)
		{
			RefState = mStateContainer[NewState];
			if (!RefState)
			{
				UE_LOG(LogTemp, Error, TEXT("FStateMachine:TryGetState-%d"), NewState);
			}
		}

		return RefState;
	}

	//
	void AddState(FState* StateObject) {
		if (!StateObject)
		{
			return;
		}

		//
		uint8 NewState = StateObject->GetState();
		if (mStateContainer.Num() <= NewState)
		{
			mStateContainer.SetNum(NewState+1);
			mStateContainer[NewState] = StateObject;
		}
		else
		{
			FState* RefState = mStateContainer[NewState];
			if (RefState)
			{
				if (StateObject != RefState)
				{
					UE_LOG(LogTemp, Warning, TEXT("FStateMachine-Add/ReplaceState?-%d"), NewState);
					delete RefState;
					mStateContainer[NewState] = StateObject;
				}
			}
			else
			{
				mStateContainer[NewState] = StateObject;
			}
		}
	}

	//Only Owner Actor Can do.
	void ReplaceState(FState* StateObject)
	{
		AddState(StateObject);
	}

	//
	FORCEINLINE uint8 GetCurState()
	{
		return mCurrStateName;
	}
	//
	FORCEINLINE uint8 GetLastState()
	{
		return mLastStateName;
	}
	//
	virtual bool CanChangeState(uint8 NewState) { return true; };

	//
	virtual bool ChangeStateTo(uint8 NewState)
	{
		if (!CanChangeState(NewState))
		{
			return false;
		}

		if (mCurrState)
		{
			mLastStateName = mCurrState->GetState();
			mLastState = mCurrState;
			mLastState->Exit();
		}

		FState* NewStateObject = TryGetState(NewState);
		if (NewStateObject)
		{
			mCurrStateName = NewState;
			mCurrState = NewStateObject;
			mCurrState->Enter();
			if (OnStateChangeEvent)
			{
				OnStateChangeEvent(NewState, mLastStateName);
			}
			return true;
		}

		//
		return false;
	}

	//
	virtual void ClearStates() {
		for (auto var : mStateContainer)
		{
			if (var)
			{
				delete var;
			}
		}
		mStateContainer.Empty();

		if (mLastState)
		{
			mLastState = 0;
		}

		if (mCurrState)
		{
			mCurrState = 0;
		}
	}

	//
	virtual void Loop(float DeltaTime) {
		if (mCurrState)
		{
			mCurrState->Loop(DeltaTime, mCurrState);
		}
	}

protected:
	//
	FState* mCurrState = 0;
	FState* mLastState = 0;

	//
	uint8 mCurrStateName;
	uint8 mLastStateName;

private:
	//TMap<uint8, FState*> mStateContainer;
	TArray<FState*>mStateContainer;
public:
	TFunction<void(uint8 NewState, uint8 LastState)>OnStateChangeEvent = 0;
};
