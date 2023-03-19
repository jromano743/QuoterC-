#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Clothe
{
protected:
    string code;
    string name;
    string quality;
    int stock;
    void CalculateUnitPriceByQuality(float& unitPrice);

public:
    int GetStock() { return stock; };
    virtual void CalculateUnitPrice(float& unitPrice) {};
    virtual string GetFullName() { return ""; };
    virtual bool IsEquals(string quality, string sleeveType, string collarType, string cutType) { return false; }
    void RemoveStock(int stock);
    void AddStock(int stock);
};