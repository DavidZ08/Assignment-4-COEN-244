//DataBaseManager.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "DatabaseManager.h"


DatabaseManager::DatabaseManager()
{
	for (size_t i = 0; i < max_no_of_students; i++)
	{
		array_student[i] = nullptr;
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		arrayCourse[i] = nullptr;
	}

	arrayCourse[0] = new CourseRegistration("COEN111", "Test Course"); //This is here purely for testing purposes
}

bool DatabaseManager::insert(Student *s)
{
	for (size_t i = 0; i < max_no_of_students; i++)
	{
		if (array_student[i]==nullptr)
		{
			
			if (UndergraduateStudent* us = dynamic_cast<UndergraduateStudent*>(s))
			{
				array_student[i] = new UndergraduateStudent(*us);
				no_of_students_enrolled++;
				std::cout << "Undergraduate student successfully added to array_student" << std::endl;
				return true;

			}
			else if (GraduateStudent* gs = dynamic_cast<GraduateStudent*>(s)) 
			{
				array_student[i] = new GraduateStudent(*gs);
				no_of_students_enrolled++;
				std::cout << "Graduate student successfully added to array_student" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool DatabaseManager::delete_(int student_id)
{ 
	for (size_t i = 0; i < max_no_of_students; i++)
	{
		if (array_student[i]!=nullptr)
		{
			if (array_student[i]->getId() == student_id)
			{
				delete array_student[i];
				array_student[i] = nullptr;
				no_of_students_enrolled--;
				std::cout << "Student successfully deleted" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool DatabaseManager::registering_to_Course(int id, Grade g)
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arrayCourse[i]!=nullptr)
		{
			if (arrayCourse[i]->getCourseNumber() == g.getCourse().getCourseNumber())
			{
				arrayCourse[i]->register_a_course(id);
				std::cout << "Student id successfully registered into arrayCourse" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool DatabaseManager::dropping_a_Course(int id, std::string coursenumber)
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arrayCourse[i]!=nullptr)
		{
			if (arrayCourse[i]->getCourseNumber() == coursenumber)
			{
				arrayCourse[i]->dropping_a_course(id);
				std::cout << "Course successfully dropped" << std::endl;
				return true;
			}
		}
	}
	return false;
}

void DatabaseManager::print(int id)
{
	for (size_t i = 0; i < max_no_of_students; i++)
	{
		if (array_student[i]!=nullptr)
		{
			if (array_student[i]->getId() == id)
			{
				std::cout << "Printing database knowledge of " << id << ": " << std::endl;
				array_student[i]->print();
				break;
			}
		}
	}
}

void DatabaseManager::print(std::string coursenumber)
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arrayCourse[i]!=nullptr)
		{
			if (arrayCourse[i]->getCourseNumber() == coursenumber)
			{
				std::cout << "Priting students that are in " << coursenumber << std::endl;
				arrayCourse[i]->print();
				break;
			}
		}
	}
}


DatabaseManager::~DatabaseManager()
{
	for (size_t i = 0; i < max_no_of_students; i++)
	{
		if (array_student[i]!=nullptr)
		{
			delete array_student[i];
			array_student[i] = nullptr;
		}
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arrayCourse[i]!=nullptr)
		{
			delete arrayCourse[i];
			arrayCourse[i] = nullptr;
		}
	}
}
