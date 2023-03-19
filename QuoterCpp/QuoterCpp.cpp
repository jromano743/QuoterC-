#include <iostream>
#include <string.h>
#include "Presenter.h"

using namespace std;

int main()
{
    Presenter* presenter = new Presenter();
    presenter->PrintMenu();
    return 0;
}