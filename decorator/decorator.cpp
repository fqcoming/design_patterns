
#include <iostream>
using namespace std;




// 装饰器：主要是增加现有类的功能
// 但是，增在现有类的功能，还有一个办法，就是新增加一个子类


class Car {
public:
    virtual void show() = 0;
};


class Bmw : public Car {
public:
    void show() { cout << "this is BMW"; }
};


class Audi : public Car {
public:
    void show() { cout << "this is Audi"; }
};


class Benz : public Car {
public:
    void show() { cout << "this is Benz"; }
};




class ConcreteDecorator01 : public Car {
public:
    ConcreteDecorator01(Car *p) : pCar(p) {}
    void show() {
        pCar->show();
        cout << " + cruise control";
    }
private:
    Car *pCar;
};


class ConcreteDecorator02 : public Car {
public:
    ConcreteDecorator02(Car *p) : pCar(p) {}
    void show() {
        pCar->show();
        cout << " + autobrake";
    }
private:
    Car *pCar;
};


class ConcreteDecorator03 : public Car {
public:
    ConcreteDecorator03(Car *p) : pCar(p) {}
    void show() {
        pCar->show();
        cout << " + self-navigation";
    }
private:
    Car *pCar;
};



int main() {

    Car *p1 = new ConcreteDecorator01(new Bmw());
    Car *p2 = new ConcreteDecorator02(new Audi());
    Car *p3 = new ConcreteDecorator03(new Benz());

    p1 = new ConcreteDecorator02(p1);
    p1 = new ConcreteDecorator03(p1);

    p1->show();
    cout << endl;

    p2->show();
    cout << endl;

    p3->show();
    cout << endl;

    return 0;
}






