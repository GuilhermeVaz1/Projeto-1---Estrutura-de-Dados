#include <iostream>
#include <fstream>
#include <sstream>
#include "alunos.h"


int main(void){
    std::string palavra, linha;
    std::ifstream arquivo;
    Aluno a;
    arquivo.open("C:/Users/guisn/Documents/Cesupa Git/Estrutura-de-Dados/Projeto-1---Estrutura-de-Dados/alunos.csv", std::ios::in);
    getline(arquivo, linha);
    while(getline(arquivo, linha)){
        std::stringstream str (linha);
        getline(str, palavra, ',');
        a.set_nome(palavra);
        getline(str, palavra, ',');
        a.set_matricula(std::stoi(palavra));
        getline(str, palavra, ',');
        a.set_aval1(std::stof(palavra));
        getline(str, palavra, ',');
        a.set_aval2(std::stof(palavra));
        a.print();
    }
    arquivo.close();
    return 0;
}