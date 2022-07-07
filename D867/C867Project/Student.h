#pragma once
#include "degree.h"
#include <string>
#include <iostream>
;using namespace std;

//Student class definition 
class Student
{
public:
	const static int tableSize = 3;

private: 
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysToComplete;
	DegreeProgram degProgram;

public:
	//default constructor
	Student();

	//full constructor
	Student(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysToComplete[],
		DegreeProgram degProgram
	);

	//getters
	string getstudentID();
	string getFirstName();
	string getLastName();
	string getemail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//setters
	void setID(string studentID);
	void setFirst(string firstName);
	void setLast(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degProgram);
	void print();

	//desturctor
	~Student();

};
