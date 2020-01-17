//DatabaseManager.h
//@author: David Molina (40111257)
//
#pragma once
#include "Student.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"
#include <String>
#include "CourseRegistration.h"
#include "Grade.h"
class DatabaseManager
{
public:
	DatabaseManager();
	bool insert(Student*);
	bool delete_(int student_id);
	bool registering_to_Course(int, Grade);
	bool dropping_a_Course(int, std::string);
	virtual void print(int);
	virtual void print(std::string);
	~DatabaseManager();
private:
	static const int max_no_of_students = 5000;
	static const int no_of_offered_courses = 400;
	int no_of_students_enrolled;
	Student * array_student[max_no_of_students];
	CourseRegistration * arrayCourse[no_of_offered_courses];
};

