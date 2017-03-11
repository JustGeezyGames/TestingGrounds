// Copyright Just Geezy Games 2017.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const;

protected:
	UPROPERTY(EditAnywhere, category = "Patrol Route")
	TArray<AActor*> PatrolPoints;

};
