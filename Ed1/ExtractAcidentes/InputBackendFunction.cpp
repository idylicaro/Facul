#include "InputBackend.h"

void esvaziaStruct(TInfo &item){
    item.registro.id =0;
    item.registro.cidade = "";
    item.registro.algumacoisa = "";
    item.registro.data = "";
    item.registro.diaDaSemana ="";
    item.registro.hora = "";
    item.registro.tipoAcidente = "";
    item.registro.x8 =0;
    item.registro.x9 = 0;
    item.registro.description ="";
}
void getAtributos(TLista &lista)
{

    ifstream arquivo("acidentes.txt");
    int tam =0;
    if(!arquivo.is_open())
    {
        cout<<"Algo de errado com o arquivo"<<endl;
    }
    else
    {

        string linha;
        //Acidente obj;
        TInfo item;

        while(getline(arquivo,linha))
        {

            //getline(arquivo,linha);
            separaElementos(linha,item);
            InsereFinal(lista,item);
            esvaziaStruct(item);
            cout << "PROCESSANDO..." <<endl;
            cout <<"Concluido :"<<tam++<<endl;

            //cout <<obj.id<<endl;  // para teste
            system("cls");
        }
        cout <<"FORAM PROCESSADOS :"<<tam <<endl;

    }
}

void separaElementos(string linha,TInfo &item)
{
    int y = 0;  // para diferenciar os atributos
    int z = 0; // rodar atribuições referentes a prencher os atributos da struct;
    string temp;
    for(int i=0; i<linha.size(); i++)
    {
        if(linha[i]==';')
        {
            y++;
            temp.clear();
            continue;
        }

        switch(y)
        {
        case 0:
            temp += linha[i];
            item.registro.id = stoi(temp);  // essa função so ta disponivel do c++11
            break;
        case 1:
            item.registro.cidade += linha[i];
            break;
        case 2:
            item.registro.algumacoisa += linha[i];
            break;
        case 3:
            item.registro.data += linha[i];
            break;
        case 4:
            item.registro.diaDaSemana += linha[i];
            break;
        case 5:
            item.registro.hora += linha[i];
            break;
        case 6:
            item.registro.tipoAcidente += linha[i];
            break;
        case 7:
            temp += linha[i];
            item.registro.x8 = stoi(temp);
            break;
        case 8:
            temp += linha[i];
            item.registro.x9 = stoi(temp);
            break;
        case 9:
            item.registro.description += linha[i];
            break;
        default:
            cout <<" Parametro errado!"<<endl;
            system("pause");
        }


    }
}
