#include <iostream>
using namespace std;

class Passport
{
protected:
    string _name;
    string _nationality;
    int _passportNumber;
public:
    Passport()
    {
        _name = "No name";
        _nationality = "No nationality";
        _passportNumber = 0;
    }
    Passport(string name, string nationality, int passportNumber)
    {
        _name = name;
        _nationality = nationality;
        _passportNumber = passportNumber;
    }

    void Print()
    {
        cout << "Name: " << _name << endl;
        cout << "Nationality: " << _nationality << endl;
        cout << "Passport Number: " << _passportNumber << endl;
    }
    virtual void PrintForeignPassport() {}

    virtual ~Passport()
    {
        cout << "Passport destroyed" << endl;
    }
};

class ForeignPassport : public Passport
{
private:
    int _foreignPassportNumber;
    string _visa;
public:
    ForeignPassport() : Passport()
    {
        cout << "Foreign passport created" << endl;
    }

    ForeignPassport(string name, string nationality, int passportNumber, int foreignPassportNumber, string visa) : Passport(name, nationality, passportNumber)
    {
        _foreignPassportNumber = foreignPassportNumber;
        _visa = visa;
    }


    void PrintForeignPassport() override
    {
        Print();
        cout << "Foreign passport Number: " << _foreignPassportNumber << endl;
        cout << "Visa: " << _visa << endl;
    }

    ~ForeignPassport()
    {
        cout << "Foreign Passport destroyed" << endl;
    }
};

void Print(Passport* passport)
{
    if (typeid(*passport) == typeid(Passport))
    {
        passport->Print();
    }
    else if (typeid(*passport) == typeid(ForeignPassport))
    {
        passport->PrintForeignPassport();
    }
}

int main()
{
    Passport* passport = new Passport("Vova", "Ukr", 1234);
    ForeignPassport* foreignPassport = new ForeignPassport("Zenya", "Ukr", 2345, 3344, "USA");

    Print(passport);
    Print(foreignPassport);

    return 0;
}
