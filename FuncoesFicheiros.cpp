#include <iostream>
#include <fstream>
#include "FuncoesFicheiros.h"

using namespace std;

void gravaString(string caminho_ficheiro) {
    string conteudo="";
    cout << "Introduza o conteúdo a gravar : ";
    getline(cin,conteudo);

    fstream ficheiro;
    ficheiro.open(caminho_ficheiro,ifstream::out);
    ficheiro << conteudo;

    ficheiro.close();

}

void imprimePorChar(string caminho_ficheiro) {
    fstream ficheiro;
    ficheiro.open(caminho_ficheiro);

    char c=0;

    while(ficheiro.good()){
        c = ficheiro.get();
        cout << c;
    }
    ficheiro.close();
}

string leLinhaAlinha(string caminho_ficheiro) {
    fstream myFile;
    myFile.open(caminho_ficheiro);
    string line="";
    string conteudo ="";
    while(getline(myFile,line)){
        //cout << line;
        conteudo = conteudo +'\n'+ line;
    }
    return conteudo;
}

string leFormato(string caminho_ficheiro) {
    fstream myFile;
    myFile.open(caminho_ficheiro);
    string nome="";
    int numero = 0;
    float media = 0;
    char ignorar;
    string conteudo = "";
    while(myFile >> nome >> ignorar>>numero>>ignorar>>media){
        cout << "Nome:"<<nome<<" | Média:"<<media<<" | Número:"<<numero<<endl;
        conteudo =  conteudo + nome+";"+ to_string(media)+";"+ to_string(numero)+'\n';
    }
    return conteudo;
}

void gravaFormato(string caminho_ficheiro, string conteudo) {
    string header = "Nome;Media;Numero\n";//"Nome,Media,Numero"+'\n';
    conteudo = header+conteudo;
    fstream myFile;
    myFile.open(caminho_ficheiro, ifstream::out);
    myFile<<conteudo;
    myFile.close();
}
