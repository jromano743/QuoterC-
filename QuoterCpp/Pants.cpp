#include "Pants.h"

Pants::Pants(string code, string quality, int stock, string cutType)
{
    this->code = code;
    this->name = "Pantalon";
    this->quality = quality;
    this->stock = stock;
    this->cutType = cutType;
};

void Pants::CalculateUnitPrice(float& unitPrice)
{
    if (cutType == "Chupin")
    {
        unitPrice *= 0.88;
    }
    CalculateUnitPriceByQuality(unitPrice);
};

string Pants::GetFullName()
{
    return name + " - " + cutType + " - " + quality;
};

bool Pants::IsEquals(string quality, string sleeveType, string collarType, string cutType)
{
    return this->quality == quality && this->cutType == cutType;
}