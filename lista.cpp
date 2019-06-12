#include<iostream>

using namespace std;

template<typename T>

class Nodo{
public:
    T data;
    Nodo<T> *next;

    Nodo(T);
    ~Nodo();
    void print();
    void modificar(T);
};

template<typename T>
Nodo<T>::Nodo(T _data){
    data = _data;
    next = NULL;
}

template<typename T>
void Nodo<T>::print(){
    cout<<data<<"->";
}

template<typename T>
void Nodo<T>::modificar(T d){
	data=d;
}

template<typename T>
Nodo<T>::~Nodo(){
}

template<typename T>
///CLASE LISTA ENLAZADA
class LinkedList{
private:
    Nodo<T> *lista;
    int tam;
public:
    LinkedList();
    ~LinkedList();
    void insertar(T);
    void mostrar();
    void eliminar(T);
};

template<typename T>
LinkedList<T>::LinkedList(){
    lista = NULL;
}

template<typename T>
void LinkedList<T>::insertar(T _data){
    Nodo<T> *new_nodo = new Nodo<T>(_data);
    Nodo<T> *temp = lista;

    if(!lista){
        lista = new_nodo;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        new_nodo->next=temp->next;
        temp->next=new_nodo;
    }
}

template<typename T>
void LinkedList<T>::mostrar(){
	Nodo<T> *actual;
	actual = lista;

	while(actual != NULL){
		cout<<actual->data<<"->";
		actual = actual->next;
	}
}

template<typename T>
void LinkedList<T>::eliminar(T _data){
    if(lista!=NULL){
    	Nodo<T> *temp = lista;
    	Nodo<T> *temp1 = NULL;

        while((temp!=NULL)&&(temp->data!=_data)){
            temp1=temp;
            temp=temp->next;
        }
		if(temp == NULL){
            cout<<"El elemento no existe"<<endl;
		}
		else if(temp1==NULL){
            lista=lista->next;
            delete temp;
		}
		else{
            temp1->next=temp->next;
            delete temp;
		}
    }
}
template<typename T>
LinkedList<T>::~LinkedList(){
}

int main(){
    LinkedList<int> lista1;
    int dato;

    bool a=false;
    int opc;
    do{
        cout<<"1.Agregar elemento"<<endl;
        cout<<"2.Eliminar elemento"<<endl;
        cout<<"3.Mostrar elemento"<<endl;
        cout<<"4.Salir"<<endl<<endl;

        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;
            switch(opc){
                case 1: cout<<"Ingrese un elemento: "<<endl;
                        cin>>dato;
                        lista1.insertar(dato);
                        lista1.mostrar();
                        cout<<endl;
                        break;

                case 2: cout<<"Elimine un elemento: "<<endl;
                        cin>>dato;
                        lista1.eliminar(dato);
                        lista1.mostrar();
                        cout<<endl;
                        break;
                case 3: cout<<"Mostrar lista: "<<endl;
                        lista1.mostrar();
                        cout<<endl;
                        break;
                case 4: a=true;
                        break;


            }
    }while(a!=true);

    return 0;
}
