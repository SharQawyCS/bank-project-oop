// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
  enum enCharType
  {
    SamallLetter = 1,
    CapitalLetter = 2,
    Digit = 3,
    MixChars = 4,
    SpecialCharacter = 5
  };

  static void Srand()
  {
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
  }

  static int RandomNumber(int From, int To)
  {
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
  }

  static char GetRandomCharacter(enCharType CharType)
  {

    // updated this method to accept mixchars
    if (CharType == MixChars)
    {
      // Capital/Samll/Digits only
      CharType = (enCharType)RandomNumber(1, 3);
    }

    switch (CharType)
    {

    case enCharType::SamallLetter:
    {
      return char(RandomNumber(97, 122));
      break;
    }
    case enCharType::CapitalLetter:
    {
      return char(RandomNumber(65, 90));
      break;
    }
    case enCharType::SpecialCharacter:
    {
      return char(RandomNumber(33, 47));
      break;
    }
    case enCharType::Digit:
    {
      return char(RandomNumber(48, 57));
      break;
    }
    defualt:
    {
      return char(RandomNumber(65, 90));
      break;
    }
    }
    return char(RandomNumber(65, 90));
  }

  static string GenerateWord(enCharType CharType, short Length)

  {
    string Word;

    for (int i = 1; i <= Length; i++)

    {

      Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
  }

  static string GenerateKey(enCharType CharType = CapitalLetter)
  {

    string Key = "";

    Key = GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4);

    return Key;
  }

  static void GenerateKeys(short NumberOfKeys, enCharType CharType)
  {

    for (int i = 1; i <= NumberOfKeys; i++)

    {
      cout << "Key [" << i << "] : ";
      cout << GenerateKey(CharType) << endl;
    }
  }

  static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
  {
    for (int i = 0; i < arrLength; i++)
      arr[i] = RandomNumber(From, To);
  }

  static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
  {
    for (int i = 0; i < arrLength; i++)
      arr[i] = GenerateWord(CharType, Wordlength);
  }

  static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
  {
    for (int i = 0; i < arrLength; i++)
      arr[i] = GenerateKey(CharType);
  }

  static void Swap(int &A, int &B)
  {
    int Temp;

    Temp = A;
    A = B;
    B = Temp;
  }

  static void Swap(double &A, double &B)
  {
    double Temp;

    Temp = A;
    A = B;
    B = Temp;
  }

  static void Swap(bool &A, bool &B)
  {
    bool Temp;

    Temp = A;
    A = B;
    B = Temp;
  }

  static void Swap(char &A, char &B)
  {
    char Temp;

    Temp = A;
    A = B;
    B = Temp;
  }

  static void Swap(string &A, string &B)
  {
    string Temp;

    Temp = A;
    A = B;
    B = Temp;
  }

  static void Swap(clsDate &A, clsDate &B)
  {
    clsDate::SwapDates(A, B);
  }

  static void ShuffleArray(int arr[100], int arrLength)
  {

    for (int i = 0; i < arrLength; i++)
    {
      Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
  }

  static void ShuffleArray(string arr[100], int arrLength)
  {

    for (int i = 0; i < arrLength; i++)
    {
      Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
  }

  static string Tabs(short NumberOfTabs)
  {
    string t = "";

    for (int i = 1; i < NumberOfTabs; i++)
    {
      t = t + "\t";
      cout << t;
    }
    return t;
  }
};
