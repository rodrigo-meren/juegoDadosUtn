#pragma once

void pedirNombres(string nombres[], int cantidadJugadores);
void cartelDespedida();// muestra un cartel de despedida
void cartelTirada(string nombreJugador[], int puntajeJugador[], int ronda, int mayorPuntaje, int modoJuego, int tiradas);
void cartelEntreTurnos(int ronda,int puntajeJugador[],string nombreJugador[]);
void cartelGanador1(int rondas,int ganador, int puntajeJugador[],string nombreJugador[]);
void cartelGanador2(int rondas,int ganador, int puntajeJugador[],string nombreJugador[]);
void cartelGanadorDadoDeOro(string nombres[], int ganador);
void mostrarMenu();
void cartelExtras();
void mostrarPuntajes(int vecPuntos[], string vecNombres[]);
void cartelDadoDeOro();
void reglas();
void reglasExtras();
void dibujarDado(int numDados, int colorDado[], int posicionXY[]);
void dibujarDadoDeOro(int numDados);

void pedirNombres(string nombres[], int cantidadJugadores)
{
    for (int i=0; i<cantidadJugadores; i++)
    {
        rlutil::locate(20, 2);
        cout << "INGRESE EL NOMBRE DEL JUGADOR: "<<i+1<< endl;
        rlutil::locate(20, 3);
        if (i==0)
        {
            rlutil::locate(20, 3);
            cin.ignore();
            getline(cin, nombres[i]);
        }
        else
        {
            rlutil::locate(20, 3);
            getline(cin, nombres[i]);
        }

        system("cls");

    }
}
void cartelTirada(string nombreJugador[], int puntajeJugador[], int ronda, int mayorPuntaje, int modoJuego, int tiradas)
{
    int estaRonda;
    if(modoJuego==1 || modoJuego==3)//para que te modifique el nro de ronda
    {
        estaRonda = ronda + 1;//a 1 Jdor   //
    }
    else
    {
        estaRonda = ronda/2 + 1;// para que muestre el turno
    }
    cout << "TURNO DE " << nombreJugador[ronda%2] << " |  RONDA Nro " << estaRonda << "  |  PUNTAJE TOTAL: " << puntajeJugador[ronda%2] << " PUNTOS" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << mayorPuntaje << " PUNTOS" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl << endl;
}

void cartelEntreTurnos(int ronda,int puntajeJugador[],string nombreJugador[])
{


    cout << "                               ----------------------------------------------------------" << endl;
    cout << "                                                RONDA Nro " << ronda/2+1 << endl;
    cout << "                                                PROXIMO TURNO: " << nombreJugador[0] << endl;
    cout << endl;
    cout << "                                                PUNTAJE " << nombreJugador[0] << " : " << puntajeJugador[0] << " PUNTOS" << endl;
    cout << "                                                PUNTAJE " << nombreJugador[1] << " : " << puntajeJugador[1] << " PUNTOS" << endl;
    cout << "                               ----------------------------------------------------------" << endl;
    system("pause>nul");

}

