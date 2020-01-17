//Student.h
//@author: David Molina (40111257)
//
#pragma once
#include <string>
#include "Grade.h"
#include "CourseSchedule.h"
#include <iostream>
#include "Time.h"
class Student
{
public:
	Student();
	Student(std::string = "", int = 0);
	virtual bool checking_a_course(std::string coursenumber)=0;
	virtual bool register_a_course(Grade,Time,Time)=0;
	virtual bool dropping_a_course(std::string coursenumber)=0;
	virtual void print();
	std::string getName();
	int getId();
	~Student();
private:
	std::string studentName;
	int studentId;
protected:
	static const int no_of_offered_courses = 400;
	CourseSchedule* arraySchedule[no_of_offered_courses];
};

