#pragma once


void jugar(int setDados, int modoJuego, int puntajeRanking[],string nombresRanking[]);

void jugar(int setDados, int modoJuego, int puntajeRanking[],string nombresRanking[])
{
    const int cantDados = setDados;
    bool modoPrueba, empate;
    int dados[cantDados], puntajeJugador[2]= {},acumPuntos=0, ronda=0, tiradas=0, mayorPuntaje=0, ganador=0;
    string nombreJugador[2];


    ///pide nombres para j1 y j2 o entra en modo prueba
    if (modoJuego==3)
    {
        modoPrueba=true;
    }else
    {
        modoPrueba=false;
    }

    if (modoJuego!=2)
    {
        pedirNombres(nombreJugador, 1);
        nombreJugador[1]=nombreJugador[0]; ///el modo un jugador/prueba usa en los dos indices del vector los mismos valores
    }
    else
    {
        pedirNombres(nombreJugador, 2);
    }

    while ((puntajeJugador[0]<100 && puntajeJugador[1]<100) || (modoJuego==2 && ronda%2==1)) ///empieza el juego
    {
        tiradas=0;
        mayorPuntaje=0;

        if(modoJuego==2 && ronda>=1)///identifica juego 2JJ y fin de ronda 1 para Mostra Cartel Entre Turnos
        {
            if(ronda%2==0)///intercala ronda de ambos JJ
            {
                cartelEntreTurnos(ronda,puntajeJugador,nombreJugador);
            }
        }
            while (tiradas <3)  ///empieza ronda de 3 tiradas
        {
            system("cls");
            tiradas++;
            cartelTirada(nombreJugador, puntajeJugador, ronda, mayorPuntaje, modoJuego, tiradas); ///stats

            if (modoPrueba)
            {
                for (int x=0; x<cantDados; x++)
                {
                    cout << "Dados: ";
                    cin >> dados[x];
                }

            }
            else
            {
                cout << "INTENTO Nro "<<tiradas<<endl;
                tirada(dados, cantDados);
//               for (int x=0; x<cantDados; x++)  ///si es necesario un modo prueba con 2 jugadores
//                {
//                    cout << "Dados: ";
//                    cin >> dados[x];
//                }

                calcularPuntos(dados, cantDados);
            }

            if (calcularPuntos(dados, cantDados)==-1)
            {
                acumPuntos=0;
                if (modoJuego!=2)
                {
                    puntajeJugador[0]=puntajeJugador[1]=0;
                }
                else
                {
                    puntajeJugador[ronda%2]=0;
                }

                tiradas=4;//Se pasa de turno para cambiar de Jugador
                cout << "NOOOOO SACASTE 6 x 6 SE RESETEAN TUS PUNTOS A 0 " << endl;
            }
            else if (calcularPuntos(dados, cantDados)==200)
            {
                if (modoJuego!=2)
                {
                    puntajeJugador[0]=puntajeJugador[1]+=calcularPuntos(dados, cantDados);
                }
                else
                {
                    acumPuntos = calcularPuntos(dados, cantDados);
                }
                cout << "SACASTE ESCALERA!!!!!!"<<endl;
                tiradas=4;
            }
            else
            {
                acumPuntos=calcularPuntos(dados, cantDados);
                cout << "BIEN SACASTE "<< calcularPuntos(dados, cantDados)<< " PUNTOS"<< endl;
            }

            if (acumPuntos>=mayorPuntaje)
            {
                mayorPuntaje=acumPuntos;
            }

            system("pause>nul");
            system("cls");
        }///fin de while de ronda
        if (modoJuego!=2)
        {
            puntajeJugador[0]=puntajeJugador[1]+=mayorPuntaje;
        }

        else
        {
            puntajeJugador[ronda%2]+=mayorPuntaje;
        }
        ronda++;
    }///fin de while de partida
    entraAlRanking(modoJuego,puntajeJugador,puntajeRanking,nombreJugador,nombresRanking); /// compara el puntaje de la jugada con el ranking


    if (modoJuego==2)
    {
        empate = esEmpate(puntajeJugador);
        if(empate==true)
        {
            ganador = dadoDeOro(nombreJugador);
        }
        else if (puntajeJugador[0]>puntajeJugador[1])
        {
            ganador=0;
        }
        else
        {
            ganador=1;
        }
        cartelGanador2(ronda,ganador,puntajeJugador,nombreJugador);
    }else
    {
        cartelGanador1(ronda, ganador, puntajeJugador, nombreJugador);

    }
}

