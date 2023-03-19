#pragma once

#include <iostream>
#include <string.h>
#include <vector>

#include "Store.h"
#include "Seller.h"
#include "Quotation.h"

#include "Clothe.h"
#include "Shirt.h"
#include "Pants.h"

using namespace std;

class QuotationSystem
{
private:
    Store* store;
    Seller* seller;
    vector<Quotation*> quotationList;

public:
    QuotationSystem();
    string GetSellerHeader() { return seller->GetFullName() + " | " + seller->GetCode(); }
    string GetStoreHeader() { return store->GetName() + " | " + store->GetAdress(); }
    vector<Quotation*> GetQuotationList() { return quotationList; }
    Clothe* FindClothe(string quality, string sleeveType, string collarType, string cutType)
    {
        return store->FindClothe(quality, sleeveType, collarType, cutType);
    };
    void InitializeData();
    Quotation* AddQuotation(int id, Clothe* clothes, float unitPrice, int quantity);
};