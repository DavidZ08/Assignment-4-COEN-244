//CourseRegistration.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "CourseRegistration.h"
#include <iostream>



CourseRegistration::CourseRegistration(std::string cNo, std::string cNa): Course (cNo,cNa)
{
	for (size_t i = 0; i < classSize; i++)
	{
		registeredtoCourse[i] = 0;
	}
	no_of_registeredStudents = 0;
}

bool CourseRegistration::register_a_course(int student_id)
{
	for (size_t i = 0; i < classSize; i++)
	{
		if (registeredtoCourse[i]==0)
		{
			registeredtoCourse[i] = student_id;
			no_of_registeredStudents++;
			return true;
		}
	}
	return false;
}

bool CourseRegistration::dropping_a_course(int student_id)
{
	for (size_t i = 0; i < classSize; i++)
	{
		if (student_id==registeredtoCourse[i])
		{
			registeredtoCourse[i] = 0;
			no_of_registeredStudents--;
			return true;
		}
	}
	return false;
}

void CourseRegistration::print()
{
	std::cout << "number of registered students: " << no_of_registeredStudents << std::endl;
	for (size_t i = 0; i < classSize; i++)
	{
		std::cout << registeredtoCourse[i] << " ";
	}
	std::cout << std::endl;
}



CourseRegistration::~CourseRegistration()
{
}
