#include "Clothe.h"

void Clothe::CalculateUnitPriceByQuality(float& unit_price)
{
    if (quality == "Premium")
        unit_price *= 1.3;
}

void Clothe::RemoveStock(int stock)
{
    this->stock -= stock;

    if (this->stock < 0) this->stock = 0;

}

void Clothe::AddStock(int stock)
{
    this->stock += stock;
}