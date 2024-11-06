#include <iostream>
using namespace std;

class Pet
{
protected:
	string _name;
	int _age;
public:
	Pet()
	{
		_name = "No name";
		_age = 0;
	}
	Pet(string name, int age)
	{
		_name = name;
		_age = age;
	}

	virtual void Print()
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	virtual ~Pet() {}
};

class Cat : public Pet
{
public:
	Cat() : Pet() {}
	Cat(string name, int age) : Pet(name, age) {}

	void Print() override
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	~Cat() {}
};

class Dog : public Pet
{
public:
	Dog() : Pet() {}
	Dog(string name, int age) : Pet(name, age) {}

	void Print() override
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	~Dog() {}
};

class Parrot : public Pet
{
public:
	Parrot() : Pet() {}
	Parrot(string name, int age) : Pet(name, age) {}

	void Print() override
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	~Parrot() {}
};

void Print(Pet* pet)
{
	pet->Print();
}

int main() {

	Pet* cat = new Cat("Tom", 3);
	Pet* dog = new Dog("Bob", 5);
	Pet* parrot = new Parrot("Jerry", 2);

	Print(cat);
	cout << endl;
	Print(dog);
	cout << endl;
	Print(parrot);

	delete cat;
	delete dog;
	delete parrot;


	return 0;
}