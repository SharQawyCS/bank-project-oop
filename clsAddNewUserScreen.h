#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:
  static void _ReadUserInfo(clsUser &User)
  {
    cout << "\nEnter FirstName: ";
    User.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName: ";
    User.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email: ";
    User.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone: ";
    User.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter Password: ";
    User.SetPassword(clsInputValidate::ReadString());

    cout << "\nEnter Permission: ";
    User.SetPermissions(_ReadPermissionsToSet());
  }

  static void _PrintUser(clsUser User)
  {
    cout << "\nUser Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << User.GetFirstName();
    cout << "\nLastName    : " << User.GetLastName();
    cout << "\nFull Name   : " << User.FullName();
    cout << "\nEmail       : " << User.GetEmail();
    cout << "\nPhone       : " << User.GetPhone();
    cout << "\nUser Name   : " << User.GetUserName();
    cout << "\nPassword    : " << User.GetPassword();
    cout << "\nPermissions : " << User.GetPermissions();
    cout << "\n___________________\n";
  }

  static int _ReadPermissionsToSet()
  {

    int Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

      Permissions += clsUser::enPermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      Permissions += clsUser::enPermissions::pManageUsers;
    }

    return Permissions;
  }

public:
  static void ShowAddNewUserScreen()
  {

    _DrawScreenHeader("\t  Add New User Screen");

    string UserName = "";

    cout << "\nPlease Enter UserName: ";
    UserName = clsInputValidate::ReadString();
    while (clsUser::IsUserExist(UserName))
    {
      cout << "\nUserName Is Already Used, Choose another one: ";
      UserName = clsInputValidate::ReadString();
    }

    clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

    _ReadUserInfo(NewUser);

    clsUser::enSaveResults SaveResult;

    SaveResult = NewUser.Save();

    switch (SaveResult)
    {
    case clsUser::enSaveResults::svSucceeded:
    {
      cout << "\nUser Addeded Successfully :-)\n";
      _PrintUser(NewUser);
      break;
    }
    case clsUser::enSaveResults::svFaildEmptyObject:
    {
      cout << "\nError User was not saved because it's Empty";
      break;
    }
    case clsUser::enSaveResults::svFaildUserExists:
    {
      cout << "\nError User was not saved because UserName is used!\n";
      break;
    }
    }
  }
};
