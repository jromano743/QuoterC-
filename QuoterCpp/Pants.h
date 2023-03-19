#pragma once
#include <iostream>
#include <string.h>
#include "Clothe.h"

using namespace std;

class Pants : public Clothe
{
private:
    string cutType;

public:
    Pants(string code, string quality, int stock, string cutType);
    void CalculateUnitPrice(float& unitPrice) override;
    string GetFullName() override;
    bool IsEquals(string quality, string sleeveType, string collarType, string cutType) override;
};