//GraduateStudent.h
//@author: David Molina (40111257)
//
#pragma once
#include "Student.h"
#include <string>
#include "Grade.h"
#include <iostream>
class GraduateStudent :
	public Student
{
public:
	GraduateStudent(std::string = "", int = 0);
	bool Student::checking_a_course(std::string coursenumber);
	bool checking_a_course_and_if_passed(std::string coursenumber);
	bool Student::register_a_course(Grade,Time,Time);
	bool Student::dropping_a_course(std::string coursenumber);
	bool adding_to_schedule(Course, Time, Time);
	virtual void print();
	~GraduateStudent();
private:
	static const int max_number_of_graduatecourses = 12;
	Grade* studentRecord[max_number_of_graduatecourses];
};

