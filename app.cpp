#include <iostream>
#include "clsLoginScreen.h"

int main()

{
  while (true)
  {
    if (!clsLoginScreen::ShowLoginScreen())
    {
      break;
    }
  }

  return 0;
}
