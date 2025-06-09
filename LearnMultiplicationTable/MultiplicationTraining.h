#pragma once
#include "User.h"

namespace General
{

	User CurrentUser("");

	void Initialize(bool ForceNewUser = false);

	void MainMenu();

	void SelectOption(int InOption);

	void StartExercise(ExerciseStruct Exercise = {});

	void StartTableExercise();

	MultiplicationStruct GenerateMultiplication(ExerciseStruct Exercise = {});

	int GenerateRandomNumber(int min, int max);


}