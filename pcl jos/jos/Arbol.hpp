#include "NodoArbol.hpp"
#include <vector>
using namespace std;

class Arbol
{
    public:
        Arbol();
        int arbolLongitud();
        void setLongitud(int num);
        void insertarPedido(Pedido &p);
        void mostrarEnOrden();
        void insertar(Pedido &p);
        void pintar();
        void dibujar();
        void pintarEstandar();
        void pintarUrgente();
        void inorden();
        void estandarSeguimientoMenor();
        void estandarSeguimientoMayor();
        Pedido& obtenerUrgenteIdMayor();
        Pedido& obtenerUrgenteIdMenor();
        int numeroSeguimientoImpar();
        ~Arbol();
    private:
        NodoArbol *raiz;
        NodoArbol* insertar(NodoArbol* nodo, Pedido& pedido);
        void pintar(NodoArbol*);
        int altura(NodoArbol*);
        void dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int minPos, char linkChar);
        void pintarEstandar(NodoArbol*);
        void pintarUrgente(NodoArbol*);
        void inorden(NodoArbol*);
        Pedido estandarSeguimientoMenor(NodoArbol*);
        Pedido estandarSeguimientoMayor(NodoArbol*);
        void urgenteIdMayor(NodoArbol*);
        void urgenteIdMenor(NodoArbol*);
        void numeroSeguimientoImpar(NodoArbol*);
        
        Pedido* mayorPedido;
        Pedido* menorPedido;
        int longitud;
        int impares;
 /*
        NodoArbol* insertarPedido(NodoArbol* nodo, Pedido& pedido) {
        if (nodo == nullptr) {
            return new NodoArbol(pedido);
        }

        if (pedido.getNumSeguimiento() <= nodo->obtenerPedido().getNumSeguimiento()) {
            nodo->setSiguiente(insertarPedido(nodo->getSiguiente(), pedido));
        } else {
            nodo->setAnterior(insertarPedido(nodo->getAnterior(), pedido));
        }

        return nodo;
    }

    // Función auxiliar para recorrer el árbol en orden
    void inorden(NodoArbol* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->getSiguiente());
            nodo->obtenerPedido().informe(); // Muestra el pedido en lugar de solo el número de seguimiento
            inorden(nodo->getAnterior());
        }
    }*/
};