//Course.h
//@author: David Molina (40111257)
//
#pragma once
#include <string>
#include <iostream>
class Course
{
public:
	Course();
	Course(std::string = "", std::string = "", std::string = "");
	virtual void print();
	std::string getCourseNumber()const;
	std::string getCourseName()const;
	std::string getCoursePreReq()const;
	~Course();
private:
	std::string courseNumber;
	std::string courseName;
	std::string coursePreReq;
};

