#pragma once
void ordenarTirada (int v[], int tam);
void tirada (int vectorDados[], int tam);
int calcularPuntos (int v[], int tam);
bool esEmpate(int vectorPuntaje[]);
void entraAlRanking(int modoJuego, int puntajeJugador[],int puntajeRanking[],string nombreJugador[],string nombresRanking[]);
void ordenarRanking(int vecPuntos[], string vecNombres[]);
int contarPuntosExtras(int vec[], int tam);
void escaleraAlCielo();
void escaleraAlInfierno();




//***********************************************************************
void ordenarTirada(int v[], int tam)
{
    int aux, mayor, posicion;
    /// considerar un nuevo ultimo
    for (int x=tam-1; x>0; x--)
    {
        /// tomar el elemento mas grande
        aux=v[x];
        mayor=v[x];
        posicion=x;
        for (int i=0; i<x; i++)
        {
            if (v[i]>mayor)
            {
                mayor=v[i];
                posicion=i;
            }
        }
        /// llevarlo al final
        v[x]=mayor;
        v[posicion]=aux;
    }
}
//***********************************************************************
///define valores de los dados y muestra los valores
void tirada (int vectorDados[], int tam)
{
//    colores
//
//	0 BLACK
//	1 BLUE
//	2 GREEN
//	3 CYAN
//	4 RED
//	5 MAGENTA
//	6 BROWN
//	7 GREY
//	8 DARKGREY
//	9 LIGHTBLUE
//	10 LIGHTGREEN
//	11 LIGHTCYAN
//	12 LIGHTRED
//	13 LIGHTMAGENTA
//	14 YELLOW
//	15 WHITE

    int posicionAct[2] = {1, 13};
    int colorDados[2]= {3,15};
    for (int i=0; i<tam; i++)
    {
        vectorDados[i]=rand()%6 + 1;
    }

    for (int i=0; i<tam; i++)
    {
        dibujarDado(vectorDados[i], colorDados, posicionAct);
        posicionAct[0]+=10;
    }
    cout << endl << endl;
}



//***********************************************************************
int calcularPuntos (int v[], int tam)
{
    /// escalera = 200
    ordenarTirada(v, tam);
    int contadorEscalera=0;
    for (int i=0; i<tam; i++)
    {
        if (v[i]==i+1)
        {
            contadorEscalera++;
        }
    }

    if (contadorEscalera==tam)
    {
        return 200;
    }

    /// 6 x 6 = reseteo (usa marca de -1)
    /// iguales x6 = num * 10
    bool iguales=true;
    int anterior=v[0];
    for(int i=1; i<tam; i++)
    {
        if(v[i]==anterior)
        {
            anterior=v[i];
        }
        else
        {
            iguales=false;
        }
    }
    if(iguales)
    {
        if(v[0]==6)
        {
            return -1;
        }
        else
        {
            return (v[0]*10);
        }
    }

    /// varios = suma v[0]..v[5]
    int  sumaElementos=0;
    for (int i=0; i<tam; i++)
    {
        sumaElementos+=v[i];
    }
    return sumaElementos;
}
//****************************************************************************
int contarPuntosExtras(int vec[], int tam)
{
    int  acumulador=0;
    for(int x=0; x<tam; x++)
    {

        acumulador+=vec[x];
    }

    return acumulador;

}