void cartelGanador1(int rondas,int ganador, int puntajeJugador[],string nombreJugador[])
{
    system("cls");
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< endl;
    cout << "                                                                                       " << endl;
    cout << "                                                     FIN DEL JUEGO                     " << endl;
    cout << "                                                                                       " << endl;
    cout << "                                             GANADOR: " <<nombreJugador[ganador]<< endl;
    cout << "                                             PUNTAJE: " <<puntajeJugador[ganador]<< endl;
    cout << "                                             CANTIDAD DE RONDAS: "<<rondas<< endl;
    cout << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void cartelGanador2(int rondas,int ganador, int puntajeJugador[],string nombreJugador[])
{
    system("cls");
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< endl;
    cout << "                                                                                       " << endl;
    cout << "                                                                                       " << endl;
    cout << "                                                     FIN DEL JUEGO                     " << endl;
    cout << "                                                                                       " << endl;
    cout << "                                       ===>  "<<nombreJugador[0]<< ": " <<puntajeJugador[0]<< endl;
    cout << "                                       ===>  "<<nombreJugador[1]<< ": " <<puntajeJugador[1]<< endl;
    cout << "                                                                                       " << endl;
    cout << "                                             GANADOR: "    <<nombreJugador[ganador]<< endl;
    cout << "                                             PUNTAJE: " <<puntajeJugador[ganador]<< endl;
    cout << "                                             CANTIDAD DE RONDAS: "<<rondas/2<< endl;
    cout << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

}


void cartelGanadorDadoDeOro(string nombreJugador[], int ganador)
{
    system("cls");
    rlutil::setColor(14);
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< endl;
    cout << "                                                                                       " << endl;
    cout << "                                                                                       " << endl;
    cout << "                                                     FIN DEL JUEGO                     " << endl;

    cout << "                                                     GANADOR: "    <<nombreJugador[ganador]<< endl;

    cout << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    rlutil::setColor(15);
}


void mostrarMenu()
{
    system("cls");
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                               +                 1- NUEVO JUEGO UN JUGADOR              +" << endl;
    cout << "                               +                 2- NUEVO JUEGO 2 JUGADORES             +" << endl;
    cout << "                               +                 3- MODO PRUEBA                         +" << endl;
    cout << "                               +                 4- RANKING DE PUNTOS                   +" << endl;
    cout << "                               +                 5- EXTRAS                              +" << endl;
    cout << "                               +                 6- REGLAS DEL JUEGO                    +" << endl;
    cout << "                               +                 0- SALIR                               +" << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;

}

void cartelExtras()
{

    cout << "                                                       EXTRAS                            " << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                               +                 1- DADO DE ORO                         +" << endl;
    cout << "                               +                 2- ESCALERA AL CIELO                   +" << endl;
    cout << "                               +                 3- ESCALERA AL INFIERNO                +" << endl;
    cout << "                               +                 4- REGLAMENTO                          +" << endl;
    cout << "                               +                 0- SALIR                               +" << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

}
void cartelDadoDeOro()
{
    rlutil::setColor(14);

    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                        DADO DE ORO                     +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    system("pause>nul");
    system("cls");
    rlutil::setColor(15);

}

void mostrarPuntajes(int vecPuntos[], string vecNombres[])
{
    cout << "---- RANKING" << endl;
    for(int i = 0 ; i<5; i++)
    {
        cout << "#"<<i+1<< " " << vecNombres [i] << " " << vecPuntos[i] << endl;
    }
}

void cartelDespedida()
{
    for (int i=0; i<20; i++)
    {
    rlutil::setColor(rand()%15+1);
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                      FIN DEL JUEGO                     +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                 MUCHAS GRACIAS POR JUGAR               +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +          CREADO POR EL GRUPO 64 PROGRAMACION 1         +" << endl;
    cout << "                               +                        UTN FRGP                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                     RODRIGO MEREN                      +" << endl;
    cout << "                               +                   VALENTINA ESPOSITO                   +" << endl;
    cout << "                               +                    MARIANO MARASCO                     +" << endl;
    cout << "                               +                     FRANCO CUELLO                      +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                Made with rlutil by TAPIO               +" << endl;
    cout << "                               +             https://github.com/tapio/rlutil            +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    rlutil::msleep(20);
        if (i<19)
        {
            system("cls");
        }
    }
    rlutil::setColor(15);
}

void cartelComienzo()
{
    for (int i=0; i<20; i++)
    {
    rlutil::setColor(rand()%15+1);
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                      BIENVENIDOS!!!!                   +" << endl;
    cout << "                               +                           a                            +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                          100                           +" << endl;
    cout << "                               +                           o                            +" << endl;
    cout << "                               +                        ESCALERA                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               +                     FRANCO CUELLO                      +" << endl;
    cout << "                               +                   VALENTINA ESPOSITO                   +" << endl;
    cout << "                               +                    MARIANO MARASCO                     +" << endl;
    cout << "                               +                     RODRIGO MEREN                      +" << endl;
    cout << "                               +                                                        +" << endl;
    cout << "                               ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    rlutil::msleep(20);
        if (i<19)
        {
            system("cls");
        }
    }
    rlutil::setColor(15);
    system("pause>Presione cualquier tecla para jugar");
}



void reglas()
{
    cout << "     REGLAMENTO DEL JUEGO      "<<endl;
    cout << "           "<<endl;
    cout << "     OBJETIVO      "<<endl;
    cout << "     El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible       "<<endl;
    cout << "     de rondas, o sacar una escalera en un lanzamiento.       "<<endl;
    cout << "           "<<endl;
    cout << "     RONDA      "<<endl;
    cout << "     Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados       "<<endl;
    cout << "     y evaluar sus valores para determinar el puntaje.      "<<endl;
    cout << "           "<<endl;
    cout << "     PUNTAJE      "<<endl;
    cout << "     El puntaje de un lanzamiento esta determinado por una serie de reglas       "<<endl;
    cout << "     que figuran a continuacion:      "<<endl;
    cout << "           "<<endl;
    cout << "     Menos de 6 dados con valores iguales       "<<endl;
    cout << "     Ejemplo: 6,5,5,2,2,1	      "<<endl;
    cout << "     Suma de dados      "<<endl;
    cout << "           "<<endl;
    cout << "     6 DADOS IGUALES (menos para el numero 6)       "<<endl;
    cout << "     valor del dado x 10 puntos      "<<endl;
    cout << "           "<<endl;
    cout << "     ESCALERA      "<<endl;
    cout << "     (1, 2, 3, 4, 5, 6) - En cualquier orden      "<<endl;
    cout << "     Gana la partida en esa ronda      "<<endl;
    cout << "      "<<endl;
    cout << "     SEIS 6      "<<endl;
    cout << "     Resetea el puntaje total a 0      "<<endl;
    cout << "           "<<endl;
    cout << "     El puntaje final de la ronda sera el valor maximo de los puntos obtenidos en los 3 lanzamientos       "<<endl;
    cout << "     (no la suma de los tres, sino el mas alto), con las siguientes excepciones:      "<<endl;
    cout << "               "<<endl;
    cout << "     *	Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento      "<<endl;
    cout << "           "<<endl;
    cout << "     *	Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6,       "<<endl;
    cout << "         el puntaje total de la persona se resetea a 0.       "<<endl;
    cout << "           "<<endl;
    cout << "     EMPATE      "<<endl;
    cout << "     -Si el jugador numero 1 llega a 100 puntos o mas, o realiza una escalera, El jugador 2 tiene "       <<endl;
    cout << "      la posibilidad de empatar en el mismo turno, alcanzando el puntaje         "<<endl;
    cout << "      o haciendo una escalera segun corresponda.     "<<endl;
    cout << "           "<<endl;
    cout << "     -En el caso que ambos jugadores pasen los 100 puntos en el mismo turno tienen        "<<endl;
    cout << "      un margen de 10 puntos de diferencia para conciderarse empate.       "<<endl;
    cout << "           "<<endl;
    cout << "     -El desempates se hace en todos los casos mediante el lanzamiento del dado de oro.(ver en reglamento de extras)       "<<endl;
    cout << "           "<<endl;
    system("pause>nul");

}
void reglasExtras()
{
    cout << "     REGLAMENTO DE LOS JUEGOS EXTRAS      "<<endl;
    cout << "           "<<endl;
    cout << "     DADO DE ORO.      "<<endl;
    cout << "     Se juega una unica mano, lanzando un dado cada jugador el que obtiene el mayor puntaje es el ganador       "<<endl;
    cout << "           "<<endl;
    cout << "     ESCALERA AL CIELO.      "<<endl;
    cout << "     El objetivo de este mini juego es obtener el mayor puntaje, cada jugador arranca lanzando un dado y  "<<endl;
    cout << "     en cada ronda se va sumando otro dado, asi hasta llegar a lanzar 6 dados cada uno,  "<<endl;
    cout << "     el que mayor puntaje obtiene es el ganador. En caso de empate se lanza el dado de oro.      "<<endl;
    cout << "           "<<endl;

    cout << "     ESCALERA AL INFIERNO.      "<<endl;
    cout << "     El objetivo de este mini juego es obtener el menor puntaje posible, cada jugador arranca con 100 puntos,"<<endl;
    cout<<  "     lanza seis dados y en cada ronda se va restando un dado, asi hasta llegar a lanzar 1 dado cada uno."<<endl;
    cout << "     El que menor puntaje obtiene es el ganador.      "<<endl;
    cout << "     en caso de empate se lanza el dado de oro.      "<<endl;

    cout << "           "<<endl;
    system("pause>nul");

}

void dibujarDado(int numDados, int colorDado[], int posicionXY[]) ///colorDado[0]=cuerpo, colorDado[1]=puntos
{
    // int numDados = 2;///numero de dado a dibujar

    ///seteo de variables que modifican color y posicion original.
//    int colorDado[2] = {4, 0};
//    int posicionXY[2]={4,4};

    bool aleatorio=rand()%2;

    switch(numDados)
    {
    case 1:
        rlutil::setColor(colorDado[0]);
        for (int x=0; x<3; x++)
        {
            rlutil::locate (posicionXY[0], posicionXY[1]+x);
            for (int i=0; i<7; i++)
            {
                cout << (char)219;
            }
        }
        rlutil::setColor(colorDado[1]);
        rlutil::setBackgroundColor(colorDado[0]);
        rlutil::locate(posicionXY[0]+3,posicionXY[1]+1);
        cout << (char)254;
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posicionXY[0]+7, posicionXY[1]+2);


        break;
    case 2:
        if (aleatorio)
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+1,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+5,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }

        break;
    case 3:
        if (aleatorio)
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+3,posicionXY[1]+1);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+3,posicionXY[1]+1);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }

        break;
    case 4:

        rlutil::setColor(colorDado[0]);
        for (int x=0; x<3; x++)
        {
            rlutil::locate (posicionXY[0], posicionXY[1]+x);
            for (int i=0; i<7; i++)
            {
                cout << (char)219;
            }
        }
        rlutil::setColor(colorDado[1]);
        rlutil::setBackgroundColor(colorDado[0]);

        rlutil::locate(posicionXY[0]+1,posicionXY[1]);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+5,posicionXY[1]);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
        cout << (char)254;


        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);

        break;
    case 5:

        rlutil::setColor(colorDado[0]);
        for (int x=0; x<3; x++)
        {
            rlutil::locate (posicionXY[0], posicionXY[1]+x);
            for (int i=0; i<7; i++)
            {
                cout << (char)219;
            }
        }
        rlutil::setColor(colorDado[1]);
        rlutil::setBackgroundColor(colorDado[0]);

        rlutil::locate(posicionXY[0]+3,posicionXY[1]+1);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+1,posicionXY[1]);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+5,posicionXY[1]);
        cout << (char)254;
        rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
        cout << (char)254;


        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);

        break;
    case 6:
        if (aleatorio)
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+1,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+3,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+3,posicionXY[1]+2);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setColor(colorDado[0]);
            for (int x=0; x<3; x++)
            {
                rlutil::locate (posicionXY[0], posicionXY[1]+x);
                for (int i=0; i<7; i++)
                {
                    cout << (char)219;
                }
            }
            rlutil::setColor(colorDado[1]);
            rlutil::setBackgroundColor(colorDado[0]);

            rlutil::locate(posicionXY[0]+1,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]+1);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+1,posicionXY[1]+2);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]+1);
            cout << (char)254;
            rlutil::locate(posicionXY[0]+5,posicionXY[1]+2);
            cout << (char)254;

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }
        break;
    }
}

