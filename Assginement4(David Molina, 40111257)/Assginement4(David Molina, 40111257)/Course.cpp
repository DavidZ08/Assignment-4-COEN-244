//Course.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "Course.h"


Course::Course()
{
}

Course::Course(std::string coursenumber, std::string coursename, std::string courseprereq):courseNumber(coursenumber),courseName(coursename),coursePreReq(courseprereq)
{
}

void Course::print()
{
	std::cout << "Course name: " << courseName << " Course number: " << courseNumber <<" Course prerequisite: "<<coursePreReq;
}


std::string Course::getCourseNumber() const
{
	return courseNumber;
}

std::string Course::getCourseName() const
{
	return courseName;
}

std::string Course::getCoursePreReq() const
{
	return coursePreReq;
}

Course::~Course()
{
}
