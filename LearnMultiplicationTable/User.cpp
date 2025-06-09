#include "User.h"
#include "Structs.h"


std::istream& operator >> (std::istream& in, User& obj)
{
	in >> obj.Name;
	in >> obj.Score;
	return in;
}

std::ostream& operator << (std::ostream& out, const User& obj)
{
	out << obj.Name << ' ';
	out << obj.Score << std::endl;
	return out;
}

void User::SaveUser(User& user)
{
    std::ofstream SaveFile(SAVEFILE_NAME);
    SaveFile << user;
    SaveFile.close();
}

bool User::LoadUser(User& user)
{
    std::ifstream ExistingSaveFile(SAVEFILE_NAME);
    if (ExistingSaveFile.good())
    {
        ExistingSaveFile >> user;
        ExistingSaveFile.close();
        return true;
    }
    return false;
}