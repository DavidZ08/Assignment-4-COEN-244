//CourseSchedule.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "CourseSchedule.h"



CourseSchedule::CourseSchedule(Course c, Time t1, Time t2): course(c), time1(t1), time2(t2)
{
}

Time CourseSchedule::getTime1() const
{
	return time1;
}

Time CourseSchedule::getTime2() const
{
	return time2;
}

void CourseSchedule::print()
{
	course.print();
	std::cout << std::endl;
	std::cout << "Time 1: " << time1 << std::endl;
	std::cout << "Time 2: " << time2 << std::endl;
}


CourseSchedule::~CourseSchedule()
{
}
