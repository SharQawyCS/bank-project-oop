#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
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
  static void ShowDeleteUserScreen()
  {

    _DrawScreenHeader("\tDelete User Screen");

    string UserName = "";

    cout << "\nPlease Enter UserName: ";
    UserName = clsInputValidate::ReadString();
    while (!clsUser::IsUserExist(UserName))
    {
      cout << "\nUser is not found, choose another one: ";
      UserName = clsInputValidate::ReadString();
    }

    clsUser User1 = clsUser::Find(UserName);
    _PrintUser(User1);

    cout << "\nAre you sure you want to delete this User y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

      if (User1.Delete())
      {
        cout << "\nUser Deleted Successfully :-)\n";
        _PrintUser(User1);
      }
      else
      {
        cout << "\nError User Was not Deleted\n";
      }
    }
  }
};
