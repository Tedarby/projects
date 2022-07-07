#include <iostream>
#include "roster.h"
using namespace std;

Roster::Roster()
{
	this -> maxSize = 0;
	this -> lastIndex = -1;
	this -> classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
	this -> maxSize = maxSize;
	this -> lastIndex = -1;
	this -> classRosterArray = new Student * [maxSize];
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
{
	int daysToComplete[3];

	daysToComplete[0] = daysInCourse1;
	daysToComplete[1] = daysInCourse2;
	daysToComplete[2] = daysInCourse3;

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeprogam);
}

Student* Roster::getStudent(int index)
{
	return classRosterArray[index];
}

void Roster::printAll()
{
	int i = 0;
	while (i <= this->lastIndex) {
		(this->classRosterArray)[i]->print();
		i++;
	}
}

bool Roster::remove(string ID)
{
	bool found = false;
	int i = 0;
	while (i <= lastIndex) {
		if (this->classRosterArray[i]->getstudentID() == ID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
		i++;
	}
	if (found == false)
	{
		cout << "The Student ID of " << ID << " could not be found." << endl;
	}
	return found;
}

void Roster::printAverageDaysInCourse(string sID)
{
	bool found = false;
	int i = 0;
	while (i <= lastIndex) {
		if (this->classRosterArray[i]->getstudentID() == sID)
		{
			int* ptr = classRosterArray[i]->getDaysToComplete();
			found = true;
			cout << "Average number of days left in class for " << sID << " is " << (ptr[0] + ptr[1] + ptr[2]) / 3 << "\n";
		}
		i++;
	}
	if (found == false) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	cout << "These emails are invalid:\n";
	int i = 0;
	while (i < 5) {
		string email = classRosterArray[i]->getemail();

		if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
			cout << email << endl;
		i++;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	cout << "Students registered for the " << DegreeProgramStrings[degreeprogram] << " degree program" << endl;
	int i = 0;
	while (i <= lastIndex) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) 
		{
			this->classRosterArray[i]->print();
		}
		i++;
	}
}

void Roster::parseThenAddSection(string section)
{


	if (lastIndex < maxSize)
	{
		lastIndex++;
	}
	this->classRosterArray[lastIndex] = new Student();

	//read the students ID
	int long parseEnd = section.find(",");
	classRosterArray[lastIndex]->setID(section.substr(0, parseEnd));

	//read the firstName of student
	int long parseBegin = parseEnd + 1;
	parseEnd = section.find(",", parseBegin);
	classRosterArray[lastIndex]->setFirst(section.substr(parseBegin, parseEnd - parseBegin));

	//read the lastName of student
	parseBegin = parseEnd + 1;
	parseEnd = section.find(",", parseBegin);
	classRosterArray[lastIndex]->setLast(section.substr(parseBegin, parseEnd - parseBegin));

	//read the email of student
	parseBegin = parseEnd + 1;
	parseEnd = section.find(",", parseBegin);
	classRosterArray[lastIndex]->setEmail(section.substr(parseBegin, parseEnd - parseBegin));

	//read the age of student
	parseBegin = parseEnd + 1;
	parseEnd = section.find(",", parseBegin);
	int x = stoi(section.substr(parseBegin, parseEnd - parseBegin));
	classRosterArray[lastIndex]->setAge(x);

	//read daysInCourse 1-3
	int parseArr[3];
	int i = 0;
	while (i < 3) {
		parseBegin = parseEnd + 1;
		parseEnd = section.find(",", parseBegin);
		parseArr[i] = stoi(section.substr(parseBegin, parseEnd - parseBegin));
		i++;
	}

	//set the days left in course
	classRosterArray[lastIndex]->setDaysToComplete(parseArr);

	//read the degree program
	parseBegin = parseEnd + 1;
	if (section[parseBegin] == 'N')
	{
		classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
	}
	else if (section[parseBegin] == 'S' && section[parseBegin + 1] == 'E')
	{
		classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
	}
	else if (section[parseBegin] == 'S' && section[parseBegin + 1] == 'O') {
		classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
	}
	else
	{
		cerr << "Not a valid Degree Program, Now Exiting..." << endl;
		exit(-1);
	}
}

Roster::~Roster()
{
	int i = 0;
	while (i <= 4) {
		delete this->classRosterArray[i];
		i++;
	}
	delete this;
}