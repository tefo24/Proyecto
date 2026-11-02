#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    Nodo() {
        siguiente = nullptr;
        anterior = nullptr;
    }

    Nodo(T dato) {
        this->dato = dato;
        siguiente = nullptr;
        anterior = nullptr;
    }

    ~Nodo() {}

    T& getDato(){ 
    return dato; 
    }
    void setDato(T newDato){ 
    dato = newDato; 
    }
    Nodo<T>* getSiguiente(){
        return siguiente;
    }
    void setSiguiente(Nodo<T>* newSiguiente){
        siguiente = newSiguiente;
    }
    Nodo<T>* getAnterior(){
        return anterior;
    }
    void setAnterior(Nodo<T>* newAnterior){
        anterior = newAnterior;
    }
};

#endif