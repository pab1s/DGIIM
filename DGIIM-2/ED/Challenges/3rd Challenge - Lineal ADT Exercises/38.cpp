#include <stack>
#include <iostream>
using namespace std;

/**
 * @brief Clase Cola implementada a partir de dos pilas. Tiene 4
 * métodos: vacia() -> devuelve true si la cola esta vacia, false si no;
 * poner(int aux) -> inserta ese elemento en la cola
 * top() -> devuelve el tope de la cola
 * quitar() -> elimina el primer elemento de la cola
 * @tparam T Plantilla del tipo de dato que se introduce en la cola
 */
template <class T> class Cola {
   private:
    stack<T> p1, p2;  // p1 -> insertar, p2 -> frente y quitar

   public:
    int frente() {
        if (p2.empty()) {
            while (!p1.empty()) {
                int aux = p1.top();
                p2.push(aux);
                p1.pop();
            }
        }
        return p2.top();
    }

    bool vacia() const { return p1.empty() && p2.empty(); }

    void poner(int aux) { p1.push(aux); }

    void quitar() {
        if (p2.empty()) {
            while (!p1.empty()) {
                int aux = p1.top();
                p2.push(aux);
                p1.pop();
            }
        }
        p2.pop();
    }
};

int main() {
    Cola<int> C;
    for (int i = 1; i <= 10; i++)
        C.poner(i);
    
    cout << C.frente() << endl;
    
    C.poner(11);
    C.quitar();

    for (int i = 0; i < 10; i++) {
        cout << C.frente() << endl;
        C.quitar();
    }

    cout << endl << C.vacia() << endl;
    
}