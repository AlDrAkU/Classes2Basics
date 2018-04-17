#include "Time.h"
int Time::m_NrOfInstances{};

Time::Time() : Time(0)
{
	
}


Time::Time(int seconds)
{ 
	m_Seconds = seconds;
	m_NrOfInstances++;
}

Time::Time(int minutes, int seconds) : Time((minutes*60)+seconds)
{
	
}

Time::Time(int hours, int minutes, int seconds) : Time((hours*60*60)+(minutes * 60) + seconds)
{
	
}

Time::~Time()
{
	m_NrOfInstances--;
}

void Time::PrintTime() const
{
	int minutes = m_Seconds / 60;
	int seconds = m_Seconds % 60;
	int hours = minutes / 60;
	minutes = minutes % 60;

	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

}

void Time::AddTime(int seconds)
{
	m_Seconds += seconds;
}

void Time::AddTime(int minutes, int seconds)
{
	int tot{ (minutes * 60) + seconds };

	AddTime(tot);
}

void Time::AddTime(int hours, int minutes, int seconds)
{
	int tot{(hours*3600) + (minutes * 60) + seconds };

	AddTime(tot);
}

int Time::GetHours() const 
{
	
	return m_Seconds/3600;
}

int Time::GetMinutes() const
{
	return m_Seconds/60;
}

int Time::GetSeconds() const
{
	return m_Seconds;
}
  int  Time::GetNrInstances()   {

	return   Time::m_NrOfInstances;
}
