#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person {
public:
    Person(string n) : name(n) {
        cout << "Construct." << endl;
    }
    ~Person() {
        cout << "Destruct." << endl;
    }
    void Speak() {
        cout << "Hello2 " << name << endl;
    }

private:
    string name;
};

class SmartPtr {
public:
    SmartPtr(Person *p) : ptr(p){
    }
    ~SmartPtr() {
        delete ptr;
    }
    Person& operator*() {
        return *ptr;
    }
    Person* operator->() {
        return ptr;
    }
private:
    Person *ptr;
};

int main() {
    //auto_ptr<Person> person(new Person("stephen")); 
    SmartPtr sptr(new Person("stephen"));
    //person->Speak();
    sptr->Speak();
    return 0;
}
