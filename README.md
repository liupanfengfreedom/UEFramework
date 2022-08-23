# UEFramework


UENUM(BlueprintType)
enum EFlyMode
{
	/** None (movement is disabled). */
	Fly_None		UMETA(DisplayName = "None"),

	/** Walking on a surface. */
	Fly_Idle	UMETA(DisplayName = "Idle"),

	Fly_Move	UMETA(DisplayName = "Move"),

	 /** Falling under the effects of gravity, such as after jumping or walking off the edge of a surface. */
	Fly_Stop	UMETA(DisplayName = "Stop"),

	Fly_MAX		UMETA(Hidden),
};

/////////////////////////////////////////////////////////////////////////////////
///.h
class ATemplateTVCharacter : public ACharacter
{
    TSharedPtr<class FStateMachine> mFlyStateMachine;

}

/////////////////////////////////////////////////////////////////////////////////
///.cpp
void ATemplateTVCharacter::BeginPlay()
{
     Super::BeginPlay();
	
	 mFlyStateMachine = MakeShared<FStateMachine>();
	 mFlyStateMachine->AddState(new FState(EFlyMode::Fly_Idle, mFlyStateMachine.Get(), // Idle
	 [=]() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Idle enter"));

		 },
		 []() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Idle exit"));

		 },
		 [=](float DeltaTime, FState* Cs) {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Idle loop :%d"));
			 if (Cs->GetCurrentTimeCount() > 5)
			 {
				 mFlyStateMachine->ChangeStateTo(Fly_Move);
			 }

		 }));
	 mFlyStateMachine->AddState(new FState(EFlyMode::Fly_Move, mFlyStateMachine.Get(), // Idle
		 [=]() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Move enter"));

		 },
		 []() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Move exit"));

		 },
		 [=](float DeltaTime, FState* Cs) {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Move loop :%d"));
			 if (Cs->GetCurrentTimeCount() > 2)
			 {
				 mFlyStateMachine->ChangeStateTo(Fly_Stop);
			 }

		 }));
	 mFlyStateMachine->AddState(new FState(EFlyMode::Fly_Stop, mFlyStateMachine.Get(), // Idle
		 [=]() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Stop enter"));

		 },
		 []() {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Stop exit"));

		 },
		 [=](float DeltaTime, FState* Cs) {
			 UE_LOG(LogTemp, Warning, TEXT("Fly_Stop loop :%d"));
			 if (Cs->GetCurrentTimeCount() > 7)
			 {
				 mFlyStateMachine->ChangeStateTo(Fly_Idle);
			 }

		 }));
	 mFlyStateMachine->ChangeStateTo(Fly_Idle);

}
void ATemplateTVCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	mFlyStateMachine->Loop(DeltaSeconds);

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////  core .h

#pragma once

#include "CoreMinimal.h"

template<typename T1, typename T2>
class FStateMachine;

template<typename T1>
class  FState
{
	//static_assert(std::is_base_of<UObject, T2>::value, "T2 must be a base of or the same as UObject, Supporting UE4 WeakPtr.");

public:
	explicit FState() {}

	explicit FState(T1 State,class FStateMachine<T1, FState<T1>>* StateMachine, TFunction<void(void)>OnEnter, TFunction<void(void)>OnExit,TFunction<void(float,FState<T1>*)>OnLoop)
		:mState(State), mStateMachine(StateMachine), mOnEnter(OnEnter),mOnExit(OnExit),mOnLoop(OnLoop)
	{

	}

public:
	//
	virtual ~FState() {}

	//
	virtual void Enter() {
		mTickTime=0;
		if(mOnEnter)
		{
			mOnEnter();
		}
	}

