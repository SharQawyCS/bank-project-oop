#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen

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
    cout << "\nUserName    : " << User.GetUserName();
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
  static void ShowUpdateUserScreen()
  {

    _DrawScreenHeader("\tUpdate User Screen");

    string UserName = "";

    cout << "\nPlease Enter User UserName: ";
    UserName = clsInputValidate::ReadString();

    while (!clsUser::IsUserExist(UserName))
    {
      cout << "\nAccount number is not found, choose another one: ";
      UserName = clsInputValidate::ReadString();
    }

    clsUser User1 = clsUser::Find(UserName);

    _PrintUser(User1);

    cout << "\nAre you sure you want to update this User y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

      cout << "\n\nUpdate User Info:";
      cout << "\n____________________\n";

      _ReadUserInfo(User1);

      clsUser::enSaveResults SaveResult;

      SaveResult = User1.Save();

      switch (SaveResult)
      {
      case clsUser::enSaveResults::svSucceeded:
      {
        cout << "\nUser Updated Successfully :-)\n";

        _PrintUser(User1);
        break;
      }
      case clsUser::enSaveResults::svFaildEmptyObject:
      {
        cout << "\nError User was not saved because it's Empty";
        break;
      }
      }
    }
  }
};
