// Nota: Se intentará hacer la mayor parte del código en inglés, así lograr tener una buena práctica y compatiblizar el aprendizaje de ambos mundos.
// Nota2: El proyecto será subido mediante un commit a github, donde se podrá revisar respectivamente.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Pacient {
    private:
        string name;
        string id;
        bool cough;
        bool fever;
        bool vomit;
    public:
        Pacient(string name, string id, bool cough, bool fever, bool vomit) {
            this->name = name;
            this->id = id;
            this->cough = cough;
            this->fever = fever;
            this->vomit = vomit;
        }

        void setName(string name) { this->name = name; }
        void setId(string id) { this->id = id; }
        void setCough(bool cough) { this->cough = cough; }
        void setFever(bool fever) { this->fever = fever; }
        void setVomit(bool vomit) { this->vomit = vomit; }

        string getName() { return name; }
        string getId() { return id; }
        bool getCough() { return cough; }
        bool getFever() { return fever; }
        bool getVomit() { return vomit; }

        int getPriority() {
            int priority = 0;
            if (cough) priority++;
            if (fever) priority++;
            if (vomit) priority++;
            return priority;
        }
        
        void cure() {
            cough = false; fever = false; vomit = false;
        }

        void print() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Cough: " << cough << endl;
            cout << "Fever: " << fever << endl;
            cout << "Vomit: " << vomit << endl;
        }
};

class Hospital {
    private:
        queue <Pacient> low; // 1
        queue <Pacient> medium; // 2
        queue <Pacient> high; // 3}
    public:
        void addPacient(Pacient pacient) {
            switch (pacient.getPriority()) {
                case 1:
                    low.push(pacient);
                    break;
                case 2:
                    medium.push(pacient);
                    break;
                case 3:
                    high.push(pacient);
                    break;
                default:
                    cout << "Not priority" << endl;
                    break;
            }
        }

        void attendPacient() {
            if (!high.empty()) {
                Pacient pacient = high.front();
                high.pop();
                cout << "Gravity level: " << pacient.getPriority() << endl;
                pacient.cure();
                cout << "Attending pacient: " << pacient.getName() << endl;
            }
            else if (!medium.empty()) {
                Pacient pacient = medium.front();
                medium.pop();
                cout << "Gravity level: " << pacient.getPriority() << endl;
                pacient.cure();
                cout << "Attending pacient: " << pacient.getName() << endl;
            }
            else if (!low.empty()) {
                Pacient pacient = low.front();
                low.pop();
                cout << "Gravity level: " << pacient.getPriority() << endl;
                pacient.cure();
                cout << "Attending pacient: " << pacient.getName() << endl;
            }
            else {
                cout << "No pacients" << endl;
            }
        }

        void roundAttention(int n) {
               cout << "Initiating round attention" << endl;
               for(int i = 0; i < n; i++){
                   if(high.empty() && medium.empty() && low.empty()){
                        cout << "No pacients" << endl;
                        break;
                   }
                   cout << "Round " << i + 1 << endl;
                   attendPacient();
               }
        }

        void showQueueStatus() {
            cout << "=== Queue Status ===" << endl;
            cout << "High priority: " << high.size() << " patients" << endl;
            cout << "Medium priority: " << medium.size() << " patients" << endl;
            cout << "Low priority: " << low.size() << " patients" << endl;
            cout << "Total: " << (high.size() + medium.size() + low.size()) << " patients" << endl;
            cout << "====================" << endl;
        }
};

// Function main to test the code
int main() {
    // Create some patients
    Pacient p1("Anakin Skywalker", "12345678-9", false, false, true); // Priority 1 // left arm
    Pacient p2("Obi-Wan Kenobi", "98765432-1", true, true, false); // Priority 2
    Pacient p3("Padme Amidala", "45678912-3", true, true, true); // Priority 3 // is dead
    Pacient p4("R2D2", "45678912-3", false, true, false); // Priority 1
    Pacient p5("Darth Vader", "45678912-3", true, true, true); // Priority 3  // very very bad jaja

    // Create hospital
    Hospital hospital;

    // Add patients to the hospital
    hospital.addPacient(p1);
    hospital.addPacient(p2);
    hospital.addPacient(p3);
    hospital.addPacient(p4);
    hospital.addPacient(p5);

    // Show queue status initial
    hospital.showQueueStatus();
    // Round attention
    hospital.roundAttention(5);
    // Show queue status final
    hospital.showQueueStatus();
}

// Fonts: https://cplusplus.com/reference/vector/vector/