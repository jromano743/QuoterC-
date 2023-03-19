#include "Store.h"

Store::Store(string code, string name, string address)
{
    this->code = code;
    this->name = name;
    this->address = address;
};

void Store::AddClothes(Clothe* clothes)
{
    clothesList.push_back(clothes);
}

Clothe* Store::FindClothe(string quality, string sleeveType, string collarType, string cutType)
{
    for (int i = 0; i < clothesList.size(); i++)
    {
        if (clothesList[i]->IsEquals(quality, sleeveType, collarType, cutType))
            return clothesList[i];
    }
    return clothesList[0];
}