//CourseRegistration.h
//@author: David Molina (40111257)
//
#pragma once
#include "Course.h"
#include <string>
class CourseRegistration :
	public Course
{
public:
	CourseRegistration(std::string, std::string);
	bool register_a_course(int student_id);
	bool dropping_a_course(int student_id);
	void print();
	~CourseRegistration();
private:
	static const int classSize = 60;
	int registeredtoCourse[classSize];
	int no_of_registeredStudents;
};

