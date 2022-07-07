#include <iostream>
#include "roster.h"
using namespace std;

int main() {

	int classSize = 5;

	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@mailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Tyler,Darby,tdarb15@wgu.edu,27,15,20,12,SOFTWARE",
	};

	Roster* classRoster = new Roster(classSize);
	int i = 0;
	while (i < classSize) {
		classRoster->parseThenAddSection(studentData[i]);
		i++;
		
	}

	cout << "Course Title: C867 Scripting and Programming - Applications" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID: 007081226" << endl;
	cout << "Student Name: Tyler Darby" << endl;
	cout << "--------------------------------------" << endl;

	cout << "printAll() Function:" << endl;
	classRoster->printAll();
	cout << "--------------------------------------" << endl;

	cout << "printInvalidEmails() Function:" << endl;
	classRoster->printInvalidEmails();
	cout << "--------------------------------------" << endl;

	cout << "Looping through each student and printAverageDaysInCourse() Function: " << endl;
	int j = 0;
	while (j < classSize) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(j)->getstudentID());
		j++;
	}
	cout << "--------------------------------------" << endl;

	cout << "printByDegreeProgram(SOFTWARE); Function: " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "--------------------------------------" << endl;

	cout << "remove('A3') function happens here " << endl;
	classRoster->remove("A3");
	cout << "--------------------------------------" << endl;

	cout << "printAll() Function: " << endl;
	classRoster->printAll();
	cout << "--------------------------------------" << endl;

	cout << "remove('A3') Function with no mathcing student" << endl;
	classRoster->remove("A3");
	cout << "--------------------------------------" << endl;

	system("pause");
	
	return 0;
}
