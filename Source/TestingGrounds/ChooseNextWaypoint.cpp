// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "ChooseNextWaypoint.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	SetNextWaypoint(OwnerComp);
	CycleIndex(OwnerComp);
	/*auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->GetPatrolPoints();

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	Blackboard->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	Index++;
	auto LengthMod = Index % PatrolPoints.Num();
	Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, LengthMod);*/


	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index)
	return EBTNodeResult::Succeeded;
}

TArray<AActor*> UChooseNextWaypoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->GetPatrolPoints();
	return PatrolPoints;
}

void UChooseNextWaypoint::SetNextWaypoint(UBehaviorTreeComponent& OwnerComp)
{
	auto PatrolPoints = GetPatrolPoints(OwnerComp);
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	Blackboard->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
}

void UChooseNextWaypoint::CycleIndex(UBehaviorTreeComponent& OwnerComp)
{
	auto PatrolPoints = GetPatrolPoints(OwnerComp);
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	Index ++;
	auto LengthMod = Index % PatrolPoints.Num();
	Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, LengthMod);
}