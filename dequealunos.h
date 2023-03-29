#include <string>
using namespace std;

class Aluno{
private:
    string nome;
    int matricula;
    float aval1;
    float aval2;
    float media;
    bool aprovado;

public:
    Aluno(string n){
        this->nome = n;
    }

    ~Aluno(){
        delete this;
    }

};

class Deque_Alunos{
private:
    Aluno* head;
    Aluno* tail;

public:
    Deque_Alunos(){
        this->head = NULL;
        this->tail = NULL;
    }

    ~Deque_Alunos(){
        delete this;
    }
};