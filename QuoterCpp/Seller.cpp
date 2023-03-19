#include "Seller.h"

Seller::Seller(string code, string name, string lastname, Store* store)
{
    this->code = code;
    this->name = name;
    this->lastname = lastname;
    this->store = store;
};