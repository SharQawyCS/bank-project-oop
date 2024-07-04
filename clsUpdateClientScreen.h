#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen

{
private:
  static void _PrintClient(clsBankClient Client)
  {
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << Client.GetFirstName();
    cout << "\nLastName    : " << Client.GetLastName();
    cout << "\nFull Name   : " << Client.FullName();
    cout << "\nEmail       : " << Client.GetEmail();
    cout << "\nPhone       : " << Client.GetPhone();
    cout << "\nAcc. Number : " << Client.AccountNumber();
    cout << "\nPassword    : " << Client.GetPinCode();
    cout << "\nBalance     : " << Client.GetAccountBalance();
    cout << "\n___________________\n";
  }

  static void ReadClientInfo(clsBankClient &Client)
  {
    cout << "\nEnter FirstName: ";
    Client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName: ";
    Client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
  }

public:
  static void ShowUpdateClientScreen()
  {
    if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
    {
      return; // this will exit the function and it will not continue
    }

    _DrawScreenHeader("\tUpdate Client Screen");

    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
      cout << "\nAccount number is not found, choose another one: ";
      AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);

    _PrintClient(Client1);

    cout << "\nAre you sure you want to update this client y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

      cout << "\n\nUpdate Client Info:";
      cout << "\n____________________\n";

      ReadClientInfo(Client1);

      clsBankClient::enSaveResults SaveResult;

      SaveResult = Client1.Save();

      switch (SaveResult)
      {
      case clsBankClient::enSaveResults::svSucceeded:
      {
        cout << "\nAccount Updated Successfully :-)\n";

        _PrintClient(Client1);
        break;
      }
      case clsBankClient::enSaveResults::svFaildEmptyObject:
      {
        cout << "\nError account was not saved because it's Empty";
        break;
      }
      }
    }
  }
};
