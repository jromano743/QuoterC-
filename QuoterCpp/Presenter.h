#pragma once

#include <iostream>
#include <string>

#include "Display.h"

#include "Store.h"
#include "Seller.h"
#include "Quotation.h"
#include "QuotationSystem.h"

#include "Clothe.h"
#include "Pants.h"
#include "Shirt.h"



using namespace std;

class Presenter
{
private:
    QuotationSystem* quotationSystem;
    Display* display;
    Clothe* clothes;
    Quotation* quotation;
    int id;
    string quality;
    string sleeveType;
    string collarType;
    string cutType;
    float unitPrice;
    int quantity;
    int PrintMainMenu();
    void ShowQuotationHistoryMenu();
    int PrintNewQuotationMenu();
    void MakeNewQuotationMenu();
    void LoadShirtSleeves(int* optionSelected);
    void LoadShirtCollars(int* optionSelected);
    void LoadPantsType(int* optionSelected);
    void LoadQualityType(int* optionSelected);
    float LoadUnitPrice(int* optionSelected);
    bool LoadQuantity(int* optionSelected);
    void PrintQuotationResult();
    void ClearData();
    bool BackToMenu(int option);
    void PrintErrorStock();

public:
    Presenter();
    void PrintMenu();
};