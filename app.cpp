#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient &Client)
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

void UpdateClient()
{
  string AccountNumber = "";

  cout << "\nPlease Enter client Account Number: ";
  AccountNumber = clsInputValidate::ReadString();

  while (!clsBankClient::IsClientExist(AccountNumber))
  {
    cout << "\nAccount number is not found, choose another one: ";
    AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient Client1 = clsBankClient::Find(AccountNumber);
  Client1.Print();

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
    Client1.Print();
    break;
  }
  case clsBankClient::enSaveResults::svFaildEmptyObject:
  {
    cout << "\nError account was not saved because it's Empty";
    break;
  }
  }
}

int main()
{
  UpdateClient();
  return 0;
}