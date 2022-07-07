#include "student.h"
#include <string>
#include <iostream>
using namespace std;

//Student class functions 
Student::Student() //Empty constructor
{
	this -> studentID = "";
	this -> firstName = "";
	this -> lastName = "";
	this -> email = "";
	this -> age = 0;
	this -> daysToComplete = new int[tableSize];
	for (int i = 0; i < tableSize; i++) this -> daysToComplete[i] = 0;
	this -> degProgram = NETWORK;

}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degProgram)
{
	this -> studentID = studentID;
	this -> firstName = firstName;
	this -> lastName = lastName;
	this -> email = email;
	this -> age = age;
	this -> daysToComplete = new int[tableSize];
	for (int i = 0; i < tableSize; i++) this -> daysToComplete[i] = daysToComplete[i];
	this -> degProgram = degProgram;
}

//Setters
void Student::setID(string studentID) { this -> studentID = studentID; }

void Student::setFirst(string firstName) { this -> firstName = firstName; }

void Student::setLast(string lastName) { this -> lastName = lastName; }

void Student::setEmail(string email) { this -> email = email; }

void Student::setAge(int age) { this->age = age; }

void Student::setDaysToComplete(int daysToComplete[])
{

	int i = 0;
	while (i < tableSize) {
		this -> daysToComplete[i] = daysToComplete[i];
		i++;
	}
}

void Student::setDegreeProgram(DegreeProgram degProgram)
{
	this -> degProgram = degProgram;
}

//Getters
string Student::getstudentID(){	return studentID;}

string Student::getFirstName(){	return firstName;}

string Student::getLastName(){	return lastName;}

string Student::getemail(){	return email;}

int Student::getAge(){	return age;}

int* Student::getDaysToComplete(){
	return daysToComplete; 
}

DegreeProgram Student::getDegreeProgram(){	return degProgram;}



void Student::print()
{	
	int i = 0;
	cout << getstudentID() << '\t';
	cout << "First Name: " << '\t';
	cout << getFirstName() << '\t';
	cout << "Last Name: " << '\t';
	cout << getLastName() << '\t';
	cout << "Age: " << '\t';
	cout << getAge() << '\t';
	int* daysToComplete = getDaysToComplete();
	cout << "daysInCourse: " << "{";
	while (i < 3) {
		if (i == 2) {
			cout << daysToComplete[i];
			i++;
		}
		else {
			cout << daysToComplete[i] << ", ";
			i++;
		}
	}
	cout << "}" << '\t';
	cout << "Degree Program: " << DegreeProgramStrings[getDegreeProgram()] << endl;
}

//Destructor
Student::~Student()
{
	if (daysToComplete != nullptr)
	{
		delete[] daysToComplete;
		daysToComplete = nullptr;
	}
}