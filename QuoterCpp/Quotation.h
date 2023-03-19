#pragma once
#include <iostream>
#include <string.h>
#include <chrono>
#include <ctime>
#include "Clothe.h"
#include "Seller.h"
#include <time.h>

using namespace std;

class Quotation
{
private:
    int id;
    time_t  date;
    char dateStr[26];
    Seller* seller;
    Clothe* clothes;
    float unitPrice;
    int quantity;
    int amount;

public:
    Quotation();
    Quotation(int id, Seller* seller, Clothe* clothes, float unitPrice, int quantity);
    int GetId() { return id; };
    string GetDate();
    string GetSellerCode() { return seller->GetCode(); }
    string GetClothesFullName() { return clothes->GetFullName(); }
    float GetUnitPrice() { return unitPrice; };
    int GetQuantity() { return quantity; };
    int GetAmount() { return amount; };
};