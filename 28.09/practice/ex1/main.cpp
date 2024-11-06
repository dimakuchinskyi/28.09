#include <iostream>
using namespace std;

class Student 
{
protected:
	string _name;
	int _age;
public:
	Student()
	{
		_name = "No name";
		_age = 0;
	}
	Student(string name, int age)
	{
		_name = name;
		_age = age;
	}

	virtual void Print()
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	virtual ~Student()
	{
		cout << "Student deleted" << endl;
	}
};

class Aspirant : public Student
{
public:
	Aspirant() : Student()
	{
		cout << "Aspirant created" << endl;
	}
	Aspirant(string name, int age) : Student(name, age)
	{
		cout << "Aspirant created with parametrs" << endl;
	}

	void Print() override
	{
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}

	~Aspirant()
	{
		cout << "Aspirant destroyed" << endl;
	}
};

void Print(Student* student)
{
	student->Print();
}

int main() {

	Student* aspirant = new Aspirant("Vova", 5);
	Aspirant* aspirant2 = new Aspirant("Alex", 8);
	Student* student = new Student("Zenya", 15);

	Print(aspirant);
	Print(aspirant2);
	Print(student);

	delete aspirant;
	return 0;
}