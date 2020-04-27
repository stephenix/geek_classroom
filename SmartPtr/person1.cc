#include <iostream>
#include <memory>
#include <string>
using namespace std;

// auto_ptr usage
class Person {
public:
    Person(string n) : name(n) {
        cout << "Construct." << endl;
    }
    ~Person() {
        cout << "Destruct." << endl;
    }
    void Speak() {
        cout << "Hello " << name << endl;
    }

private:
    string name;
};

int main() {
    auto_ptr<Person> person(new Person("stephen")); 
    person->Speak();
    return 0;
}
