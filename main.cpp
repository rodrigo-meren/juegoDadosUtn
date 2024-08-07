#include <iostream>
#include <ctime>
#include "rlutil.h"
using namespace std;

#include "carteles.h"
#include "auxiliares.h"
#include "juego.h"
#include "menu.h"




int main()
{
    srand(time(0));

    cartelComienzo();

    menu();

    cartelDespedida();
    system("pause>nul");

    return 0;
}

