// Type your code here, or load an example.
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Person {
    public:
        Person(void) : myName("") {}
        ~Person(void) {}
        void setName(string newName) {
            myName = newName;
        }
        void print() {
            cout << myName << endl;
        }
    private:
        string myName;
};

class Student: public Person {
    public:
        Student(void) {
            myDept = "";
        }
        ~Student(void) {}
        void setDept(string newDept) {
            myDept = newDept;
        }
        void print() {
            Person::print();
            cout << myDept << endl;
        }
    private:
        string myDept;
};

int main() {
    Student s;
    s.setDept("CS");
    s.print();
    s.setName("yd");
    s.print();
    return 0;
}
