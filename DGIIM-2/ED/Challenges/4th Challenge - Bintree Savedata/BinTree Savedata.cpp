// Escritura del árbol
template <typename T>
void Escribe(ostream &os, const info_nodo<T> *&n) {
    if (n != nullptr) {
        if (n->hijoizq != nullptr && n->hijodcha != nullptr) {
            os << 'n' << n->et;
            Escribe(os, n->hijoizq);
            Escribe(os, ->hijodcha);
        } else if (n->hijoizq != nullptr && n->hijodcha == nullptr) {
            os << 'i' << n->et;
            Escribe(os, n->hijoizq);
        } else if (n->hijoizq == nullptr && n->hijodcha != nullptr) {
            os << 'd' << n->et;
            Escribe(os, n->hijodcha);
        } else if (n->hijoizq == nullptr && n->hijodcha == nullptr) {
            os << 'h' << n->et;
        }
    } else if (n == nullptr)
        os << 'x';
}
// Lectura del árbol
template <typename T>
void Lee(istream &is, info_nodo<T> *&n) {
    char c;
    c = is.get();
    if (is) {
        if (c == 'x')
            n = nullptr;
        else {
            T e;
            is >> e;
            n = new info_nodo<T>(e);
            switch (c) {
                case 'n':
                    Lee(is, n->hijoizq);
                    Lee(is, n->hijodcha);
                    n->hijoizq->padre = n;
                    n->hijodcha->padre = n;
                    break;
                case 'i':
                    lee(is, n->hijoizq);
                    n->hijoizq->padre = n;
                    n->hijodcha = nullptr;
                    break;
                case 'd':
                    Lee(is, n->hijodcha);
                    n->hijodcha->padre = n;
                    n->hijoizq = nullptr;
                    break;
                case 'h':
                    n->hijoizq = nullptr;
                    n->hijodcha = nullptr;
                    break;
            }
        }
    }
}
