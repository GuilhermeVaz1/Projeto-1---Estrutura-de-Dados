/*
Estrutura de Dados - Projeto 1
Autor: Guilherme de Souza Nunes Vaz - 23300037
Data: 17/03/2023
*/

#include "alunos.h"

struct Node{
    Aluno data;
    Node* next;
    Node* prev;
};

Node* HEAD = NULL;
Node* TAIL = NULL;

bool dequeIsEmpty(){ // verifica se o deque está vazio
    return (HEAD == NULL && TAIL == NULL);
}

Node* createNode(Aluno data){ // cria e devolva um nó, a partir de um elemento
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToBeginning(Aluno data){
    Node* newNode = createNode(data);
    if(dequeIsEmpty()){
        HEAD = TAIL = newNode;
    }else{
        newNode->next = HEAD;
        HEAD->prev = newNode;
        HEAD = newNode;
    }
}

void addToEnd(Aluno data){
    Node* newNode = createNode(data);
    if(dequeIsEmpty()){
        HEAD = TAIL = newNode;
    }else{
        newNode->prev = TAIL;
        TAIL->next = newNode;
        TAIL = newNode;
    }
}

void removeFromBeginning(){
    using namespace std;
    if(dequeIsEmpty()){
        cout << "Lista vazia!" << endl;
    }else{
        Node* nodeToRemove = HEAD;
        HEAD = HEAD->next;
        HEAD->prev = NULL;
        delete nodeToRemove;
    }
}

void removeFromEnd(){
    using namespace std;
    if(dequeIsEmpty()){
        cout << "Lista vazia!" << endl;
    }else{
        Node* nodeToRemove = TAIL;
        TAIL = TAIL->prev;
        TAIL->next = NULL;
        delete nodeToRemove;
    }
}

void add_aluno(){
    using namespace std;
    cout << "Insira o nome do Aluno: ";
    string nome;
    cin.ignore();
    getline(cin, nome);
    cout << "Insira a matricula do Aluno: ";
    int matricula;
    cin >> matricula;
    float aval1, aval2;
    cout << "Insira a nota 1 do Aluno: ";
    cin >> aval1;
    cout << "Insira a nota 2 do Aluno: ";
    cin >> aval2;
    Aluno novoAluno(nome, matricula, aval1, aval2);
    cout << "Adicionar ao fim - 1 (padrao) ou inicio - 2" << endl;
    int escolha;
    cin >> escolha;
    if(escolha != 1) addToBeginning(novoAluno);
    else addToEnd(novoAluno);
}

Node* search_node(){
    using namespace std;
    string nome;
    int matricula;
    int escolha;
    cout << "Deseja procurar por nome - 1 ou matricula - 2 (padrao): ";
    cin >> escolha;
    if(escolha == 1){
        cout << "Insira o nome: ";
        cin.ignore();
        getline(cin, nome);
        Node* current = HEAD;
        while(current != NULL && current->data.get_nome().compare(nome) != 0){
            current = current->next;
        }
        if(current == NULL){
            cout << "Nao encontramos o nome: " << nome << endl;
            return current;
        }else{
            return current;
        }
    }else{
        cout << "Insira a matricula: ";
        cin >> matricula;
        Node* current = HEAD;
        while(current != NULL && current->data.get_matricula() != matricula){
            current = current->next;
        }
        if(current == NULL){
            cout << "Nao encontramos a matricula: " << matricula << endl;
            return current;
        }else{
            return current;
        }
    }
}

void remove_aluno(){
    Node* nodeToRemove = search_node();
    if(!nodeToRemove) return;
    if(nodeToRemove->next != NULL){
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    if(nodeToRemove->prev != NULL){
        nodeToRemove->prev->next = nodeToRemove->next;
    }
    delete nodeToRemove;
}

void edit_aluno(){
    using namespace std;
    string nome;
    int matricula;
    float aval1, aval2;
    Node* nodeToUpdate = search_node();
    cout << "Insira o nome do Aluno: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Insira a matricula do Aluno: ";
    cin >> matricula;
    cout << "Insira a nota 1 do Aluno: ";
    cin >> aval1;
    cout << "Insira a nota 2 do Aluno: ";
    cin >> aval2;
    nodeToUpdate->data.set_nome(nome);
    nodeToUpdate->data.set_matricula(matricula);
    nodeToUpdate->data.set_aval1(aval1);
    nodeToUpdate->data.set_aval2(aval2);
}

void print_alunos(){
    Node* current = HEAD;
    while(current != NULL){
        current->data.print();
        current = current->next;
    }
}

int main(void){
    using namespace std;
    int escolha;
    system("cls");
    while(true){
        Node* search;
        int qtd;
        cout << "Gerenciador de turma" << endl << endl;
        cout << "Adicionar aluno - 1" << endl;
        cout << "Remover aluno - 2" << endl;
        cout << "Procurar aluno - 3" << endl;
        cout << "Editar aluno - 4" << endl;
        cout << "Ver alunos - 5" << endl;
        cout << "Remover do fim - 6" << endl;
        cout << "Remover do inicio - 7" << endl;
        cout << "-----> ";
        cin >> escolha;
        switch(escolha){
            case 1:
                cout << "Quantos alunos vai inserir ?: ";
                cin >> qtd;
                while(qtd > 0){
                    add_aluno();
                    qtd--;
                }
                break;
            
            case 2:
                remove_aluno();
                break;

            case 3:
                search = search_node();
                if(search == NULL) { cout << "Aluno nao encontrado" << endl; }
                else { search->data.print(); }
                system("pause");
                break;

            case 4:
                edit_aluno();
                break;

            case 5:
                system("cls");
                print_alunos();
                break;

            case 6:
                removeFromEnd();
                break;

            case 7:
                removeFromBeginning();
                break;

            default:
                cout << "Escolha invalida!" << endl << endl;
                system("pause");
                break;
        }
    }
    return 0;
}