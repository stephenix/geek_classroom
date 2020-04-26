#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Shape" << endl;
    }
    // here must be virtual function
    // or cannot release subclass alloc space
    virtual ~Shape() {
        cout << "Destruct Shape" << endl;
    }
};
class Circle : public Shape {
public:
    Circle() {
        cout << "Circle" << endl;
    }
    ~Circle() {
        cout << "Destruct Circle" << endl;
    }
};
class Triangle : public Shape {
public:
    Triangle() {
        cout << "Triangle" << endl;
    }
    ~Triangle() {
        cout << "Destruct Triangle" << endl;
    }
};

class ShapeWrapper {
public:
    explicit ShapeWrapper(Shape *ptr = nullptr) : ptr_(ptr) {

    }
    ~ShapeWrapper() {
        delete ptr_;
    }
    Shape* Get() const {
        return ptr_;
    }
private:
    Shape *ptr_;
};
enum class ShapeType {
    circle,
    triangle,
};
Shape* CreateShape(ShapeType type) {
    switch(type) {
        case ShapeType::circle:
            return new Circle();
        case ShapeType::triangle:
            return new Triangle();
    }
}

int main() {
    ShapeWrapper rapper(CreateShape(ShapeType::triangle)); 
    return 0;
}
