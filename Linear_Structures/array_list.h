//  !	Classe Lista.
/*  !
 *  \Copyright (C) 2016  Adan Pereira Gomes
 *  \Released under the GNU General Public License 2.0
 */

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

//! Classe ArrayList | Lista
/*!
 *	Tipo de estrutura que generaliza a Pilha e a Fila.
 *	Diferentemente delas, a Lista pode inserir e remover dados em qualquer ordem.
 *	Esta classe e capaz de alocar dinamicamente memoria conforme necessario.
 */
template<typename T>
class ArrayList {
 public:
    //! Construtor Padrão.
	/*!	Usado para criar estrutura com tamanho padrão.	*/
    ArrayList();

    //! Construtor Polimórfico.
	/*!	Usado para criar a estrutura com o tamanho determinado.
	 *	\param max_size o tamanho maximo que a estrutura comporta.
	 *	\sa ArrayQueue()
	 */
    explicit ArrayList(std::size_t max_size);

    //! Destrutor.
	/*!	Destroi todos os dados relacionados a classe e devolve a memoria ao SO.	*/
    ~ArrayList();

    //! Função membro clear | limpa.
	/*!	Responsavel por limpar estrutura de forma a ser reutilizada.	*/
	void clear();

    //! Função membro push_back.
	/*!	Responsavel por colocar o dado no final da estrutura.
	 *	\param data um tipo T que sera armazenado.
	 *	\sa push_front()
	 */
    void push_back(T data);

    //! Função membro push_front.
	/*!	Responsavel por colocar o dado no comeco da estrutura.
	 *	\param data um tipo T que sera armazenado.
	 *	\sa push_back()
	 */
    void push_front(T data);

    //! Função membro insert.
	/*!	Responsavel por inserir o dado em determinada posicao da estrutura.
	 *	\param data um tipo T que sera armazenado.
	 *  \param index um tipo std::size_t indica a posicao da insercao.
	 *	\sa insert_sorted()
	 */
    void insert(T data, std::size_t index);

    //! Função membro insert_sorted.
	/*!	Responsavel por inserir o dado na estrutura de forma ordenada.
	 *	\param data um tipo T que sera armazenado
	 *	\sa insert()
	 */
    void insert_sorted(T data);

    //! Função membro pop.
	/*!	Responsavel por remover o dado do primeiro elemento.
	 *	\return um tipo T armazenado por ultimo.
	 *	\sa pop_front(), pop_back()
	 */
    T pop(std::size_t index);

    //! Função membro pop_front.
	/*!	Responsavel por remover o dado do primeiro elemento.
	 *	\return um tipo T armazenado na primeira posicao.
	 *	\sa pop(), pop_back()
	 */
    T pop_front();

    //! Função membro pop_back.
	/*!	Responsavel por remover o dado do primeiro elemento.
	 *	\return um tipo T armazenado na ultima posicao.
	 *	\sa pop(), pop_front()
	 */
    T pop_back();

    //! Função membro remove.
	/*!	Responsavel por remover um dado elemento da estrutura.
     *  \param data um tipo T que sera removido da estrutura.
     */
    void remove(T data);

    //! Função membro full | cheia const.
	/*!	Testa se a estrutura esta cheia.
	 *	\return um bool.
	 *	\sa empty()
	 */
	bool full() const;

    //! Função membro empty | vazia const.
	/*!	Testa se a estrutura esta vazia.
	 *	\return um bool.
	 *	\sa full()
	 */
    bool empty() const;

    //! Função membro contains | contem const.
	/*!	Testa se a estrutura contem o elemento.
	 *	\return um bool.
	 */
    bool contains(const T& data) const;

    //! Função membro find const.
	/*!	Indica a posicao em que se encontra o dado.
	 * 	\param data um tipo const T&, um dado a ser armazenado;
	 *	\return um std::size_t.
	 */
    std::size_t find(const T& data) const;

    //! Função membro size | tamanho const.
	/*!	Indica o tamanho atual da estrutura.
	 *	\return um std::size_t.
	 *	\sa max_size()
	 */
    std::size_t size() const;

    //! Função membro max_size | capacidade const.
	/*!	Indica a capacidade maxima que a estrutura comporta.
	 *	\return um std::size_t.
	 *	\sa size()
	 */
    std::size_t max_size() const;

    //! Função membro at.
	/*!	Retorna o dado que esta armazenado na posicao.
	 * 	\param index um tipo std::size_t india a posicao.
	 *	\return um T.
	 */
    T& at(std::size_t index);

    //! Função membro operator[].
	/*!	Implementa a funcionalidade dos colchetes para a estrutura.
	 * 	\param index um tipo std::size_t, indica a posicao.
	 *	\return um T&.
	 */
    T& operator[](std::size_t index);

    //! Função membro at const.
	/*!	Retorna o dado que esta armazenado na posicao.
	 * 	\param index um tipo std::size_t india a posicao.
	 *	\return um const T&.
	 */
    const T& at(std::size_t index) const;

    //! Função membro operator[] const.
	/*!	Implementa a funcionalidade dos colchetes para a estrutura.
	 * 	\param index um tipo std::size_t, indica a posicao.
	 *	\return um const T&.
	 */
    const T& operator[](std::size_t index) const;

 private:
    //! Função membro privada go_backward.
	/*!	Avança todos elementos da Fila uma posição para tras.
	 * 	\param index um tipo int que indica a posicao.
	 *  \sa go_forward()
	 */
    void go_backward(int index);