	//
	virtual void Loop(float DeltaTime, FState<T1>*CurrentObject) {
		mTickTime+= DeltaTime;
		if (mOnLoop)
		{
			mOnLoop(DeltaTime,this);
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
	virtual bool CanChangeState(T1 NextState) { return true; }

	//
	T1 GetState() { return mState; }
	FStateMachine<T1, FState<T1>>* GetStateMachine(){return mStateMachine;}
	float GetCurrentTimeCount(){return mTickTime;}
private:
		float mTickTime = 0.0f;

	//
	T1 mState;
	FStateMachine<T1, FState<T1>>* mStateMachine;
	TFunction<void(void)>mOnEnter=0;
	TFunction<void(float,FState<T1>*)>mOnLoop=0;
	TFunction<void(void)>mOnExit = 0;

};
/**
 * 
 */
template<typename T1, typename T2>
class  FStateMachine
{
public:
	FStateMachine(){
		UE_LOG(LogTemp, Warning, TEXT("Create a new FStateMachine"));
	}
	virtual~FStateMachine(){
		ClearStates();
	}
	//static_assert(std::is_base_of<FState, T2>::value, "T2 must be a base of or the same as FState.");

public:

	//
	T2* TryGetState(T1 NewState) {
		T2* RefState = nullptr;
		if (mStateContainer.Num() > 0)
		{
			RefState = mStateContainer.FindRef(NewState);
			if (!RefState)
			{
				UE_LOG(LogTemp, Error, TEXT("FStateMachine:TryGetState-%d"), NewState);
			}
		}

		return RefState;
	}

	//
	void AddState(T2* StateObject) {
		if (!StateObject)
		{
			return;
		}

		//
		T1 NewState = StateObject->GetState();
		T2* RefState = mStateContainer.FindRef(NewState);
		if (RefState)
		{
			if (StateObject != RefState)
			{
				UE_LOG(LogTemp, Warning, TEXT("FStateMachine-Add/ReplaceState?-%d"), NewState);
				delete RefState;

				mStateContainer[NewState] = StateObject;
			}
			delete RefState;
		}
		else
		{
			mStateContainer.Add(NewState, StateObject);
		}
	}

	//Only Owner Actor Can do.
	void ReplaceState(T2* StateObject)
	{
		if (!StateObject)
		{
			return;
		}

		//
		T1 NewState = StateObject->GetState();
		T2* RefState = mStateContainer.FindRef(NewState);
		if (RefState)
		{
			if (StateObject != RefState)
			{
				delete RefState;
				//Only Owner Actor Can do.
				mStateContainer[NewState] = StateObject;
			}
		}
		else
		{
			mStateContainer.Add(NewState, StateObject);
		}
	}

	//
	T1 GetCurState()
	{
		return  mCurrStateName ;
	}
	//
	T1 GetLastState()
	{
		return mLastStateName;
	}
	//
	virtual bool CanChangeState(T1 NewState){return true;};

	//
	virtual bool ChangeStateTo(T1 NewState)
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

		T2* NewStateObject = TryGetState(NewState);
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
		for (const TPair<T1, T2*>& Pair : mStateContainer)
		{
			if (Pair.Value)
			{
				delete Pair.Value;
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
	T2* mCurrState = 0;
	T2* mLastState = 0;

	//
	T1 mCurrStateName;
	T1 mLastStateName;

private:
	TMap<T1, T2*> mStateContainer;
public:
    TFunction<void(T1 NewState,T1 LastState)>OnStateChangeEvent=0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//user h file
#include "FStateMachine.h"
#include "MyActor.generated.h"
UENUM(BlueprintType)
enum class ETestState : uint8
{
	//None
	State_None = 0,
	State_1,
	State_2,
	State_3,
	State_4,
	State_5, 
};
UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	// FStateMachine<ETestState, FState<ETestState>> *mStatema;
	TSharedPtr<FStateMachine<ETestState, FState<ETestState>>> mStatema;
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChange(ETestState News, ETestState Lasts);

	UFUNCTION(BlueprintCallable)    // External force state change
	void Changestate(ETestState News);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //user cpp file
 
#include "MyActor.h"
#include "ABCClassv1.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//mStatema = new FStateMachine<ETestState, FState<ETestState>>();
	mStatema = MakeShared<FStateMachine<ETestState, FState<ETestState>>>();
	mStatema->OnStateChangeEvent=[=](ETestState st1,ETestState st2){
		OnStateChange(st1,st2);
	};
	mStatema->AddState(new FState<ETestState>(ETestState::State_1, mStatema.Get(),
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_1 enter"));
		},
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_1 exit"));

		},
			[=](float DeltaTime, FState<ETestState>* Cs) {
			UE_LOG(LogTemp, Warning, TEXT("State_1 loop"));
			if (Cs->GetCurrentTimeCount() > 5)
			{
				mStatema->ChangeStateTo(ETestState::State_2);
			}
		}));
	mStatema->AddState(new FState<ETestState>(ETestState::State_2, mStatema.Get(),
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_2 enter"));
		},
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_2 exit"));

		},
			[=](float DeltaTime, FState<ETestState>* Cs) {
			UE_LOG(LogTemp, Warning, TEXT("State_2 loop"));
			if (Cs->GetCurrentTimeCount() > 10)
			{
				mStatema->ChangeStateTo(ETestState::State_1);
			}
		}));
	mStatema->AddState(new FState<ETestState>(ETestState::State_3, mStatema.Get(),
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_3 enter"));
		},
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_3 exit"));

		},
			[=](float DeltaTime, FState<ETestState>* Cs) {
			UE_LOG(LogTemp, Warning, TEXT("State_3 loop"));

		}));
	mStatema->AddState(new FState<ETestState>(ETestState::State_4, mStatema.Get(),
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_4 enter"));
		},
		[=]() {
			UE_LOG(LogTemp, Warning, TEXT("State_4 exit"));

		},
			[=](float DeltaTime, FState<ETestState>* Cs) {
			UE_LOG(LogTemp, Warning, TEXT("State_4 loop"));
			if (Cs->GetCurrentTimeCount() > 6)
			{
				mStatema->ChangeStateTo(ETestState::State_1);
			}
		}));

	mStatema->ChangeStateTo(ETestState::State_1);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mStatema->Loop(DeltaTime);
}

void AMyActor::Changestate(ETestState News)
{
	mStatema->ChangeStateTo(News);//  External force state change
}
