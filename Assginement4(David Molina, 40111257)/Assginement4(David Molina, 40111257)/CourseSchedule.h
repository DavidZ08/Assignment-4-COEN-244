//CourseSchedule.h
//@author: David Molina (40111257)
//
#pragma once
#include <string>
#include "Time.h"
#include "Course.h"
#include <iostream>
class CourseSchedule
{
public:
	CourseSchedule(Course, Time, Time);
	Time getTime1()const;
	Time getTime2()const;
	virtual void print();
	~CourseSchedule();
private:
	Course course;
	Time time1;
	Time time2;
};