//**************************************************************
bool esEmpate (int vectorPuntaje[])
{
    int diferencia;

    if (vectorPuntaje[0]== vectorPuntaje[1])
    {
        return true;
    }
    else if((vectorPuntaje[0]>=100 && vectorPuntaje[1]>=100) && vectorPuntaje[0] > vectorPuntaje[1])
    {
        diferencia = vectorPuntaje[0] - vectorPuntaje[1];

    }
    else if ((vectorPuntaje[0]>=100 && vectorPuntaje[1]>=100)&& vectorPuntaje[1]>vectorPuntaje[0])
    {
        diferencia = vectorPuntaje[1]- vectorPuntaje[0];
    }

    if(diferencia<=5)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//*************************************************************************
void entraAlRanking(int modoJuego, int puntajeJugador[],int puntajeRanking[],string nombreJugador[],string nombresRanking[])
{
    if (modoJuego==1)
    {
        if(puntajeJugador[0]>puntajeRanking[4])
        {
            puntajeRanking[4]=puntajeJugador[0];
            nombresRanking[4]=nombreJugador[0];
        }
        ordenarRanking(puntajeRanking,nombresRanking);

    }
    else if (modoJuego==2)
    {
        if(puntajeJugador[0]>puntajeRanking[4])
        {
            puntajeRanking[4]=puntajeJugador[0];
            nombresRanking[4]=nombreJugador[0];
        }
        ordenarRanking(puntajeRanking,nombresRanking);

        if(puntajeJugador[1]>puntajeRanking[4])
        {
            puntajeRanking[4]=puntajeJugador[1];
            nombresRanking[4]=nombreJugador[1];

        }

        ordenarRanking(puntajeRanking,nombresRanking);

    }
}

//*************************************************************************
void ordenarRanking(int vecPuntos[], string vecNombres[])
{
    for(int i=0; i<4; i++)
    {
        int maxPos = i;
        for(int j=i+1; j<5; j++)
        {
            if(vecPuntos[j] > vecPuntos [maxPos])
            {
                maxPos = j;
            }
        }
        int puntosAux = vecPuntos [maxPos];
        vecPuntos [maxPos] = vecPuntos[i];
        vecPuntos[i] = puntosAux;
        string nombreAux = vecNombres [maxPos];
        vecNombres [maxPos] = vecNombres[i];
        vecNombres[i] = nombreAux;
    }
}


//******************************************************************************
int dadoDeOro(string nombreJugador[])
{
    int tiradaJugador1=0,tiradaJugador2=0;
    cartelDadoDeOro();
    while(tiradaJugador1==tiradaJugador2)
    {
        int colorDado[2]={14, 0};
        int posicion[2]={10, 5};

        cout<<"                       TURNO DE: "<< nombreJugador[0]<<endl;
        tiradaJugador1 =rand()%6 + 1;

        dibujarDadoDeOro(tiradaJugador1);

        system("pause>nul");
        system("cls");

        cout<<"                       TURNO DE: "<< nombreJugador[1]<<endl;
        tiradaJugador2=rand()%6 + 1;

        dibujarDadoDeOro(tiradaJugador2);
        system("pause>nul");
        system("cls");
    }
    if(tiradaJugador1>tiradaJugador2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//*************************************************************************

void  escaleraAlCielo()

{
    string nombres[2];
    int dados[6] {};
    int puntaje[2] {};
    pedirNombres(nombres,2);
    for(int x=1; x<=5; x++)
    {
        cout<<"          TIRADA DEL JUGADOR ==> "<< nombres[0]<< endl;

        tirada(dados,x);

        puntaje[0]+=contarPuntosExtras(dados,x);
        cout<<"**** Puntaje Acumulado: "<< puntaje[0]<< endl;

        system("pause>nul");
        system("cls");

        cout<<"          TIRADA DEL JUGADOR ==> "<< nombres[1]<< endl;
        tirada(dados,x);
        puntaje[1]+=contarPuntosExtras(dados,x);
        cout<<"**** Puntaje Acumulado: "<< puntaje[1]<< endl;

        system("pause>nul");
        system("cls");


    }

    if ( puntaje[0]==puntaje[1])
    {

        cout<<"          EL GANADOR ES: ==> "<< nombres[dadoDeOro(nombres)];
    }

    else
    {
        if(puntaje[0]>puntaje[1])
        {

            cout<<"          EL GANADOR ES: ==> "<< nombres[0]<< endl;
            cout<<"          con "<<puntaje[0]<<" puntos..."<<endl;
        }
        else
        {

            cout<<"          EL GANADOR ES: ==> "<< nombres[1]<< endl;
            cout<<"          con "<<puntaje[1]<<" puntos..."<<endl;

        }
    }
}
//**************************************************************************
void escaleraAlInfierno()

{
    string nombres[2];
    int dados[6] {};
    int puntaje[2] {100,100};
    pedirNombres(nombres,2);
    for(int x=6; x>=1; x--)
    {
        cout<<"          TIRADA DEL JUGADOR ==> "<< nombres[0]<< endl;

        tirada(dados,x);

        puntaje[0]-=contarPuntosExtras(dados,x);
        cout<<"**** Puntaje Acumulado: "<< puntaje[0]<< endl;

        system("pause>nul");
        system("cls");

        cout<<"          TIRADA DEL JUGADOR ==> "<< nombres[1]<< endl;
        tirada(dados,x);
        puntaje[1]-=contarPuntosExtras(dados,x);
        cout<<"**** Puntaje Acumulado: "<< puntaje[1]<< endl;

        system("pause>nul");
        system("cls");


    }

    if ( puntaje[0]==puntaje[1])
    {

        cout<<"          EL GANADOR ES: ==> "<< nombres[dadoDeOro(nombres)];
    }

    else
    {
        if(puntaje[0]<puntaje[1])
        {

            cout<<"          EL GANADOR ES: ==> "<< nombres[0]<< endl;
            cout<<"          con "<<puntaje[0]<<" puntos..."<<endl;
        }
        else
        {

            cout<<"          EL GANADOR ES: ==> "<< nombres[1]<< endl;
            cout<<"          con "<<puntaje[1]<<" puntos..."<<endl;

        }
    }

}



