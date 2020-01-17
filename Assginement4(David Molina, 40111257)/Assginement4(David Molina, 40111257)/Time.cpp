//Time.cpp
//@author: David Molina (40111257)
//
#include "pch.h"
#include "Time.h"
#include <iostream>


Time::Time()
{
}

Time::Time(int h, int d): hour(h),day(d)
{

}

bool Time::operator==(const Time & t)const
{
	return ((day == t.day) && (hour == t.hour));
}


Time::~Time()
{
}

std::ostream &operator<<(std::ostream &os, Time &t)
{
	os << "Day: " << t.day << " Hour: " << t.hour;
	return os;
}
