#pragma once
#include <fstream>
#include <istream>
#include "Structs.h"

#define SAVEFILE_NAME "SaveFile.dat"

class User
{

private:
	std::string Name;
	unsigned int Score = 0;


public:

	User(std::string Name, int Points = 0)
	{
		this->Name = Name;
		this->Score = Points;
	}

	void SetName(std::string Name)
	{
		this->Name = Name;
	}

	void SetScore(int InPoints)
	{
		this->Score = InPoints;
	}

	void InscreaseScore(int Value)
	{
		this->Score += Value;
	}

	void WinScore(MultiplicationStruct Calculation) 
	{

		if (Calculation.IsNumberInFactors(1) || Calculation.IsNumberInFactors(10))
			return;

		this->InscreaseScore(1);

	}

	void DecreaseScore(int Value)
	{
		this->Score -= Value;
	}

	std::string GetName()
	{
		return this->Name;
	}

	int GetScore()
	{
		return this->Score;
	}

	friend std::istream& operator >> (std::istream& in, User& obj);
	friend std::ostream& operator << (std::ostream& out, const User& obj);

	static void SaveUser(User& user);

	static bool LoadUser(User& user);

};