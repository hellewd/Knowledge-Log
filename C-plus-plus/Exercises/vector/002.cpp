#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Aeronave {
    private:
        string identificador;
        string tipo;
        int pasajeros;
    public:
        Aeronave(string identificador, string tipo, int pasajeros) {
            this->identificador = identificador;
            this->tipo = tipo;
            this->pasajeros = pasajeros;
        }
        
        void setIdentificador(string identificador) { this->identificador = identificador; }
        void setTipo(string tipo) { this->tipo = tipo; }
        void setPasajeros(int pasajeros) { this->pasajeros = pasajeros; }

        string getIdentificador() { return identificador; }
        string getTipo() { return tipo; }
        int getPasajeros() { return pasajeros; }

        void print() {
            cout << "Identificador: " << identificador << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Pasajeros: " << pasajeros << endl;
        }
};

class TorreDeControl {
    private:
        queue <Aeronave> cola;
        string nombreAeropuerto;
    public:
        TorreDeControl(string nombreAeropuerto) {
            this->nombreAeropuerto = nombreAeropuerto;
        }

        void solicitarAterrizaje(Aeronave tmp) {
            cola.push(tmp);
        }

        void siguienteAterrizaje() {
            if(cola.empty()) {
                cout << "No hay aterrizajes" << endl;
            }
            else {
                cola.front().print();
            }
        }

        void aterrizarAeronave() {
            if(cola.empty()) {
                cout << "No hay aterrizajes" << endl;
            } else {
                cola.front().print();
                cola.pop();
            }
        }

        void mostrarCola() {
            queue <Aeronave> colaAux = cola;
            while(!colaAux.empty()) {
                colaAux.front().print();
                colaAux.pop();
            }
        }
};

int main() {
    TorreDeControl torreDeControl("Aeropuerto Internacional de Barajas");
    Aeronave aeronave1("AA123", "Boeing 747", 200);
    Aeronave aeronave2("BA456", "Airbus A380", 500);
    Aeronave aeronave3("CA789", "Boeing 777", 300);
    torreDeControl.solicitarAterrizaje(aeronave1);
    torreDeControl.solicitarAterrizaje(aeronave2);
    torreDeControl.solicitarAterrizaje(aeronave3);
    torreDeControl.mostrarCola();
    return 0;
}

