// Assginement4(David Molina, 40111257).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Time.h"
#include "Course.h"
#include "CourseRegistration.h"
#include "CourseSchedule.h"
#include "Grade.h"
#include "UndergraduateStudent.h"
#include "DatabaseManager.h"
using namespace std;

int main()
{
	cout << "*****Testing Time class*****" << endl;
	Time test1 = Time(1, 1);
	Time test2 = Time(1, 1);
	Time test3 = Time(2, 2);
	cout << "Operator << overloading test on test1: ";
	cout << test1;
	cout << endl;
	cout << "Operator == overloading test on test1 and test 2: ";
	cout << (test1 == test2);
	cout << endl;
	cout << "Operator == overloading test on test1 and test 3: ";
	cout << (test1 == test3);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing Course class*****" << endl;
	Course courseTest = Course("COEN244", "Programming Methodology II", "COEN243");
	courseTest.print();
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing CourseRegistration class*****" << endl;
	CourseRegistration cRTest = CourseRegistration("COEN 244", "Programming Methodology II");
	cRTest.print();
	cRTest.register_a_course(4000000);
	cRTest.print();
	cRTest.dropping_a_course(4000000);
	cRTest.print();
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing CourseSchedule class*****" << endl;
	Time time1CsTest = Time(1, 1);
	Time time2CsTest = Time(2, 2);
	Course courseCsTest = Course("COEN243", "Programming Methodology I", "test");
	CourseSchedule cSTest = CourseSchedule(courseCsTest, time1CsTest, time2CsTest);
	cSTest.print();
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing Grade class*****" << endl;
	Course courseGtest = Course("ELEC273", "Basic circuit analysis", "test2");
	Grade gTest = Grade(courseGtest, "A");
	cout << "Operator << overloading test on gTest: ";
	cout << gTest << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing UndergraduateStudent class*****" << endl;
	UndergraduateStudent ugTest = UndergraduateStudent("TestStudent", 1234567);

	cout << "+++++Adding a course without a prereq+++++" << endl;
	Course courseUgTest = Course("COEN243", "Programming Methodology I", "");
	Grade gradeUgTest = Grade(courseUgTest, "A");
	Time tUg1 = Time(1, 1);
	Time tUg2 = Time(2, 2);
	ugTest.register_a_course(gradeUgTest, tUg1, tUg2);

	cout << "+++++Adding a course with a conflicting schedule++++++" << endl;
	Course courseUgTest1 = Course("ELEC273", "Basic circuit analysis", "");
	Grade gradeUgTest1 = Grade(courseUgTest1, "A");
	Time tUg3 = Time(1, 1);
	Time tUg4 = Time(2, 2);
	ugTest.register_a_course(gradeUgTest1, tUg2, tUg3);

	cout << "+++++Adding a course with a prerequisite successfully passed+++++" << endl;
	Course courseUgTest2 = Course("COEN244", "Programming Methodology II", "COEN243");
	Grade gradeUgTest2 = Grade(courseUgTest2, "A");
	Time tUg5 = Time(3, 3);
	Time tUg6 = Time(4, 4);
	ugTest.register_a_course(gradeUgTest2, tUg5, tUg6);

	cout << "+++++Adding a course with a failed prerequisite+++++" << endl;
	Course courseUgTest3 = Course("ENGR213", "Ordinary differential equations", "");
	Grade gradeUgTest3 = Grade(courseUgTest3, "F");
	Time tUg7 = Time(5, 5);
	Time tUg8 = Time(6, 6);
	ugTest.register_a_course(gradeUgTest3, tUg7, tUg8);

	Course courseUgTest4 = Course("COEN231", "Discrete mathematics", "ENGR213");
	Grade gradeUgTest4 = Grade(courseUgTest4, "A");
	Time tUg9 = Time(7, 7);
	Time tUg10 = Time(8, 8);
	ugTest.register_a_course(gradeUgTest4, tUg9, tUg10);

	cout << "+++++Adding a course that was taken and failed+++++" << endl;
	Course courseUgTest5 = Course("ENGR213", "Ordinary differential equations", "");
	Grade gradeUgTest5 = Grade(courseUgTest5, "A");
	Time tUg11 = Time(9, 9);
	Time tUg12 = Time(10, 10);
	ugTest.register_a_course(gradeUgTest5, tUg11, tUg12);

	ugTest.dropping_a_course("COEN243");

	ugTest.print();

	//Testing the GraduateStudent class would be redundant since the methods are exactly the same except for "i<max_no_of_graduate_courses" in the for loops

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "*****Testing the DatabaseManager class*****" << endl;
	DatabaseManager dbM = DatabaseManager();
	UndergraduateStudent ugStudent = UndergraduateStudent("Test undergrad", 1234567);
	GraduateStudent gradStudent = GraduateStudent("Test grad", 1111111);
	dbM.insert(&ugStudent);
	dbM.insert(&gradStudent);
	dbM.delete_(1111111);
	Course dbMcourse = Course("COEN111", "Test Course", "");
	Grade dbMGrade = Grade(dbMcourse, "A");
	dbM.registering_to_Course(ugStudent.getId(), dbMGrade);
	dbM.print(ugStudent.getId());
	dbM.print("COEN111");
	dbM.dropping_a_Course(ugStudent.getId(), "COEN111");

	return 0;
}

