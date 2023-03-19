#include "Shirt.h"

Shirt::Shirt(string code, string quality, int stock, string sleeveType, string collarType)
{
    this->code = code;
    this->name = "Camisa";
    this->quality = quality;
    this->stock = stock;
    this->sleeveType = sleeveType;
    this->collarType = collarType;
};

void Shirt::CalculateUnitPrice(float& unitPrice)
{
    if (sleeveType == "Manga corta")
    {
        unitPrice *= 0.9;
    }
    if (collarType == "Cuello mao")
    {
        unitPrice *= 1.03;
    }
    CalculateUnitPriceByQuality(unitPrice);
};

string Shirt::GetFullName()
{
    return name + " - " + sleeveType + " - " + collarType + " - " + quality;
};

bool Shirt::IsEquals(string quality, string sleeveType, string collarType, string cutType)
{
    return this->quality == quality && this->sleeveType == sleeveType && this->collarType == collarType;
}