    //! Função membro privada go_forward.
	/*!	Avança todos elementos da Fila uma posição para frente.
	 * 	\param index um tipo int que indica a posicao.
	 *  \sa go_backward()
	 */
    void go_forward(int index);

    //! Variavel privada contents .
	/*!	Responsavel por armazenar os dados da estrutura.	*/
    T* contents;

    //! Variavel privada size_ .
    /*!	Responsavel por armazenar o indice do ultimo elemento armazenado.	*/
    std::size_t size_;

    //! Variavel privada max_size_ .
	/*!	Responsavel por indicar a capacidade maxima comportada pela estrutura.	*/
    std::size_t max_size_{0u};

    //! Variavel privada DEFAULT_SIZE .
	/*!	Constante que define o tamanho padrão da estrutura caso
		a estrutura seja criada sem um tamanho inicial.
	 */
    static const auto DEFAULT_SIZE = 10u;
};

template<typename T>
ArrayList<T>::ArrayList() :
    max_size_{DEFAULT_SIZE} 
{
	//max_size_ = DEFAULT_SIZE;
	contents = new T[DEFAULT_SIZE];
}

template<typename T>
ArrayList<T>::ArrayList(std::size_t max_size) :
    max_size_{max_size} 
{
	contents = new T[max_size_];
}

template<typename T>
ArrayList<T>::~ArrayList() {
	delete contents;
}

template<typename T>
void ArrayList<T>::clear() {
	size_ = 0u;
}

template<typename T>
void ArrayList<T>::push_back(T data) {
	if (full()) {
		throw std::out_of_range("Erro: Estrutura Cheia.");
	} else {
		contents[++size_] = data;
	}
}

template<typename T>
void ArrayList<T>::push_front(T data) {
	if (full()) {
		throw std::out_of_range("Erro: Estrutura Cheia.");
	} else {
		insert(data, 0);
	}
}

template<typename T>
void ArrayList<T>::insert(T data, std::size_t index) {
	if (full()) {
        throw std::out_of_range("Erro: Estrutura cheia.");
	} else {
	    if (index < 0 or index > size_) {
			throw std::out_of_range("Erro: Posicao invalida.");
		} else {
            ++size_;
            go_backward(index);
            contents[index] = data;
		}
	}
}

template<typename T>
void ArrayList<T>::insert_sorted(T data) {
    if (full()) {
        throw std::out_of_range("Erro: Estrutura cheia.");
    } else {
        std::size_t i = 0;
        while (i != size_ && data > contents[i]) {
            ++i;
        }
        insert(data, i);
    }
}

template<typename T>
T ArrayList<T>::pop(std::size_t index) {
	if (index > size_ || index < 0) {
		throw std::out_of_range("Erro: Posicao invalida.");
	} else {
        T tmp;
	    --size_;
		tmp = contents[index];
		go_forward(index);
		return tmp;
	}
}

template<typename T>
T ArrayList<T>::pop_front() {
	if (empty()) {
		throw std::out_of_range("Erro: Estrutura Vazia");
	} else {
        return pop(0);
	}
}

template<typename T>
T ArrayList<T>::pop_back() {
	if (empty()) {
		throw std::out_of_range("Erro: Estrutura Vazia");
	} else {
	    T tmp;
		tmp = contents[size_--];
		return tmp;
	}
}

template<typename T>
void ArrayList<T>::remove(T data) {
	if (!contains(data)) {
		throw std::invalid_argument("Erro: Dado inexistente.");
	} else {
		pop(data);
	}
}

template<typename T>
bool ArrayList<T>::full() const {
	return size_ == max_size_;
}

template<typename T>
bool ArrayList<T>::empty() const {
	return size_ == 0u;
}

template<typename T>
bool ArrayList<T>::contains(const T& data) const {
	if ( !empty() ) {
		std::size_t i = 0;
		bool encontrou = false;
		while ( i != size_ && !encontrou ) {
			if ( contents[i] == data ) {
				return true;
			}
			++i;
		}
		return false;
	} else {
		return false;
	}
}

template<typename T>
std::size_t ArrayList<T>::find(const T& data) const {
    std::size_t i = 0u;
    if (empty()) {
        throw std::out_of_range("Erro: Estrutura vazia.");
    } else {
		while (contents[i] != data && i != size_ + 1) {
			i++;
		}
		if ( i > size_ ) {
		    return size_ + 1;
		} else {
		    return i;
		}
	}
}

template<typename T>
std::size_t ArrayList<T>::size() const {
	return size_;
}

template<typename T>
std::size_t ArrayList<T>::max_size() const {
	return max_size_;
}

template<typename T>
T& ArrayList<T>::at(std::size_t index) {
	if (index < 0 || index > max_size_) {
		throw std::out_of_range("Erro: Posicao invalida.");
	} else {
		return contents[index];
	}
}

template<typename T>
T& ArrayList<T>::operator[](std::size_t index) {
	return contents[index];
}

template<typename T>
const T& ArrayList<T>::at(std::size_t index) const {
    at(index);
}

template<typename T>
const T& ArrayList<T>::operator[](std::size_t index) const {
    return operator[](index);
}

template<typename T>
void ArrayList<T>::go_backward(int index) {
	for (std::size_t i = size_; i != index; --i) {
		contents[i] = contents[i - 1];
	}
}

template<typename T>
void ArrayList<T>::go_forward(int index) {
	for (std::size_t i = index; i != size_; ++i) {
		contents[i] = contents[i + 1];
	}
}

}  // namespace structures

#endif
