#pragma once


void menu();

void menuExtras();

void menu()
{
    int puntajeRanking[5]= {100, 100, 100, 100, 99};
    string nombreRanking[5]= {"Rodrigo", "Valentina", "Mariano", "Franco", "Varo Mafra"};

    int opcion;

    while (true)
    {
        mostrarMenu();

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            jugar(6, 1, puntajeRanking, nombreRanking);

            system("pause>nul");
            system("cls");
            break;
        case 2:
            jugar(6, 2, puntajeRanking, nombreRanking);

            system("pause>nul");
            system("cls");
            break;
        case 3:
            jugar(6, 3, puntajeRanking, nombreRanking);

            system("pause>nul");
            system("cls");

            break;
        case 4:
            mostrarPuntajes(puntajeRanking, nombreRanking);

            system("pause>nul");
            system("cls");
            break;
        case 5:
            menuExtras();

            system("cls");
            break;
        case 6:
            reglas();

            system("cls");
            break;

        case 0:

            return;
            break;
        }
    }
}


void menuExtras()
{
    string jugadores[2] {};
    int ganador,opcion;

    while (true)
    {
        cartelExtras();

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            pedirNombres(jugadores,2);
            ganador = dadoDeOro(jugadores);

            cartelGanadorDadoDeOro(jugadores, ganador);
//            if(ganador==0)
//            {
//                cout<<"El Ganadador es el jugador "<< jugadores[0]<<endl;
//            }
//            else
//            {
//                cout<<"El Ganadador es el jugador "<< jugadores[1]<<endl;
//            }

            system("pause>nul");
            system("cls");
            break;
        case 2:
            escaleraAlCielo();
            system("pause>nul");
            system("cls");

            break;

        case 3:

            escaleraAlInfierno();

            system("pause>nul");
            system("cls");


            break;

        case 4:
            reglasExtras();
            system("pause>nul");
            system("cls");
            break;
        case 0:
            return;

        }
    }
}
