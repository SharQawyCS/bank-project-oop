#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
  enum enTransactionsMenueOptions
  {
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenue = 4
  };

  static short ReadTransactionsMenueOption()
  {
    cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
    short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
    return Choice;
  }

  static void _ShowDepositScreen()
  {
    // cout << "\n Deposit Screen will be here.\n";
    clsDepositScreen::ShowDepositScreen();
  }

  static void _ShowWithdrawScreen()
  {
    // cout << "\n Withdraw Screen will be here.\n";
    clsWithdrawScreen::ShowWithdrawScreen();
  }

  static void _ShowTotalBalancesScreen()
  {
    // cout << "\n Balances Screen will be here.\n";
    clsTotalBalancesScreen::ShowTotalBalances();
  }

  static void _GoBackToTransactionsMenue()
  {
    cout << "\n\nPress any key to go back to Transactions Menue...";
    Global::Pause();
    ShowTransactionsMenue();
  }

  static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
  {
    switch (TransactionsMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
      Global::Clear();
      _ShowDepositScreen();
      _GoBackToTransactionsMenue();
      break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
      Global::Clear();
      _ShowWithdrawScreen();
      _GoBackToTransactionsMenue();
      break;
    }

    case enTransactionsMenueOptions::eShowTotalBalance:
    {
      Global::Clear();
      _ShowTotalBalancesScreen();
      _GoBackToTransactionsMenue();
      break;
    }

    case enTransactionsMenueOptions::eShowMainMenue:
    {

      // do nothing here the main screen will handle it :-) ;
    }
    }
  }

public:
  static void ShowTransactionsMenue()
  {

    if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
    {
      return; // this will exit the function and it will not continue
    }

    Global::Clear();
    _DrawScreenHeader("\tTransactions Screen");

    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Deposit.\n";
    cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
    cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
    cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
    cout << setw(37) << left << "" << "===========================================\n";

    _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
  }
};
