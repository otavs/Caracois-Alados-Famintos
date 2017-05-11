#include "fila.h"

template <class T> 
Fila<T>::Fila(){
	vetor = NULL;
	primeiro = -1;
	ultimo = -1;
	tam = 0;
	numElementos = 0;
}

template <class T> 
Fila<T>::Fila(int tam){
	vetor = new T[tam];
	primeiro = -1;
	ultimo = -1;
	this->tam = tam;
	numElementos = 0;
}

template <class T>
bool Fila<T>::vazia(){
	if(numElementos == 0)
		return true;
	return false;
}

template <class T>
bool Fila<T>::cheia(){
	if(numElementos == tam)
		return true;
	return false;
}

template <class T>
bool Fila<T>::insere(T elem){
	if(cheia())
		return false;
	if(primeiro == -1)
		primeiro++;
	ultimo++;
	if(ultimo == tam)
		ultimo = 0;
	vetor[ultimo] = elem;
	numElementos++;
	return true;
}

template <class T>
bool Fila<T>::remove(){
	if(vazia())
		return false;
	primeiro++;
	if(primeiro == tam)
		primeiro = 0;
	numElementos--;
	return true;
}

template <class T>
T Fila<T>::primeiroElem(){
	return vetor[primeiro];
}

template <class T>
int Fila<T>::getTam(){
	return tam;
}

template <class T>
int Fila<T>::getNumElementos(){
	return numElementos;
}

template <class T>
T Fila<T>::operator[](int i){
	if(i < tam-primeiro)
		return vetor[primeiro+i];
	else
		return vetor[i-(tam-primeiro)];
}

template class Fila<Caracol*>;
template class Fila<Comida*>;