void dibujarDadoDeOro(int numDados)
{
    bool aleatorio=rand()%2;
    int posicionXY[2]={30, 5};

    switch(numDados)
    {
        case 1:
            rlutil::setColor(14);
            rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+6, posicionXY[1]+3);
            cout << (char)32 << (char)32;


            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 2:

        rlutil::setColor(14);
        rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+1);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+10, posicionXY[1]+5);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 3:

        rlutil::setColor(14);
        rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+6, posicionXY[1]+3);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+2, posicionXY[1]+1);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+10, posicionXY[1]+5);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 4:

        rlutil::setColor(14);
        rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+5);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+5);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 5:

        rlutil::setColor(14);
        rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+6, posicionXY[1]+3);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+5);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+5);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 6:

        rlutil::setColor(14);
        rlutil::locate(posicionXY[0], posicionXY[1]);

            for (int i=0; i<8; i++)
            {
                for (int x=0; x<14; x++)
                {
                    cout << (char)219;
                }
                rlutil::locate (posicionXY[0], posicionXY[1]+i);
            }
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+3);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+2, posicionXY[1]+5);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+1);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+3);
            cout << (char)32 << (char)32;
            rlutil::locate(posicionXY[0]+10, posicionXY[1]+5);
            cout << (char)32 << (char)32;

            rlutil::locate(posicionXY[0]+12, posicionXY[1]+10);

            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    }
}
