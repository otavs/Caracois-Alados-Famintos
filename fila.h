// Fila circular
#ifndef FILA_H
#define FILA_H

template <class T>
class Fila{
	private:
		T *vetor;
		int primeiro, ultimo, tam, numElementos;
	public:
		Fila(int);				// construtor
		bool vazia();			// verifica se está vazia
		bool cheia();			// verifica se está cheia
		bool insere(T);			// insere elemento no fim
		bool remove();			// remove primeiro elemento
		T primeiroElem();		// retorna o valor do primeiro elemento
		int getTam();			// retorna o tamanho máximo da fila
		int getNumElementos();	// retorna o numero de elementos atualmente na fila
		T operator[](int);		// retorna o i-ésimo elemento da fila (começando por 0)
};

#endif
