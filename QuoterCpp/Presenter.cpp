#include "Presenter.h"


Presenter::Presenter()
{
    clothes = new Clothe();
    quotation = new Quotation();
    quotationSystem = new QuotationSystem();
    quotationSystem->InitializeData();
    display = new Display();
    id = 1;
    quality = "";
    sleeveType = "";
    collarType = "";
    cutType = "";
    unitPrice = 0;
    quantity = 0;
}

void Presenter::ClearData()
{
    id++;
    quality = "";
    sleeveType = "";
    collarType = "";
    cutType = "";
    unitPrice = 0;
    quantity = 0;
}

int Presenter::PrintMainMenu()
{
    int opt = 0;
    do
    {
        display->ClearScreen();
        display->ShowMainMenu(
            quotationSystem->GetStoreHeader(),
            quotationSystem->GetSellerHeader());
        cin >> opt;
    } while (opt != 1 && opt != 2 && opt != 0);

    return opt;
}

void Presenter::MakeNewQuotationMenu()
{
    int clotheSelected = PrintNewQuotationMenu();
    int backToMenu = -1;

    if (clotheSelected == 0) return;

    if (clotheSelected == 1)
    {
        LoadShirtSleeves(&backToMenu);
        if (BackToMenu(backToMenu)) return;

        LoadShirtCollars(&backToMenu);
        if (BackToMenu(backToMenu)) return;
    }
    else
    {
        LoadPantsType(&backToMenu);
        if (BackToMenu(backToMenu)) return;
    }

    LoadQualityType(&backToMenu);
    if (BackToMenu(backToMenu)) return;

    float unitPrice = LoadUnitPrice(&backToMenu);
    if (BackToMenu(backToMenu)) return;

    clothes = quotationSystem->FindClothe(quality, sleeveType, collarType, cutType);

    bool hasStock = LoadQuantity(&backToMenu);
    if (BackToMenu(backToMenu)) return;

    if (hasStock)
    {
        PrintQuotationResult();

        ClearData();
    }
    else
    {
        ClearData();
    }


}

void Presenter::PrintMenu()
{
    int opt = 0;
    do
    {
        opt = PrintMainMenu();
        switch (opt)
        {
        case 1:
            MakeNewQuotationMenu();
            PrintMenu();
            break;
        case 2:
            ShowQuotationHistoryMenu();
            PrintMenu();
            break;
        case 0:
            cout << "Apagando..." << endl;
            break;
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (opt != 0);

}

void Presenter::ShowQuotationHistoryMenu()
{
    int opt = 0;
    do
    {
        display->ClearScreen();
        display->ShowQuotationHistoryMenu(quotationSystem->GetQuotationList());
        cin >> opt;
    } while (opt != 0);

}

/*
1 => Shirt
2 => Pants
*/
int Presenter::PrintNewQuotationMenu()
{
    int opt = 0;
    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuName();
        cin >> opt;
        if (opt == 3)
        {

            ShowQuotationHistoryMenu();
        }
    } while (opt != 1 && opt != 2 && opt != 0);

    return opt;
}

void Presenter::LoadShirtSleeves(int* optionSelected)
{
    int opt = 0;
    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuShirtSleeve();
        cin >> opt;
        if (opt == 3)
        {
            ShowQuotationHistoryMenu();
        }
    } while (opt != 1 && opt != 2 && opt != 0);

    sleeveType = opt == 1 ? "Manga corta" : "Manga larga";

    *optionSelected = opt;
}

void Presenter::LoadShirtCollars(int* optionSelected)
{
    int opt = 0;
    do {
        display->ClearScreen();
        display->ShowNewQuotationMenuShirtCollar();
        cin >> opt;
        if (opt == 3)
        {
            ShowQuotationHistoryMenu();
        }
    } while (opt != 1 && opt != 2 && opt != 0);

    collarType = opt == 1 ? "Cuello mao" : "Cuello com�n";

    *optionSelected = opt;
}

void Presenter::LoadPantsType(int* optionSelected)
{
    int opt = 0;
    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuPantsCut();
        cin >> opt;
        if (opt == 3)
        {
            ShowQuotationHistoryMenu();
        }
    } while (opt != 1 && opt != 2 && opt != 0);

    cutType = opt == 1 ? "Chup�n" : "Com�n";

    *optionSelected = opt;
}

void Presenter::LoadQualityType(int* optionSelected)
{
    int opt = 0;

    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuQuality();
        cin >> opt;
        if (opt == 3)
        {
            ShowQuotationHistoryMenu();
        }
    } while (opt != 1 && opt != 2 && opt != 0);

    quality = opt == 1 ? "Standard" : "Premium";

    *optionSelected = opt;
}

float Presenter::LoadUnitPrice(int* optionSelected)
{
    int opt = 0;
    unitPrice = 0;
    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuUnitPrice();
        cin >> unitPrice;

        display->ClearScreen();
        string msg("El precio ingreso es de: ");
        std::string numText = std::to_string(unitPrice);
        std::string numRounded = numText.substr(0, numText.find(".") + 3);
        msg += numRounded;
        msg += "$";
        display->ShowContinueMenu(msg);
        cin >> opt;

        if (opt == 2 || opt == 3)
        {
            unitPrice = 0;

            if (opt == 3)
            {
                ShowQuotationHistoryMenu();
            }
        }

    } while (unitPrice <= 0 || (opt != 0 && opt != 1));

    *optionSelected = opt;

    return unitPrice;
}

bool Presenter::LoadQuantity(int* optionSelected)
{
    int opt = 0;
    quantity = 0;

    if (quotation == NULL)
    {
        display->ClearScreen();
        display->ShowStockError();
        return false;
    }

    bool hasStock = false;
    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuStock(clothes->GetStock());
        cin >> quantity;

        string msg("La cantidad de stock solicitada es de: ");
        msg += to_string(quantity);
        display->ClearScreen();
        display->ShowContinueMenu(msg);

        cin >> opt;
        if (opt == 2 || opt == 3)
        {
            quantity = 0;

            if (opt == 3)
            {
                ShowQuotationHistoryMenu();
            }
        }

        if (quantity > 0)
        {
            if (quantity <= clothes->GetStock())
            {
                quotation = quotationSystem->AddQuotation(id, clothes, unitPrice, quantity);
                hasStock = true;
                break;
            }
            else
            {
                hasStock = false;
                PrintErrorStock();
                break;
            }
        }

    } while (quantity <= 0 || (opt != 1 && opt != 0));

    return hasStock;
}

void Presenter::PrintQuotationResult()
{
    int opt = 0;

    do
    {
        display->ClearScreen();
        display->ShowNewQuotationMenuResult(quotation);
        cin >> opt;
    } while (opt != 0);
}

void Presenter::PrintErrorStock()
{
    char letter;
    display->ClearScreen();
    display->ShowStockError();
    cin >> letter;
}

bool Presenter::BackToMenu(int option)
{
    if (option == 0)
    {
        ClearData();
        return true;
    }

    return false;
}