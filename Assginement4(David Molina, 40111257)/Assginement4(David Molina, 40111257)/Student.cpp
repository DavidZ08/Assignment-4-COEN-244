//Student.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "Student.h"


Student::Student()
{
}

Student::Student(std::string name, int id): studentName(name), studentId(id)
{
}


void Student::print()
{
	std::cout << "Name : " << studentName << " Id: " << studentId << std::endl;
}

std::string Student::getName()
{
	return studentName;
}

int Student::getId()
{
	return studentId;
}

Student::~Student()
{
}
