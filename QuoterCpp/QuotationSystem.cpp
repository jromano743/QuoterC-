#include "QuotationSystem.h"

QuotationSystem::QuotationSystem()
{
    cout << "Iniciando sistema..." << endl;
}

void QuotationSystem::InitializeData()
{
    store = new Store("TIENDA01", "Star Clothe", "Wall C 123");
    seller = new Seller("VENDEDOR01", "Mica", "Chamut", store);

    store->AddClothes(new Shirt("CAMISA_01", "Standard", 100, "Manga corta", "Cuello mao"));
    store->AddClothes(new Shirt("CAMISA_02", "Premium", 100, "Manga corta", "Cuello mao"));
    store->AddClothes(new Shirt("CAMISA_03", "Standard", 150, "Manga corta", "Cuello comun"));
    store->AddClothes(new Shirt("CAMISA_04", "Premium", 150, "Manga corta", "Cuello comun"));
    store->AddClothes(new Shirt("CAMISA_05", "Standard", 75, "Manga larga", "Cuello mao"));
    store->AddClothes(new Shirt("CAMISA_06", "Premium", 75, "Manga larga", "Cuello mao"));
    store->AddClothes(new Shirt("CAMISA_07", "Standard", 175, "Manga larga", "Cuello comun"));
    store->AddClothes(new Shirt("CAMISA_08", "Premium", 175, "Manga larga", "Cuello comun"));

    store->AddClothes(new Pants("PANTALON_01", "Standard", 750, "Chupin"));
    store->AddClothes(new Pants("PANTALON_02", "Premium", 750, "Chupin"));
    store->AddClothes(new Pants("PANTALON_03", "Standard", 250, "Comun"));
    store->AddClothes(new Pants("PANTALON_04", "Premium", 250, "Comun"));
};

Quotation* QuotationSystem::AddQuotation(int id, Clothe* clothes, float unitPrice, int quantity)
{
    if (clothes->GetStock() < quantity)
    {
        return NULL;
    }
    Quotation* quotation = new Quotation(id, seller, clothes, unitPrice, quantity);
    clothes->RemoveStock(quantity);
    quotationList.push_back(quotation);
    return quotation;
};