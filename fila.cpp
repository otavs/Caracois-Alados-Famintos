#include "fila.h"

template <class T>
Fila<T>::Fila(int tam){
	this->vetor = new T[tam];
	this->primeiro = -1;
	this->ultimo = -1;
	this->tam = tam;
	this->numElementos = 0;
}

template <class T>
bool Fila<T>::vazia(){
	if(this->numElementos == 0)
		return true;
	return false;
}

template <class T>
bool Fila<T>::cheia(){
	if(this->numElementos == this->tam)
		return true;
	return false;
}

template <class T>
bool Fila<T>::insere(T elem){
	if(this->cheia())
		return false;
	if(this->primeiro == -1)
		this->primeiro++;
	this->ultimo++;
	if(this->ultimo == this->tam)
		this->ultimo = 0;
	this->vetor[this->ultimo] = elem;
	this->numElementos++;
	return true;
}

template <class T>
bool Fila<T>::remove(){
	if(this->vazia())
		return false;
	this->primeiro++;
	if(this->primeiro == this->tam)
		this->primeiro = 0;
	this->numElementos--;
	return true;
}

template <class T>
T Fila<T>::primeiroElem(){
	if(this->vazia())
		return 0;
	return this->vetor[this->primeiro];
}

template <class T>
int Fila<T>::getTam(){
	return this->tam;
}

template <class T>
int Fila<T>::getNumElementos(){
	return this->numElementos;
}

template <class T>
T Fila<T>::operator[](int i){
	if(i >= this->numElementos)
		return 0;
	if(i < this->tam-this->primeiro)
		return this->vetor[this->primeiro+i];
	else
		return this->vetor[i-(this->tam-this->primeiro)];
}
