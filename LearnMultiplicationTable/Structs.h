#pragma once

struct MultiplicationStruct
{
	int Multiplicand = 0;
	int Multiplier = 0;
	int Result = 0;

	bool IsNumberInFactors(int Number)
	{
		if (this->Multiplicand == Number || this->Multiplier == Number) 
		{
			return true;
		}

		return false;
	}
};

struct ExerciseStruct {

	ExerciseStruct(MultiplicationStruct Multiplication = {}, bool TableExercise = false) {
		this->Multiplication = Multiplication;
		this->TableExercise = TableExercise;
	}

	MultiplicationStruct Multiplication;
	bool TableExercise = false;
};
