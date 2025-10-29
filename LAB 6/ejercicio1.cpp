#include <iostream>
#include <string>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int tamaño;

public:
    ListaEnlazada() : cabeza(nullptr), cola(nullptr), tamaño(0) {}
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    void insertarAlFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
        tamaño++;
    }
    void insertarAlInicio(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
        tamaño++;
    }
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        std::cout << "Lista: ";
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << " -> NULL" << std::endl;
    }
    int obtenerTamaño() const {
        return tamaño;
    }
    bool buscar(T valor) const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }    
    bool eliminar(T valor) {
        if (cabeza == nullptr) return false;
        
        // eliminar la cabeza
        if (cabeza->dato == valor) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            if (cabeza == nullptr) {
                cola = nullptr;
            }
            delete temp;
            tamaño--;
            return true;
        }
        
        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }
        
        if (actual->siguiente == nullptr) {
            return false; // osea que no encontrado
        }
        
        Nodo<T>* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        
        if (temp == cola) {
            cola = actual;
        }
        
        delete temp;
        tamaño--;
        return true;
    }
};  

void demostrarListas() {
    ListaEnlazada<int> listaEdades;
    
    listaEdades.insertarAlFinal(25);
    listaEdades.insertarAlFinal(30);
    listaEdades.insertarAlInicio(20);
    listaEdades.insertarAlFinal(35);
    
    listaEdades.mostrar();
    std::cout << "Tamaño: " << listaEdades.obtenerTamaño() << std::endl;
    
    int edadBuscada = 30;
    std::cout << "¿Edad " << edadBuscada << " encontrada? " << (listaEdades.buscar(edadBuscada) ? "Sí" : "No") << std::endl;
    
    listaEdades.eliminar(30);
    std::cout << "Después de eliminar 30: ";
    listaEdades.mostrar();
    
    std::cout << "\n=== LISTA DE PALABRAS (string) ===" << std::endl;
    ListaEnlazada<std::string> listaPalabras;
    
    listaPalabras.insertarAlFinal("Hola");
    listaPalabras.insertarAlFinal("Mundo");
    listaPalabras.insertarAlInicio("¡Hola,");
    listaPalabras.insertarAlFinal("C++!");
    
    listaPalabras.mostrar();
    std::cout << "Tamaño: " << listaPalabras.obtenerTamaño() << std::endl;
    
    std::string palabraBuscada = "Mundo";
    std::cout << "¿Palabra '" << palabraBuscada << "' encontrada? " << (listaPalabras.buscar(palabraBuscada) ? "Sí" : "No") << std::endl;
    
    listaPalabras.eliminar("Mundo");
    std::cout << "Después de eliminar 'Mundo': ";
    listaPalabras.mostrar();
}

int main() {
    demostrarListas();
    return 0;
}