#pragma once
class Container
{

public:
Container(int capacity);
~Container();
void PushBack( int value);
int Size() const;
int Capacity()const;
int Get(int index)const;
void Set(int index, int value);



private:
void Reserve(int newCapacity);
int m_Size;
int m_Capacity;
int *m_pElement;



};
