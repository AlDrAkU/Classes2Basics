#include "Container.h"
#include<iostream>


Container::Container(int capacity) {
	m_pElement = new int[capacity] {};
	m_Capacity = capacity;

}
Container::~Container() {
}
void Container::PushBack( int value){
	if (m_Size >= m_Capacity)
	{
		Reserve(m_Capacity * 2);
		Set(m_Size, value);

	}
	else
	{
		Set(m_Size, value);
	}
	m_Size++;


}
int Container::Size()const {
	return m_Size;

}
int Container::Capacity()const {
return m_Capacity;
}
int Container::Get(int index)const {
return m_pElement[index];
}
void Container::Set (int index, int value){

m_pElement[index] = value;

}
void Container::Reserve(int newCapacity){
	int *nArr = new int[newCapacity];

		for (int i = 0; i < m_Capacity; i++)
		{
			nArr[i] = m_pElement[i];
		}

	delete[] m_pElement;
	m_pElement = nArr;
	nArr = nullptr;

	m_Capacity = newCapacity;



}
