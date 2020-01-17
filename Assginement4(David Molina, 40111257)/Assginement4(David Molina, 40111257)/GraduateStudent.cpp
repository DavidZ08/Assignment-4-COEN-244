//GraduateStudent.cpp
//@author: David Molina (40111257)
//

#include "pch.h"
#include "GraduateStudent.h"




GraduateStudent::GraduateStudent(std::string name, int id):Student(name,id)
{
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		studentRecord[i] = nullptr;
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		arraySchedule[i] = nullptr;
	}
}

bool GraduateStudent::checking_a_course(std::string coursenumber)
{
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		if (studentRecord[i]!=nullptr)
		{
			if (studentRecord[i]->getCourse().getCourseNumber()==coursenumber)
			{
				return true;
			}
		}
	}
	return false;
}
bool GraduateStudent::checking_a_course_and_if_passed(std::string coursenumber)
{
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
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

bool GraduateStudent::register_a_course(Grade grade, Time t1, Time t2)
{
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		if (studentRecord[i] == nullptr)
		{
			if (grade.getCourse().getCoursePreReq() == "")
			{
				if (checking_a_course_and_if_passed(grade.getCourse().getCourseName()))
				{
					return false;
				}
				else
				{
					if (adding_to_schedule(grade.getCourse(), t1, t2))
					{
						studentRecord[i] = new Grade(grade);
						return true;
					}

				}
			}
			else
			{
				if (checking_a_course_and_if_passed(grade.getCourse().getCoursePreReq()))
				{
					if (checking_a_course_and_if_passed(grade.getCourse().getCourseNumber()))
					{
						return false;
					}
					else
					{
						if (adding_to_schedule(grade.getCourse(), t1, t2))
						{
							studentRecord[i] = new Grade(grade);
							return true;
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}

bool GraduateStudent::adding_to_schedule(Course c, Time t1, Time t2)
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i] != nullptr)
		{
			if ((arraySchedule[i]->getTime1() == t1) || (arraySchedule[i]->getTime2() == t2))
			{
				return false;
			}
		}
	}
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i] == nullptr)
		{
			arraySchedule[i] = new CourseSchedule(c, t1, t2);
			return true;
		}
	}
}

bool GraduateStudent::dropping_a_course(std::string coursenumber)
{
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		if (studentRecord[i]!=nullptr)
		{
			if (studentRecord[i]->getCourse().getCourseNumber()==coursenumber)
			{
				delete studentRecord[i];
				studentRecord[i] = nullptr;
				return true;
			}
		}
	}
	return false;
}

void GraduateStudent::print() 
{
	Student::print();
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		if (studentRecord[i]!=nullptr)
		{
			std::cout << *studentRecord[i] << std::endl;
		}
		
	}
}


GraduateStudent::~GraduateStudent()
{
	for (size_t i = 0; i < no_of_offered_courses; i++)
	{
		if (arraySchedule[i] != nullptr)
		{
			delete arraySchedule[i];
			arraySchedule[i] = nullptr;
		}
	}
	for (size_t i = 0; i < max_number_of_graduatecourses; i++)
	{
		if (studentRecord[i] != nullptr)
		{
			delete studentRecord[i];
			studentRecord[i] = nullptr;
		}
	}
}
