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

template <typename T>
class SmartPtr {
public:
    SmartPtr(T *p) : ptr(p){
    }
    ~SmartPtr() {
        delete ptr;
    }
    T& operator*();
    T* operator->();
private:
    T *ptr;
};

template <typename T>
T& SmartPtr<T>::operator*() {
    return *ptr;
}

template <typename T>
T* SmartPtr<T>::operator->() {
    return ptr;
}

int main() {
    //auto_ptr<Person> person(new Person("stephen")); 
    SmartPtr<Person> sptr(new Person("stephen"));
    //person->Speak();
    sptr->Speak();
    return 0;
}
