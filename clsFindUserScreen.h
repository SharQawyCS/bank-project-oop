#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{

private:
  static void _PrintUser(clsUser User)
  {
    cout << "\nUser Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << User.GetFirstName();
    cout << "\nLastName    : " << User.GetLastName();
    cout << "\nFull Name   : " << User.FullName();
    cout << "\nEmail       : " << User.GetEmail();
    cout << "\nPhone       : " << User.GetPhone();
    cout << "\nUserName    : " << User.GetUserName();
    cout << "\nPassword    : " << User.GetPassword();
    cout << "\nPermissions : " << User.GetPermissions();
    cout << "\n___________________\n";
  }

public:
  static void ShowFindUserScreen()
  {

    _DrawScreenHeader("\t  Find User Screen");

    string UserName;
    cout << "\nPlease Enter UserName: ";
    UserName = clsInputValidate::ReadString();
    while (!clsUser::IsUserExist(UserName))
    {
      cout << "\nUser is not found, choose another one: ";
      UserName = clsInputValidate::ReadString();
    }

    clsUser User1 = clsUser::Find(UserName);

    if (!User1.IsEmpty())
    {
      cout << "\nUser Found :-)\n";
    }
    else
    {
      cout << "\nUser Was not Found :-(\n";
    }

    _PrintUser(User1);
  }
};
