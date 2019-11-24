// Type your code here, or load an example.
#include <string>
#include <cstring>
using namespace std;

class Person {
    public:
        virtual void name(string &n);
        virtual void age(int &a);
};

class Student: public Person{
    public:
        virtual void name(string &n);
        virtual void age(int &a);
        virtual void year(int &y);
};

int main() {
    Person *p = new Student();
    string name = "yd";
    p->name(name);
    int age = 20;
    p->age(age);
    return 0;
}