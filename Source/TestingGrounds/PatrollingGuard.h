// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()


public:
	TArray<AActor*> GetPatrolPoints();

protected:
	UPROPERTY(EditAnywhere, category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;

private:

};
