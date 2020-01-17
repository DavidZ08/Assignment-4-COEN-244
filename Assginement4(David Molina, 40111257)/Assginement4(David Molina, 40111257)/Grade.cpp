//Grade.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "Grade.h"


Grade::Grade(Course c, std::string g): course(c),grade(g)
{
}


Course Grade::getCourse() const
{
	return course;
}

std::string Grade::getCharGrade() const
{
	return grade;
}

Grade::~Grade()
{
}

std::ostream & operator<<(std::ostream & os, Grade &g)
{
	os << g.course.getCourseName()<<" ("<<g.course.getCourseNumber()<<")"<< " : " << g.grade;
	return os;
}
