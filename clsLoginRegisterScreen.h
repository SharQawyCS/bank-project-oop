#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{

private:
  static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
  {

    cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
    cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
    cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
    cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
  }

public:
  static void ShowLoginRegisterScreen()
  {
    if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
    {
      return; // this will exit the function and it will not continue
    }

    vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

    string Title = "\tLogin Register List Screen";
    string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

    _DrawScreenHeader(Title, SubTitle);

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
    cout << "| " << left << setw(20) << "UserName";
    cout << "| " << left << setw(20) << "Password";
    cout << "| " << left << setw(10) << "Permissions";
    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vLoginRegisterRecord.size() == 0)
      cout << "\t\t\t\tNo Logins Available In the System!";
    else

      for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
      {

        PrintLoginRegisterRecordLine(Record);
        cout << endl;
      }

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
  }
};
