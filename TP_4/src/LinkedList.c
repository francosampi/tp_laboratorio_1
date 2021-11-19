#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));
    this->pFirstNode=NULL;
    this->size=0;
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=this->size;
    	/*
    	struct Node* auxP=this->pFirstNode;
    	returnAux=0;

    	while(auxP!=NULL)
    	{
    		auxP=auxP->pNextNode;
    		returnAux++;
    	}
    	*/
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	if(this!=NULL)
	{
		Node* auxP=this->pFirstNode;
		int tam = ll_len(this);

		if(nodeIndex>-1 && nodeIndex<tam)
		{
			for(int i=0; i<nodeIndex; i++)
			{
				auxP=auxP->pNextNode;
			}
			return auxP;
		}
	}
    return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;

	if(this!=NULL)
	{
		Node* pNode=(Node*)malloc(sizeof(Node));
		pNode->pElement=pElement;

		int tam = ll_len(this);
		tam++;

		if(nodeIndex>-1 && nodeIndex<tam)
		{
			if(nodeIndex!=0)
			{
				Node* auxAnterior=NULL;
				Node* auxSiguiente=NULL;

				auxAnterior=getNode(this, nodeIndex-1);

				if(auxAnterior!=NULL)
				{
					auxAnterior->pNextNode=pNode;
				}
				auxSiguiente=getNode(this, nodeIndex+1);

				if(auxSiguiente!=NULL)
				{
					pNode->pNextNode=auxSiguiente;
				}
			}
			else
			{
				pNode->pNextNode=this->pFirstNode;
				this->pFirstNode=pNode;
			}
			this->size++;
			returnAux=0;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	int tam=ll_len(this);

    	addNode(this, tam, pElement);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

	if(this!=NULL)
	{
		int tam = ll_len(this);
		Node* auxP=this->pFirstNode;

		if(index>-1 && index<tam)
		{
			auxP=getNode(this, index);
			returnAux=auxP->pElement;
		}
	}
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
	{
		int tam = ll_len(this);

		if(index>-1 && index<tam)
		{
			Node* auxP=getNode(this, index);
			auxP->pElement=pElement;
			returnAux=0;
		}
	}
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    if(this!=NULL)
    {
		int tam = ll_len(this);
		Node* auxP=this->pFirstNode;

		if(index>-1 && index<tam)
		{
			auxP=getNode(this, index);
			Node* next=auxP->pNextNode;
			if(index>0)
			{
				struct Node* prev=getNode(this, index-1);
				if(prev!=NULL)
				{
					prev->pNextNode=next;
				}
			}
			else
			{
				this->pFirstNode=NULL;
			}
			this->size--;
			free(auxP);
			auxP=NULL;
			returnAux=0;
		}
	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

	if(this!=NULL)
	{
		int tam=ll_len(this);

		for(int i=0; i<tam; i++)
		{
			ll_remove(this, i);
		}
		returnAux=0;
	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
	{
		ll_clear(this);
		free(this);
		this=NULL;
		returnAux=0;
	}
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	int tam=ll_len(this);
    	void* auxP=NULL;

		for(int i=0; i<tam; i++)
		{
			auxP=ll_get(this, i);
			if(auxP==pElement)
			{
				returnAux=i;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if (this->pFirstNode!=NULL)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL)
	{
    	void* auxElement=ll_get(this, index);

		if(ll_remove(this, index)==0)
		{
			returnAux=auxElement;
		}
	}
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=0;

    	int tam=ll_len(this);
    	void* auxP=NULL;

		for(int i=0; i<tam; i++)
		{
			auxP=ll_get(this, i);
			if(auxP==pElement)
			{
				returnAux=1;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this!=NULL && this2!=NULL)
	{
    	returnAux=0;

		int tam=ll_len(this);
		int tamB=ll_len(this2);

		if(tam==tamB)
		{
			returnAux=1;

			void* auxpA=NULL;
			void* auxpB=NULL;

			for(int i=0; i<tam; i++)
			{
				auxpA=ll_get(this, i);
				auxpB=ll_get(this2, i);
				if(auxpB!=auxpA)
				{
					returnAux=0;
					break;
				}
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
		int tam=ll_len(this);

		if(from>-1 && from<tam+1 && to>from-1 && to<tam+1)
		{
			cloneArray=ll_newLinkedList();
			void* auxP;

			for(int i=from; i<to; i++)
			{
				auxP=ll_get(this, i);
				if(auxP!=NULL)
				{
					ll_add(cloneArray, auxP);
				}
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
    	int tam=ll_len(this);
    	cloneArray=ll_subList(this, 0, tam);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    if(this!=NULL && pFunc!=NULL)
    {
    	void* pA = NULL;
    	void* pB = NULL;

    	if(order==1)
    	{
    		void* auxSort = pB;
			pB=pA;
			pA=auxSort;
			returnAux=0;
    	}
    	else
    	{
    		if(order==0)
    		{
    			void* auxSort = pA;
    			pA=pB;
    			pA=auxSort;
    			returnAux=0;
    		}
    		else
    		{
    			returnAux=-1;
    		}
    	}
    }
    return returnAux;
}

