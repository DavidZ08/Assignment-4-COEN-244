//Grade.h
//@author: David Molina (40111257)
//
#pragma once
#include <string>
#include "Course.h"
#include <iostream>
class Grade
{
public:
	Grade(Course, std::string);
	friend std::ostream &operator << (std::ostream &, Grade&);
	Course getCourse()const;
	std::string getCharGrade()const;
	~Grade();
private:
	Course course;
	std::string grade;
};

