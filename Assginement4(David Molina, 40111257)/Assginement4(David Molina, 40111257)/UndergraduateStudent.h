//UndergraduateStudent.h
//@author: David Molina (40111257)
//
#pragma once
#include "Student.h"
#include <string>
#include <iostream>
#include "CourseSchedule.h"
#include "Course.h"
#include "Time.h"
class UndergraduateStudent :
	public Student
{
public:
	UndergraduateStudent(std::string = "", int = 0);
	bool Student::checking_a_course(std::string coursenumber);
	bool checking_a_course_and_if_passed(std::string coursenumber);
	bool Student::register_a_course(Grade, Time, Time);
	bool Student::dropping_a_course(std::string coursenumber);
	bool adding_to_schedule(Course, Time, Time);
	virtual void print();
	~UndergraduateStudent();
private:
	static const int max_no_of_courses = 40;
	Grade *studentRecord[max_no_of_courses];
};

