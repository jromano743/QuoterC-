#pragma once
#include <iostream>
#include <string.h>
#include "Clothe.h"

using namespace std;

class Shirt : public Clothe
{
private:
    string sleeveType;
    string collarType;

public:
    Shirt(string code, string quality, int stock, string sleeveType, string collarType);
    void CalculateUnitPrice(float& unitPrice) override;
    string GetFullName() override;
    bool IsEquals(string quality, string sleeveType, string collarType, string cutType) override;
};