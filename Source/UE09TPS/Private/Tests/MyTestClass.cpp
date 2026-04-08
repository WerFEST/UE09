// Fill out your copyright notice in the Description page of Project Settings.


#include "Tests/MyTestClass.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyTestClass, "UE09.CustomTests.FirstTest",
	EAutomationTestFlags::ProductFilter |
	EAutomationTestFlags::EditorContext |
	EAutomationTestFlags::HighPriority);


bool FMyTestClass::RunTest(const FString& Parameters)
{
	bool result = TestTrue("Test two different digits", FMath::Max(13, 25) == 25);
	TestEqual("Test two equal digits", FMath::Max(1, 1), 1);
	TestTrueExpr(FMath::Max(1, 100) == 100);
	TestTrue("Test two float digits", FMath::Max(4.0f, 8.0f) == 8.0f);

	return result;
}