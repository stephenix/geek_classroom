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
    SmartPtr() : ptr(0) {
        ref_cnt = new int(0);
        (*ref_cnt) ++;
    }
    SmartPtr(T *p) : ptr(p){
        ref_cnt = new int(0);
        (*ref_cnt) ++;
    }
    ~SmartPtr() {
        if (-- (*ref_cnt) == 0) {
            delete ref_cnt;
            delete ptr;
        } else {
            cout << "ref_cnt: " << *ref_cnt << endl;
        }
    }
    SmartPtr(const SmartPtr<T>& sp);
    SmartPtr<T>& operator=(const SmartPtr<T>& sp);
    T& operator*();
    T* operator->();
private:
    T *ptr;
    int *ref_cnt;
};

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp) : ptr(sp.ptr), ref_cnt(sp.ref_cnt){
    (*ref_cnt) ++;
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sp) {
    ptr = sp.ptr;
    ref_cnt = sp.ref_cnt;
    (*ref_cnt) ++;
    return *this;
}

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
    SmartPtr<Person> r;
    //person->Speak();
    sptr->Speak();
    {
        SmartPtr<Person> q = sptr;
        q->Speak();
        r = q;
        SmartPtr<Person> ss(r);
        ss->Speak();
    }
    r->Speak();
    return 0;
}
