#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "Nodo.h"
#include <iostream>

template <typename T>
class Lista_Doble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    Lista_Doble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    Nodo<T>* getCabeza() { return cabeza; }
    void setCabeza(Nodo<T>* newCabeza) { cabeza = newCabeza; }
    Nodo<T>* getCola() { return cola; }
    void setCola(Nodo<T>* newCola) { cola = newCola; }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (estaVacia()){
            cabeza = nuevo;
            cola = nuevo;
        }else{
            cola->setSiguiente(nuevo);
            nuevo->setAnterior(cola);
            cola = nuevo;
        }
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (estaVacia()){
            cabeza = nuevo;
            cola = nuevo;
        }else{
            cabeza->setAnterior(nuevo);
            nuevo->setSiguiente(cabeza);
            cabeza = nuevo;
        }
    }

    Nodo<T>* buscar(T dato){
        Nodo<T>* aux = cabeza;
        while (aux != nullptr){
            if (aux->getDato() == dato){
                return aux;
            }
            aux = aux->getSiguiente();
        }
        return nullptr;
    }

    void imprimir() {
    if (estaVacia()) {
        std::cout << "Lista vacia" << std::endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        aux->getDato().imprimir();
        aux = aux->getSiguiente();
    }
    }

    bool eliminar(T dato) {
    Nodo<T>* nodo = buscar(dato);
    if (nodo == nullptr) {
        return false;             
    }
    if (nodo == cabeza && nodo == cola) {
        cabeza = nullptr;
        cola = nullptr;
    } else if (nodo == cabeza) {
        cabeza = cabeza->getSiguiente();
        cabeza->setAnterior(nullptr);
    } else if (nodo == cola) {
        cola = cola->getAnterior();
        cola->setSiguiente(nullptr);
    } else {
        nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
        nodo->getSiguiente()->setAnterior(nodo->getAnterior()); 
    }
    delete nodo;
    return true;
    }

    ~Lista_Doble() {
    while (cabeza != nullptr) {
        Nodo<T>* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
    }
    cola = nullptr;
    }

    Lista_Doble(const Lista_Doble<T>& otra) {
    cabeza = nullptr;
    cola = nullptr;
    Nodo<T>* aux = otra.cabeza;
    while (aux != nullptr){
        insertarFinal(aux->getDato());
        aux = aux->getSiguiente();

    }
    }

    Lista_Doble<T>& operator=(const Lista_Doble<T>& otra) {
    if (this != &otra) {           
        while (cabeza != nullptr) {
            Nodo<T>* aux = cabeza;
            cabeza = cabeza->getSiguiente();
            delete aux;
        }
        cola = nullptr;
        Nodo<T>* aux = otra.cabeza;
        while (aux != nullptr) {
            insertarFinal(aux->getDato());
            aux = aux->getSiguiente();
        }
    }
    return *this;                    
    }
};

#endif