#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Patient : public Person {
    private:
        string medicalHistory;
    public:
        Patient(string name, int age, string medicalHistory) : Person(name, age) {
            this->medicalHistory = medicalHistory;
        }

        void setMedicalHistory(string medicalHistory) {
            this->medicalHistory = medicalHistory;
        }

        string getMedicalHistory() {
            return medicalHistory;
        }

        void print() {
            Person::print();
            cout << "Medical History: " << medicalHistory << endl;
        }
};

int main() {
    Patient * patient = new Patient("John", 30, "None");
    patient->print();
    return 0;
}