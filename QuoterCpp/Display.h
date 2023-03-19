#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Quotation.h"

using namespace std;

class Display
{
private:
    void ShowQuotation(Quotation* quotation);
    void ShowTitle(string option);
    void ShowBackMenu(bool toMainMenu);

public:
    Display();
    void ClearScreen();
    void ShowMainMenu(string clothingStoreHeader, string sellerHeader);
    void ShowQuotationHistoryMenu(vector<Quotation*> quotationList);
    void ShowNewQuotationMenuName();
    void ShowNewQuotationMenuShirtSleeve();
    void ShowNewQuotationMenuShirtCollar();
    void ShowNewQuotationMenuPantsCut();
    void ShowNewQuotationMenuQuality();
    void ShowNewQuotationMenuUnitPrice();
    void ShowNewQuotationMenuStock(int stock);
    void ShowNewQuotationMenuResult(Quotation* quotation);
    void ShowStockError();
    void ShowContinueMenu(string message);
};