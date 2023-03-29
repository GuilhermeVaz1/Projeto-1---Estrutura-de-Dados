#include <iostream>
using namespace std;

template <typename Type>
class node{
private:
    Type* elemento = new Type;
    Type* proximo = new Type;
    Type* anterior = new Type;

public:
    node(){
        
    }
};

template <typename Type>
class deque{
private:
    node<Type>* inicio = new node<Type>;
    node<Type>* fim = new node<Type>;

};