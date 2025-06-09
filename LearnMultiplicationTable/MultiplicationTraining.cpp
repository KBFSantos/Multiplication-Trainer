#include <iostream>
#include <Windows.h>
#include <string>
#include "MultiplicationTraining.h"


int main()
{
    General::Initialize();
}

void General::Initialize(bool ForceNewUser) 
{
    SetConsoleTitleA("Multiplication Training");
    system("cls");


    // Load User Save File
    if (!ForceNewUser)
    {
        if (User::LoadUser(General::CurrentUser))
        {
            General::MainMenu();
            return;
        }
    }

    // Insert Name
    std::string InName;
    std::cout << "Insert Nickname: ";
    std::cin >> InName;

    //Setup User
    General::CurrentUser.SetName(InName);
    General::CurrentUser.SetScore(0);

    User::SaveUser(General::CurrentUser);


    General::MainMenu();
}

void General::MainMenu() 
{
    system("cls");
    std::string Option;
    int Selected = 0;
    std::cout << "Multiplication Training" << std::endl << std::endl;
    std::cout << "User: " << General::CurrentUser.GetName() << "\nScore: " << General::CurrentUser.GetScore() << "\n\n" << "1 - Start Random Exercise\n2 - Table Exercise\n3 - Create New User" << std::endl;

    std::cout << std::endl << "Select: ";
    std::cin >> Option;

    try {
        Selected = std::stoi(Option);
    }
    catch (...) {
        General::MainMenu();
        return;
    }

    SelectOption(Selected);
}

void General::StartExercise(ExerciseStruct Exercise)
{
    system("cls");

    std::string input;
    int Answer;

    MultiplicationStruct Calculation = General::GenerateMultiplication(Exercise);

    std::cout << Calculation.Multiplicand << " X " << Calculation.Multiplier << std::endl;

    std::cout << "\nAnswer (or type 'q' to quit): ";
    std::cin >> input;

    // Check if the user wants to quit
    if (input == "q" || input == "Q") {
        General::MainMenu();
        return;
    }

    // Check input
    try {
        Answer = std::stoi(input);
    }
    catch (...) {
        std::cout << "Invalid input. Please enter a number or 'q' to quit.\n";
        system("pause");
        StartExercise(ExerciseStruct(Calculation, Exercise.TableExercise));
        return;
    }

    // Check the answer
    if (Answer == Calculation.Result) {
        General::CurrentUser.WinScore(Calculation);
        User::SaveUser(General::CurrentUser);



        if (Exercise.TableExercise) 
        {

            if (Exercise.Multiplication.Multiplier < 10) {
                Exercise.Multiplication.Multiplier++;
            }
            else
            {
                system("cls");
                std::cout << "You've mastered the multiplication table!\n";
                system("pause");
                General::MainMenu();
                return;
            }
        }
        else 
        {
            Exercise = ExerciseStruct();
        }
            
       
        StartExercise(Exercise);
    }
    else 
    {
        system("cls");
        std::cout << "You Failed!" << std::endl;
        system("pause");

        General::MainMenu();
    }



}

void General::StartTableExercise() 
{
    system("cls");
    int SelectedTable;
    std::cout << "Select Table: ";
    std::cin >> SelectedTable;

    if (SelectedTable > 0)
    {
        StartExercise(ExerciseStruct({ SelectedTable, 1 }, true));
    }
    else
    {
        MainMenu();
    }

}


void General::SelectOption(int InOption)
{

    switch (InOption)
    {
    case 1:
        StartExercise();
        break;

    case 2:
        StartTableExercise();
            break;

    case 3:
        Initialize(true);
        break;

    default:
        General::MainMenu();
        break;
    }
}

MultiplicationStruct General::GenerateMultiplication(ExerciseStruct Exercise)
{
    MultiplicationStruct MultiplicationData;

    MultiplicationData.Multiplicand = (Exercise.Multiplication.Multiplicand > 0 ? Exercise.Multiplication.Multiplicand : General::GenerateRandomNumber(2, 10));
    MultiplicationData.Multiplier = (Exercise.Multiplication.Multiplier > 0 ? Exercise.Multiplication.Multiplier : General::GenerateRandomNumber(2, 10));

    MultiplicationData.Result = MultiplicationData.Multiplicand * MultiplicationData.Multiplier;

    return MultiplicationData;
}

int General::GenerateRandomNumber(int min, int max) 
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); 
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

