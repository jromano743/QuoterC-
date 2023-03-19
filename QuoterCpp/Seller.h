#pragma once
#include <iostream>
#include <string.h>
#include "Store.h"

using namespace std;

class Seller
{
private:
    string code;
    string name;
    string lastname;
    Store* store;

public:
    Seller(string code, string name, string lastName, Store* store);
    string GetFullName() { return name + " " + lastname; };
    string GetCode() { return code; };
};