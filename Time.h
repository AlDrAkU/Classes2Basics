#pragma once
#include <iostream>
class Time
{
public:
	Time();
	Time(int seconds);
	Time(int minutes, int seconds);
	Time(int hours, int minutes, int seconds);
	~Time();

	void PrintTime() const;
	void AddTime(int seconds);
	void AddTime(int minutes, int seconds);
	void AddTime(int hours, int minutes, int seconds);
	int GetHours()const;
	int GetMinutes()const;
	int GetSeconds()const;
	static int GetNrInstances() ;
private:
	
	int m_Seconds{};
	static int m_NrOfInstances;
};

