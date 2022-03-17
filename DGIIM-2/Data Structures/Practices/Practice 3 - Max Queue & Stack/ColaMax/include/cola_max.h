#ifndef __Cola_max_H__
#define __Cola_max_H__
#include <stack>
using namespace std;

template <class T>
struct elemento {
    T ele;
    T maximo;
};

template <class T>
class Cola_max {
    private:
        stack<elemento<T>> pila;

    public:
        Cola_max() = default;
        bool vacia();
        elemento<T> frente();
        void poner(const T& elem);
        void quitar();
        int num_elementos() const;
};
#include "../src/cola_max.cpp"
#endif /* __Cola_max_H__ */