#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string _type;
    double _speed; 
    double _costPerKm; 
public:
    Transport()
    {
        _type = "No type";
        _speed = 0;
        _costPerKm = 0;
    }
    Transport(string type, double speed, double costPerKm)
    {
        _type = type;
        _speed = speed;
        _costPerKm = costPerKm;
    }

    virtual double CalculateTime(double distance) {
        return distance / _speed;
    }

    virtual double CalculateCost(double distance, double weight) {
        return distance * _costPerKm;
    }

    virtual void Print() {
        cout << "Transport type: " << _type << endl;
    }

    virtual ~Transport() {
        cout << "Transport destroyed" << endl;
    }
};

class Car : public Transport {
public:
    Car() : Transport() {}
    Car(string type, double speed, double costPerKm) : Transport(type, speed, costPerKm) {}

    double CalculateCost(double distance, double weight) override {
        return (distance * _costPerKm) + (weight * 1);
    }

    void Print() override {
        Transport::Print();
    }

    ~Car() {
        cout << "Car destroyed" << endl;
    }
};

class Bicycle : public Transport {
public:
    Bicycle() : Transport() {}
    Bicycle(string type, double speed, double costPerKm) : Transport(type, speed, costPerKm) {}

    double CalculateCost(double distance, double weight) override {
        if (weight > 10) {
            cout << "Too heavy for a bicycle!" << endl;
            return -1;
        }
        return distance * _costPerKm;
    }

    void Print() override {
        Transport::Print();
    }

    ~Bicycle() {
        cout << "Bicycle destroyed" << endl;
    }
};


class Cart : public Transport {
public:
    Cart() : Transport() {}
    Cart    (string type, double speed, double costPerKm) : Transport(type, speed, costPerKm) {}

    double CalculateCost(double distance, double weight) override {
        return distance * _costPerKm;
    }

    void Print() override {
        Transport::Print();
    }

    ~Cart() {
        cout << "Cart destroyed" << endl;
    }
};

void Calculate(Transport* vehicle, double distance, double weight) {
    vehicle->Print();
    double time = vehicle->CalculateTime(distance);
    double cost = vehicle->CalculateCost(distance, weight);
    cout << "Time to travel " << distance << " km: " << time << " hours" << endl;
    if (cost >= 0) {
        cout << "Cost to transport " << weight << " kg: $" << cost << endl;
    }
    cout << endl;
}

int main() {
    double distance = 50;
    double weight = 8;

    Transport* car = new Car("Car", 80, 6);
    Transport* bicycle = new Bicycle("Bicycle", 10, 2);
    Transport* cart = new Cart("Cart", 8, 10);

    Calculate(car, distance, weight);
    Calculate(bicycle, distance, weight);
    Calculate(cart, distance, weight);
   

    return 0;
}
