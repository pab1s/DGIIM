#include "../include/diccionario.h"

template <typename T, typename U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& D) {
    /*typename list<data<T,U> >::const_iterator it_d;
    typename list<data<T,U> >::iterator it=this->datos.begin();*/
    
    datos.assign(D.datos.begin(),D.datos.end());
    /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
            this->datos.insert(it,*it_d);
            
    }*/
}

template <typename T, typename U>
void Diccionario<T,U>::Borrar(){    
        this->datos.erase(datos.begin(),datos.end());
}	      

template <typename T, typename U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
    Copiar(D);
}

template <typename T, typename U>
Diccionario<T,U>& Diccionario<T,U>:: operator=(const Diccionario<T,U> &D){
    if (this!=&D){
            Borrar();
            Copiar(D);
    }
    return *this;
}

template <typename T, typename U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
    
    if (datos.size()>0){
        
        typename list<data<T,U> >::iterator it;
        
        for (it=datos.begin(); it!=datos.end() ;++it){
        if ((*it).clave==p) {
                it_out=it;
                return true;
        }
        else if ((*it).clave>p){
                it_out=it;
                return false;
        }	  
            
        }
        
        it_out=it;
        return false;
    }
    else {	
        it_out=datos.end();
        return false;
    }	    
}

template <typename T, typename U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;
    
        datos.insert(it,p);
            
    }
    
}

template <typename T, typename U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
        datos.insert(it,p);
    }	    
    
    //Insertamos el siginificado al final
        (*it).info_asoci.insert((*it).info_asoci.end(),s);
}

template <typename T, typename U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p) {
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
    return list<U>();
    }
    else{
    return (*it).info_asoci;
    }
}

template <typename T, typename U>
list<U> Diccionario<T,U>::getClaves(){
    list<U> result;
    list<data<T, U>> aux(datos);
    typename list<data<T, U>>::const_iterator it;

    for (it=datos.cbegin(); it!=datos.cend(); ++it) {
        result.push_back(aux.front().clave);
        aux.pop_front();
    }

    return result;
}

template<typename T, typename U>
data<T,U> Diccionario<T,U>::getDato(const T &p) {
    typename list<data<T,U> >::iterator it;
    Esta_Clave(p,it);

    return *it;
}

template <typename T, typename U>
bool Diccionario<T,U>::esVacia(){
    if (datos.size() == 0)
        return true;
    else
        return false;
}

template <typename T, typename U>
void Diccionario<T,U>::Ordenar(){
    datos.sort();
}

template <typename T, typename U>
void Diccionario<T,U>::Eliminar(const T &clave){
    typename list<data<T,U>>::iterator it_out;
    if (Esta_Clave(clave, it_out))
        datos.erase(it_out);
        
}
    
template <typename T, typename U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template <typename T, typename U>
typename list<data<T,U> >::iterator & Diccionario<T,U>::begin(){
    return datos.begin();
}

template <typename T, typename U>
typename list<data<T,U> >::iterator & Diccionario<T,U>::end(){
    return datos.end();
}

template <typename T, typename U>
typename list<data<T,U> >::const_iterator Diccionario<T,U>::cbegin()const {
    return datos.cbegin();
}

template <typename T, typename U>
typename list<data<T,U> >::const_iterator Diccionario<T,U>::cend()const {
    return datos.cend();
}

//Iterator
template<class T, class U>
Diccionario<T, U>::iterator::iterator(typename std::list<data<T, U>>::iterator it) {
    this->lit = it;
}

template <typename T, typename U>
Diccionario<T, U>::iterator::iterator(){}

template <typename T, typename U>
Diccionario<T, U>::iterator::iterator(const iterator& it){
    lit = it.lit;
}

template <typename T, typename U>
typename Diccionario<T, U>::iterator& Diccionario<T, U>::iterator::operator=(const iterator& it){
    lit = it.lit;
    return *this;
}

template <typename T, typename U>
typename Diccionario<T, U>::iterator& Diccionario<T, U>::iterator::operator++(){
    return ++lit;
}

template <typename T, typename U>
typename Diccionario<T, U>::iterator& Diccionario<T, U>::iterator::operator--(){
    return --lit;
}

template <typename T, typename U>
data<T, U>& Diccionario<T, U>::iterator::operator*(){
    return *lit;
}

template <typename T, typename U>
bool Diccionario<T, U>::iterator::operator!=(const iterator& it)const {
    return lit != it.lit;
}

template <typename T, typename U>
bool Diccionario<T, U>::iterator::operator==(const iterator& it)const {
    return lit == it.lit;
}

//Const iterator
template<class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(typename list<data<T, U>>::const_iterator it) {
    this->lit = it;
}

template <typename T, typename U>
Diccionario<T, U>::const_iterator::const_iterator(){}

template <typename T, typename U>
Diccionario<T, U>::const_iterator::const_iterator(const const_iterator& it){
    lit = it.lit;
}

template <typename T, typename U>
typename Diccionario<T, U>::const_iterator& Diccionario<T, U>::const_iterator::operator=(const const_iterator& it){
    lit = it.lit;
    return *this;
}

template <typename T, typename U>
typename Diccionario<T, U>::const_iterator& Diccionario<T, U>::const_iterator::operator++(){
    return ++lit;
}

template <typename T, typename U>
typename Diccionario<T, U>::const_iterator& Diccionario<T, U>::const_iterator::operator--(){
    return --lit;
}

template <typename T, typename U>
data<T, U> Diccionario<T, U>::const_iterator::operator*() const{
    return *lit;
}

template <typename T, typename U>
bool Diccionario<T, U>::const_iterator::operator!=(const const_iterator& it)const {
    return lit != it.lit;
}

template <typename T, typename U>
bool Diccionario<T, U>::const_iterator::operator==(const const_iterator& it)const {
    return lit == it.lit;
}
