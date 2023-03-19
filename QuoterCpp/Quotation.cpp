#include "Quotation.h"

Quotation::Quotation()
{
    //^^
}

Quotation::Quotation(int id, Seller* seller, Clothe* clothes, float unitPrice, int quantity)
{
    this->id = id;
    this->date = time(NULL);
    this->seller = seller;
    this->clothes = clothes;
    this->unitPrice = unitPrice;
    this->quantity = quantity;
    clothes->CalculateUnitPrice(unitPrice);
    this->result = quantity * unitPrice;
};

string Quotation::GetDate()
{
    ctime_s(dateStr, sizeof dateStr, &date);
    return dateStr;
}