#include <iostream>
#include "clsLoginScreen.h"

int main()

{
  cout <<"\nThis Nagy Ahmed ";
  while (true)
  {
    if (!clsLoginScreen::ShowLoginScreen())
    {
      break;
    }
  }

  return 0;
}
