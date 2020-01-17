//UndergraduateStudent.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "UndergraduateStudent.h"




bool UndergraduateStudent::checking_a_course(std::string coursenumber)
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i] != nullptr)
		{
			if (studentRecord[i]->getCourse().getCourseNumber() == coursenumber)
			{
				return true;
			}
		}
	}
	return false;
}

bool UndergraduateStudent::checking_a_course_and_if_passed(std::string coursenumber)
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i] != nullptr)
		{			
			 if (studentRecord[i]->getCourse().getCourseNumber() == coursenumber)
			 {
				if (studentRecord[i]->getCharGrade() == "F" || studentRecord[i]->getCharGrade() == "D")
				{
					return false;
				}
				else
				{
					return true;
				}
			 }
		}
	}
	return false;
}

bool UndergraduateStudent::register_a_course(Grade grade, Time t1, Time t2)
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i] == nullptr)
		{
			if (grade.getCourse().getCoursePreReq()=="")
			{
				if (checking_a_course_and_if_passed(grade.getCourse().getCourseName()))
				{
					std::cout<< "There was a problem adding your course to the studentrecord and schedule: courses at the same time? Prerequesite?Already passed course?"<<std::endl;
					return false;
				}
				else
				{
					if (adding_to_schedule(grade.getCourse(),t1,t2))
					{
						studentRecord[i] = new Grade(grade);
						std::cout << "Added course to schedule and record successfully" << std::endl;
						return true;
					}
					else
					{
						std::cout << "There was a problem adding your course to the studentrecord and schedule: courses at the same time? Prerequesite?Already passed course?" << std::endl;
						return false;
					}
					
				}
			}
			else
			{
				if (checking_a_course_and_if_passed(grade.getCourse().getCoursePreReq()))
				{
					if (checking_a_course_and_if_passed(grade.getCourse().getCourseNumber()))
					{
						std::cout << "There was a problem adding your course to the studentrecord and schedule: courses at the same time? Prerequesite?Already passed course?" << std::endl;
						return false;
					}
					else
					{
						if (adding_to_schedule(grade.getCourse(), t1, t2))
						{
							studentRecord[i] = new Grade(grade);
							std::cout << "Added course to schedule and record successfully" << std::endl;
							return true;
						}
						else
						{
							std::cout << "There was a problem adding your course to the studentrecord and schedule: courses at the same time? Prerequesite?Already passed course?" << std::endl;
							return false;
						}
					}
				}
				else
				{
					std::cout << "There was a problem adding your course to the studentrecord and schedule: courses at the same time? Prerequesite?Already passed course?" << std::endl;
					return false;
				}
			}
		}
	}
	return false;
}

bool UndergraduateStudent::dropping_a_course(std::string coursenumber)
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i] != nullptr)
		{
			if (studentRecord[i]->getCourse().getCourseNumber() == coursenumber)
			{
				delete studentRecord[i];
				studentRecord[i] = nullptr;
				std::cout << "#####Deleted successfully#####" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool UndergraduateStudent::adding_to_schedule(Course c, Time t1, Time t2)
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i]!=nullptr)
		{
			if ((arraySchedule[i]->getTime1() == t1) ||(arraySchedule[i]->getTime2() == t2)|| (arraySchedule[i]->getTime1() == t2) || (arraySchedule[i]->getTime2() == t1))
			{
				return false;
			}
		}
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i]==nullptr)
		{
			arraySchedule[i] = new CourseSchedule(c, t1, t2);
			return true;
		}
	}
}

void UndergraduateStudent::print() 
{     
	Student::print();
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i]!=nullptr)
		{
			std::cout << *studentRecord[i] << std::endl;
		}
	}
}

UndergraduateStudent::UndergraduateStudent(std::string name, int id): Student(name,id)
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		studentRecord[i] = nullptr;
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		arraySchedule[i] = nullptr;
	}
}


UndergraduateStudent::~UndergraduateStudent()
{
	for (size_t i = 0; i < max_no_of_courses; i++)
	{
		if (studentRecord[i]!=nullptr)
		{
			delete studentRecord[i];
			studentRecord[i] = nullptr;
		}
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i] != nullptr)
		{
			delete arraySchedule[i];
			arraySchedule[i] = nullptr;
		}
	}
}
