#include <iostream>
#include "Time.h"
#include <ctime>
#include <string>
#include "Container.h"

void PrintContainer(const Container &container);
void TestArrays();
void CompareTimes(const Time & t1, const Time & t2);
void PrintInstancesCntr(const  std::string & message);
void TestDynamicArrays();
void TestContainer();
//void PrintContainer(const Container &c);

int main() {
	Time time1, time2;
	time1.AddTime(rand() % 12000);
	time2.AddTime(rand() % 12000);


	srand(unsigned int(time(0)));
	PrintInstancesCntr("Before calling TestArrays -> Nr of Time objects: ");
	TestArrays();
PrintInstancesCntr("After calling TestArrays -> Nr of Time objects: ");
	CompareTimes(time1,time2);
	TestDynamicArrays();
	
	TestContainer();




	system("pause");


}
void TestArrays() {
	
	Time time1, time2, time3, time4;
	const int nrOfTimes{4};


	//std::cout << rand() % 120 << std::endl;
	time1.AddTime(rand() % 12000);
	time2.AddTime(rand() % 12000);
	time3.AddTime(rand() % 12000);
	time4.AddTime(rand() % 12000);

	time1.PrintTime();
	time2.PrintTime();
	time3.PrintTime();
	time4.PrintTime();


	Time* pTimes[nrOfTimes]{};
	PrintInstancesCntr("After defining the Array of 4 Time object pointers  -> Nr of Time objects : ");
	for (int i = 0; i < nrOfTimes; i++)
	{
		pTimes[i] = new Time{};
		//std::cout << pTimes[i] << std::endl;
		
	}
	PrintInstancesCntr("After creating the 4 Time Objects   -> Nr of Time objects : ");
	for (int i = 0; i < nrOfTimes; i++)
	{
		delete pTimes[i];
		pTimes[i] = nullptr;
	}
	PrintInstancesCntr("After deleting the 4 Time Objects   -> Nr of Time objects : ");

	Time Times[nrOfTimes]{};
	for (int i = 0; i < nrOfTimes; i++)
	{
		Times[i].AddTime(20);
	}
	PrintInstancesCntr("After defining the Array of 4 Time objects  -> Nr of Time objects : ");
	

	//std::cout << Time::GetNrInstances() << std::endl;




}


void CompareTimes(const Time & t1, const Time & t2) {


	t1.PrintTime();
	t2.PrintTime();


	if (t1.GetHours() == t2.GetHours() && t1.GetMinutes() == t2.GetMinutes() && t1.GetSeconds() == t2.GetSeconds())
	{
		std::cout << "They are equal!" << std::endl;

	}
	else
	{
		std::cout << "They are not equal!" << std::endl;
	}


}
void PrintInstancesCntr(const std::string & message) {



	std::cout << message << Time::GetNrInstances() <<std::endl;


}
void TestDynamicArrays() {
	int elementsInArray;
	int * element{};
	std::cout << " How many elements do you need in the array ? ";
	std::cin >> elementsInArray;

	for (int i = 0; i < elementsInArray; i++)
	{
		element = new int[elementsInArray];
	}
	for (int i = 0; i < elementsInArray; i++)
	{
		element[i] = { rand() % 1000 };
		std::cout << element[i] << std::endl;

	}
	for (int i = 0; i < elementsInArray; i++)
	{
		
		

	}
}

void TestContainer()
{
	std::cout << "\n-- Container tests --\n";
	// Define a Container object
	const int cap{ 5 };
	std::cout << "Create container with capacity of " << cap << " elements\n";
	Container c{ cap };
	PrintContainer(c);

	// Add some values to the container
	std::cout << "\nPush back of 4 elements\n";
	for (int idx{ 0 }; idx < cap - 1; ++idx)
	{
		c.PushBack(rand() % 21);
	}
	PrintContainer(c);

	std::cout << "\nChange the value of some elements (using Set)\n";
	c.Set(0, rand() % 21);
	c.Set(2, rand() % 21);
	PrintContainer(c);

	std::cout << "\nPush back another 4 elements\n";
	for (int i{ 1 }; i < cap; ++i)
	{
		c.PushBack(rand() % 21);
	}
	PrintContainer(c);
}
void PrintContainer(const Container &container)
{
	std::cout << "-- Print container --\n";
	std::cout << "   Capacity: " << container.Capacity() << std::endl;
	std::cout << "   Size: " << container.Size() << std::endl;
	std::cout << "   Get the elements (using Get and Size)\n   ";
	for (int idx{ 0 }; idx < container.Size(); ++idx)
	{
		std::cout << container.Get(idx) << " ";
	}
	std::cout << std::endl;
}
