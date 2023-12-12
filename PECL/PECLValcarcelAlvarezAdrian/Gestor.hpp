#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
#include <vector>
class Gestor
{
    public:
        Gestor();
        void genera12Pedidos();
        void muestraPedidos();
        void borraPedidosPila();
        void encolarPedidos();
        void muestraPedidosSalasAyB();
        void muestraPedidosSalasCyD();
        void borraPedidosColas();
        void muestraPedidosEstandar();
        void muestraPedidosUrgentes();
        void maxPedidoEstandar();
        void enlistarPedidos();
        void maxPedidoUrgente();
        void buscarPedidos();
        int PedidosEnPila();
        int PedidosEnSalaA();
        int PedidosEnSalaB();
        int PedidosEnSalaC();
        int PedidosEnSalaD();
        int PedidosEnListaEstandar();
        int PedidosEnListaUrgentes();
        int PedidosEnArbol();
        void reiniciar();
        void crearArbol();
        void mostrarEstandarArbol();
        void mostrarUrgenteArbol();
        void inordenArbol();
        void buscarPedidosArbol();
        void contarImpares();
        void mostrarHojas();
        void eliminarNodoHoja();
        bool buscarNumero(int);
        int randomIDestandar();
        int randomIDurgente();
        int randomNumSegestandar();
        int randomNumSegurgente();
        ~Gestor();
    private:
        Pila pila;
        Cola colaA;
        Cola colaB;
        Cola colaC;
        Cola colaD;
        Lista estandar;
        Lista urgente;
        Arbol raiz;
        //srand(time(NULL));
};