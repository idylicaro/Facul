#ifndef LISTASENCADEADA_H_INCLUDED
#define LISTASENCADEADA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct acidente
{
    int id;
    string cidade;
    string algumacoisa;  //nao especificado por quem disponibilizou o material
    string data;
    string diaDaSemana;
    string hora;
    string tipoAcidente;
    int x8;  //nao especificado por quem disponibilizou o material
    int x9;  //nao especificado por quem disponibilizou o material
    string description;
} Acidente;

typedef struct NodoLista *Apontador;
typedef struct
{
    Acidente registro;
} TInfo;

struct NodoLista
{
    TInfo Item;
    struct NodoLista *Proximo;
};

typedef struct
{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;


bool vazia(TLista lista);
void display(TInfo item);
void criaLista(TLista &Lista);
void InsereInicio(TLista &Lista,TInfo Item);
void RemoveInicio(TLista lista);
void InsereFinal(TLista &lista,TInfo Item);
void Imprime(TLista lista);
void display(TInfo item);
void InserePosicao(TLista lista,int pos,TInfo item);
void RemoveFinal(TLista lista);
void PesquisaRemove(TLista lista,TInfo item);



#endif // LISTASENCADEADA_H_INCLUDED
