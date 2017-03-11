// Copyright Just Geezy Games 2017.

#include "TestingGrounds.h"
#include "PatrolRouteComponent.h"


TArray<AActor*> UPatrolRouteComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}

