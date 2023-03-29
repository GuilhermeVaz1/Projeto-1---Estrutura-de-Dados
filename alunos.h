#include <iostream>
#include <string>
using namespace std;

class Aluno{
private:
    string nome;
    int matricula;
    float aval1;
    float aval2;

public:

    //Constructor generico

    Aluno(){
        this->nome = "";
        this->matricula = 2023999;
        this->aval1 = 0.0;
        this->aval2 = 0.0;
    }

    //Constructor

    Aluno(string n, int m, float a1, float a2){
        this->nome = n;
        this->matricula = m;
        this->aval1 = a1;
        this->aval2 = a2;
    }

    //Destructor

    ~Aluno(){
        delete this;
    }

    //Getters

    string get_nome(){
        return this->nome;
    }

    int get_matricula(){
        return this->matricula;
    }

    float get_aval1(){
        return this->aval1;
    }

    float get_aval2(){
        return this->aval2;
    }

    //Setters

    void set_nome(string n){
        this->nome = n;
    }

    void set_matricula(int m){
        this->matricula = m;
    }

    void set_aval1(float a1){
        this->aval1 = a1;
    }

    void set_aval2(float a2){
        this->aval2 = a2;
    }

    //Print

    void print(){
        cout << "Nome: " << this->nome << " | ";
        cout << "Matricula: "; //<------- Format this
    }

};
