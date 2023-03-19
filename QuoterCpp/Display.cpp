#include "Display.h"

Display::Display()
{
    cout << "Iniciando..." << endl;
};

void Display::ClearScreen()
{
    system("cls");
}

void Display::ShowTitle(string option)
{
    cout << "COTIZADOR EXPRESS - " << option << endl;
}

void Display::ShowBackMenu(bool toMainMenu)
{
    if (toMainMenu)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Presione 0 para cancelar la operacion" << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Presione 0 para volver" << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
    }

}

void Display::ShowQuotation(Quotation* quotation)
{
    string strUnitPrice;
    string strAmount;

    std::string numTextPrice = std::to_string(quotation->GetUnitPrice());
    std::string numRounded = numTextPrice.substr(0, numTextPrice.find(".") + 3);
    strUnitPrice += numRounded;
    strUnitPrice += "$";

    strAmount = std::to_string(quotation->GetAmount());
    strAmount += "$";

    cout << "\tNumero de identificacion: " << quotation->GetId() << endl;
    cout << "\tFecha y Hora de la cotizacion: " << quotation->GetDate();
    cout << "\tCodigo del Vendedor: " << quotation->GetSellerCode() << endl;
    cout << "\tPrenda Cotizada: " << quotation->GetClothesFullName() << endl;
    cout << "\tPrecio Unitario: " << strUnitPrice << endl;
    cout << "\tCantidad de unidades cotizadas: " << quotation->GetQuantity() << endl;
    cout << "\tPrecio final: " << strAmount << endl << endl;
}

void Display::ShowMainMenu(string clothingStoreHeader, string sellerSeader)
{
    ShowTitle("MENU PRINCIPAL");
    cout << "-------------------------------------------------------------------" << endl;
    cout << clothingStoreHeader << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << sellerSeader << endl;
    cout << "-------------------------------------------------------------------" << endl
        << endl;
    cout << "SELECCIONE UNA OPCION" << endl
        << endl;
    cout << "1) Realizar Cotizacion" << endl;
    cout << "2) Historial de Cotizaciones" << endl;
    cout << "0) Salir" << endl
        << endl;
    cout << "-------------------------------------------------------------------" << endl
        << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowQuotationHistoryMenu(vector<Quotation*> quotationList)
{
    ShowTitle("HISTORIAL DE COTIZACIONES");
    ShowBackMenu(false);
    if (quotationList.size() == 0)
    {
        cout << "No hay cotizaciones para mostrar" << endl << endl;
    }
    else
    {
        for (int i = 0; i < quotationList.size(); i++)
        {
            ShowQuotation(quotationList[i]);
        }
    }

    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuName()
{
    ShowTitle("COTIZAR: PRENDA");
    ShowBackMenu(true);
    cout << "Seleccione la prenda a cotizar" << endl;
    cout << "1) Camisa" << endl;
    cout << "2) Pantalon" << endl;
    cout << "3) Ver historial" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuShirtSleeve()
{
    ShowTitle("COTIZAR: CAMISA, MANGAS");
    ShowBackMenu(true);
    cout << "Seleccione el tipo de manga" << endl;
    cout << "1) Corta" << endl;
    cout << "2) Larga" << endl;
    cout << "3) Ver historial" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuShirtCollar()
{
    ShowTitle("COTIZAR: CAMISA, CUELLO");
    ShowBackMenu(true);
    cout << "Seleccione el tipo de cuello" << endl;
    cout << "1) Mao" << endl;
    cout << "2) Comun" << endl;
    cout << "3) Ver historial" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuPantsCut()
{
    ShowTitle("COTIZAR: PANTALON");
    ShowBackMenu(true);
    cout << "�El pantalon es chupin?" << endl;
    cout << "1) Si" << endl;
    cout << "2) No" << endl;
    cout << "3) Ver historial" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuQuality()
{
    ShowTitle("COTIZAR: CALIDAD");
    ShowBackMenu(true);
    cout << "Seleccione la calidad de la prenda" << endl;
    cout << "1) Standard" << endl;
    cout << "2) Premium" << endl;
    cout << "3) Ver historial" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void Display::ShowNewQuotationMenuUnitPrice()
{
    ShowTitle("COTIZAR: PRECIO (POR UNIDAD)");
    ShowBackMenu(true);
    cout << "Ingrese el precio unitario de la prenda a cotizar" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Precio unitario: ";
}

void Display::ShowNewQuotationMenuStock(int stock)
{
    ShowTitle("COTIZAR: STOCK");
    ShowBackMenu(true);
    cout << "INFORMACI�N:" << endl;
    cout << "Existen " << stock << " unidades en stock de la prenda seleccionada" << endl << endl << endl;
    cout << "Ingrese la cantidad de unidades a cotizar" << endl << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Cantidad de unidades: ";
}

void Display::ShowNewQuotationMenuResult(Quotation* quotation)
{
    ShowTitle("COTIZAR: REVICION");
    ShowBackMenu(false);
    ShowQuotation(quotation);
    cout << "Ingrese una opcion: ";
}

void Display::ShowStockError()
{
    ShowTitle("COTIZAR: REVICION");
    ShowBackMenu(false);
    cout << "-------------------------------------------------------------------" << endl;
    cout << "ERROR: Stock no disponible o insuficiente" << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;
    cout << "Ingrese cualquier letra cualquier tecla para volver al menu: ";
}

void Display::ShowContinueMenu(string message)
{
    ShowTitle("COTIZAR: REVICION");
    ShowBackMenu(true);
    cout << message << endl;
    cout << "�Desea continuar?" << endl;
    cout << "1) Si" << endl;
    cout << "2) No" << endl;
    cout << "3) Ver historial" << endl;
    cout << "Ingrese una opcion: ";
}