#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{

private:
  string _FirstName;
  string _LastName;
  string _Email;
  string _Phone;

public:
  clsPerson(string FirstName, string LastName, string Email, string Phone)
  {

    _FirstName = FirstName;
    _LastName = LastName;
    _Email = Email;
    _Phone = Phone;
  }

  // Property Set
  void SetFirstName(string FirstName)
  {
    _FirstName = FirstName;
  }

  // Property Get
  string GetFirstName()
  {
    return _FirstName;
  }

  // Property Set
  void SetLastName(string LastName)
  {
    _LastName = LastName;
  }

  // Property Get
  string GetLastName()
  {
    return _LastName;
  }

  // Property Set
  void SetEmail(string Email)
  {
    _Email = Email;
  }

  // Property Get
  string GetEmail()
  {
    return _Email;
  }

  // Property Set
  void SetPhone(string Phone)
  {
    _Phone = Phone;
  }

  // Property Get
  string GetPhone()
  {
    return _Phone;
  }

  string FullName()
  {
    return _FirstName + " " + _LastName;
  }

  void Print()
  {
    cout << "\nInfo:";
    cout << "\n___________________";
    cout << "\nFirstName: " << _FirstName;
    cout << "\nLastName : " << _LastName;
    cout << "\nFull Name: " << FullName();
    cout << "\nEmail    : " << _Email;
    cout << "\nPhone    : " << _Phone;
    cout << "\n___________________\n";
  }
};
