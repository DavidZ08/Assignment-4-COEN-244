//Time.h
//@author: David Molina (40111257)
//
#pragma once
#include <iostream>
class Time
{
public:
	Time();
	Time(int, int);
	bool operator == (const Time&)const;
	friend std::ostream &operator<< (std::ostream&, Time&);
	~Time();
private:
	int hour;
	int day;
};

