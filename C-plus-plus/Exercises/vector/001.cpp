#include <iostream>
#include <vector>
using namespace std;

class Libro {
    private:
        string titulo;
        string autor;
        string fecha;
    public:
        Libro(string titulo, string autor, string fecha) {
            this->titulo = titulo;
            this->autor = autor;
            this->fecha = fecha;
        }

        void setTitulo(string titulo) { this->titulo = titulo; }
        void setAutor(string autor) { this->autor = autor; }
        void setFecha(string fecha) { this->fecha = fecha; }

        string getTitulo() { return titulo; }
        string getAutor() { return autor; }
        string getFecha() { return fecha; }

        void print() {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Fecha: " << fecha << endl;
        }
};

class Biblioteca {
    private:
        vector <Libro*> catalogo;
        string nombre;
    public:     
        Biblioteca(string nombre) {
            this->nombre = nombre;
        }
    void agregarLibro(Libro * tmp) {
        catalogo.push_back(tmp);
    }

    void imprimirCatalogo() {
        for(int i = 0; i < catalogo.size(); i++) {
            catalogo[i]->print();
        }
    }

    void BuscarPorAutor(string nombre) {
        for(int i = 0; i < catalogo.size(); i++) {
            if(catalogo[i]->getAutor() == nombre) {
                catalogo[i]->print();
            }
        }
    }

    void LibrosDespuesDelDosMil() {
        for(int i = 0; i < catalogo.size(); i++) {
            if(catalogo[i]->getFecha() > "2000") {
                catalogo[i]->print();
            }
        }
    }   
};

int main() {
    Biblioteca *biblioteca = new Biblioteca("Biblioteca Nacional");
    Libro *libro1 = new Libro("El Señor de los Anillos", "J.R.R. Tolkien", "1954");
    Libro *libro2 = new Libro("El Hobbit", "J.R.R. Tolkien", "1937");
    Libro *libro3 = new Libro("El Alquimista", "Paulo Coelho", "1988");
    Libro *libro4 = new Libro("El Principito", "Antoine de Saint-Exupéry", "1943");
    Libro *libro5 = new Libro("El Quijote", " Miguel de Cervantes", "1615");
    biblioteca->agregarLibro(libro1);
    biblioteca->agregarLibro(libro2);
    biblioteca->agregarLibro(libro3);
    biblioteca->agregarLibro(libro4);
    biblioteca->agregarLibro(libro5);
    biblioteca->imprimirCatalogo();
    biblioteca->BuscarPorAutor("J.R.R. Tolkien");
    biblioteca->LibrosDespuesDelDosMil();
    return 0;
}