#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Clothe.h"

using namespace std;

class Store
{
private:
    string code;
    string name;
    string address;
    vector<Clothe*> clothesList;

public:
    Store(string code, string name, string address);
    string GetName() { return name; };
    string GetAdress() { return address; };
    void AddClothes(Clothe* clothes);
    Clothe* FindClothe(string quality, string sleeveType, string collarType, string cutType);
};