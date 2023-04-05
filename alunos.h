#include <iostream>
#include <string>
#include <iomanip>

class Aluno{
private:
    std::string nome;
    int matricula;
    float aval1;
    float aval2;

public:
    //Constructor generico

    Aluno(){
        this->nome = " ";
        this->matricula = 0;
        this->aval1 = 0.0;
        this->aval2 = 0.0;
    }

    //Constructor

    Aluno(std::string n, int m, float a1, float a2){
        this->nome = n;
        this->matricula = m;
        this->aval1 = a1;
        this->aval2 = a2;
    }

    Aluno(std::string n, std::string m, std::string a1, std::string a2){
        this->nome = n;
        this->matricula = std::stoi(m);
        this->aval1 = std::stof(a1);
        this->aval2 = std::stof(a2);
    }

    //Destructor

    ~Aluno(){
    }

    //Getters

    std::string get_nome(){
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

    void set_nome(std::string n){
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

    //Functions

    float calc_media(){
        return (this->aval1 + this->aval2)/2.0;
    }

    bool aprova(){
        return (this->calc_media() >= 7.0);
    }

    //Print

    void print(){
        std::cout << "Nome: " << std::left << std::setw(20) << this->nome << std::setw(0) << " | ";
        std::cout << "Matricula: " << this->matricula << " | ";
        std::cout.precision(2);
        std::cout << "Media: " << std::fixed << this->calc_media() << " | ";
        if(this->aprova()){
            std::cout << "Aprovado" << std::endl;
        }else{
            std::cout << "Reprovado" << std::endl;
        }
    }

};
