#include <iostream>
#include "Arbol.hpp"

/*class NodoArbol {
public:
    int numeroSeguimiento;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(int numSeg)
        : numeroSeguimiento(numSeg), izquierda(nullptr), derecha(nullptr) {}
};*/
Arbol:: Arbol() { raiz = nullptr; longitud = 0; }

int Arbol::arbolLongitud()
{
    return longitud;
}
void Arbol:: setLongitud(int num)
{
    longitud = num;
};

void Arbol:: insertar(Pedido& pedido) 
{ 
    raiz = insertar(raiz, pedido);
    longitud++;
}

NodoArbol* Arbol:: insertar(NodoArbol* nodo, Pedido& pedido)
{
    if(!nodo)
        return new NodoArbol(pedido);
    if(pedido.getNumSeguimiento() <= nodo->obtenerPedido().getNumSeguimiento())
        nodo->setAnterior(insertar(nodo->getAnterior(), pedido));
    else
        nodo->setSiguiente(insertar(nodo->getSiguiente(), pedido));
    return nodo;
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < static_cast<int>(linkAbove[i].size()); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

int Arbol::altura(NodoArbol* nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->getAnterior()), altura(nodo->getSiguiente()));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->getAnterior()) {
        int numeroQueQuieroImprimirEnElArbol = nodo->getAnterior()->obtenerPedido().getNumSeguimiento();
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->getAnterior(), nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol = nodo->obtenerPedido().getNumSeguimiento();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->getSiguiente())
        dibujarNodo(output, linkAbove, nodo->getSiguiente(), nivel + 1, output[nivel].size(), 'R');
}

void Arbol::pintarEstandar()
{
    pintarEstandar(raiz->getAnterior());
    cout << '\n';
}
void Arbol::pintarEstandar(NodoArbol* nodo)
{
    if(!nodo) return;
        pintarEstandar(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) cout << nodo->obtenerPedido().getNumSeguimiento() << " ";
        pintarEstandar(nodo->getSiguiente()); 
}

void Arbol::pintarUrgente()
{
    pintarUrgente(raiz->getSiguiente());
    cout << '\n';
}
void Arbol::pintarUrgente(NodoArbol* nodo)
{
    if(!nodo) return;
        pintarUrgente(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) cout << nodo->obtenerPedido().getNumSeguimiento() << " ";
        pintarUrgente(nodo->getSiguiente()); 
}

void Arbol::inorden()
{
    inorden(raiz);
    cout << '\n';
}

void Arbol::inorden(NodoArbol* nodo) {
    if (nodo != nullptr) {
        inorden(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) nodo->obtenerPedido().informe();
        inorden(nodo->getSiguiente());
    }
}

void Arbol::estandarSeguimientoMenor()
{
    Pedido menor=estandarSeguimientoMenor(raiz->getAnterior());
    cout << "\tPEDIDO ESTANDAR CON MENOR NUMERO DE SEGUIMIENTO\n";
    menor.informe();
}
Pedido Arbol::estandarSeguimientoMenor(NodoArbol* nodo) {
    while (nodo->getAnterior() != nullptr) {
    nodo = nodo->getAnterior();
    }
    return nodo->obtenerPedido();
}

void Arbol::estandarSeguimientoMayor()
{
    Pedido mayor=estandarSeguimientoMayor(raiz->getAnterior());
    cout << "\tPEDIDO ESTANDAR CON MAYOR NUMERO DE SEGUIMIENTO\n";
    mayor.informe();
}
Pedido Arbol::estandarSeguimientoMayor(NodoArbol* nodo) {
    while (nodo->getSiguiente() != nullptr){// && nodo->getSiguiente()->obtenerPedido().getNumSeguimiento() <= 500) {
    nodo = nodo->getSiguiente();
    }
    return nodo->obtenerPedido();
}

Pedido& Arbol::obtenerUrgenteIdMenor() {
    menorPedido = nullptr;
    
    urgenteIdMenor(raiz->getSiguiente());
    return *menorPedido;
}

void Arbol::urgenteIdMenor(NodoArbol* nodo){
    
    if (nodo != nullptr) {
        if (menorPedido == nullptr || nodo->obtenerPedido().getPrioridad() < menorPedido->getPrioridad()) {
            menorPedido = &nodo->obtenerPedido();
        }
        urgenteIdMenor(nodo->getAnterior());
        urgenteIdMenor(nodo->getSiguiente());
    }
}

Pedido& Arbol::obtenerUrgenteIdMayor() {
    mayorPedido = nullptr;
    urgenteIdMayor(raiz->getSiguiente());
    return *mayorPedido;
}
void Arbol::urgenteIdMayor(NodoArbol* nodo){
    if (nodo != nullptr) {
        if (mayorPedido == nullptr || nodo->obtenerPedido().getPrioridad() > mayorPedido->getPrioridad()) {
            mayorPedido = &nodo->obtenerPedido();
        }
        urgenteIdMayor(nodo->getAnterior());
        urgenteIdMayor(nodo->getSiguiente());
    }
}

int Arbol::numeroSeguimientoImpar(){
    impares = 0;
    numeroSeguimientoImpar(raiz);
    return impares;
}

void Arbol::numeroSeguimientoImpar(NodoArbol* nodo){
    if (nodo != nullptr) {
        if(nodo->obtenerPedido().getNumSeguimiento() != 500 && nodo->obtenerPedido().getNumSeguimiento()%2 != 0 ) {
            impares++;
        }
        numeroSeguimientoImpar(nodo->getAnterior());
        numeroSeguimientoImpar(nodo->getSiguiente());
    }
}
Arbol::~Arbol() {}
