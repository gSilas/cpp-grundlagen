#include "dynamicobjectlist.hpp"
#include "object.h"
#include <math.h> 
#include <algorithm>
DynamicObjectList::DynamicObjectList() :
m_count(0),
m_capacity(0),
m_list(nullptr)
{
}

DynamicObjectList::~DynamicObjectList()
{
  delete[] m_list;
}

void DynamicObjectList::reserve(unsigned int capacity)
{
  // Check if anything should happen.
  if(m_capacity >= capacity)
    return;

  // Create new object array with the given capacity.
  Object** newArray = new Object*[capacity];

  // Moves old list contents to new list.
  for(unsigned int i = 0; i < m_count; ++i)
  {
    newArray[i] = m_list[i];
  }

  // Optional: Set all other pointer to nullptr, just for easier debugging.
  for(unsigned int i = m_count; i < capacity; ++i)
  {
    newArray[i] = nullptr;
  }

  // delete old array!
  delete[] m_list;

  // Save new data.
  m_list = newArray;
  m_capacity = capacity;
}

void DynamicObjectList::shrink()
{
	m_capacity = (int)pow(2, m_count);
}

Object* DynamicObjectList::createObject_back(char* name)
{
	// Ensure capacity.
	reserve((m_count + 1) * 2);

	// Add new object.
	m_list[m_count] = new Object(name);

	return m_list[m_count++];
}

void DynamicObjectList::sort()
{
	for (unsigned int j = 1; j < m_count-2; j++)    // Start with 1 (not 0)
	{
		unsigned int i = 0;
		Object *tmp = m_list[j];
		for (i = j - 1; (i >= 0) && (*m_list[i] < *tmp); i--)   // Smaller values move up
		{
			m_list[i + 1] = m_list[i];
		}
		m_list[i + 1] = tmp;    //Put key into its proper location
	}
}


Object* DynamicObjectList::push_back(Object *a)
{
	if (a == nullptr)
		return a;
	// Ensure capacity.
	reserve((m_count + 1) * 2);

	// Add new object.
	m_list[m_count] = a;

	return m_list[m_count++];
}

Object* DynamicObjectList::createObject_front(char* name)
{
  // Ensure capacity.
  reserve((m_count + 1) * 2);

  // Move all other objects.
  for (unsigned int i = m_count; i >= 1; --i)
  {
    m_list[i] = m_list[i - 1];
  }

  // Add new object.
  m_list[0] = new Object(name);
  ++m_count;

  return m_list[0];
}

void DynamicObjectList::destroyObject(unsigned int position)
{
  // Does the element exist?
  if(m_count <= position)
  {
    return;
  }

  // Destroy the object at the given position.
  delete m_list[position];

  // Now we have less objects!
  --m_count;

  // Move all other objects.
  for (unsigned int i = position; i < m_count; ++i)
  {
    m_list[i] = m_list[i + 1];
  }
  shrink();
  // Optional: Set former back to nullptr for easier debugging.
  m_list[m_count] = nullptr;
}

Object* DynamicObjectList::getAt(unsigned int position)
{
	// Does the element exist?
	if (m_count <= position)
	{
		return nullptr;
	}

	return m_list[position];
}
/* todo*/
Object* DynamicObjectList::getAt(const unsigned int position) const
{
	if (position >= m_count)
		return nullptr;
	else
		return m_list[position];
}


DynamicObjectList & DynamicObjectList::operator+=(const Object &o)
{
	static Object *opointer = new Object(o);
	push_back(opointer);
	return *this;
}
DynamicObjectList& DynamicObjectList::operator+=(Object& o) 
{
	push_back(&o);
	return *this;
}
DynamicObjectList & DynamicObjectList::operator|=(const DynamicObjectList &l)
{
	int index = 0;
	while(index < l.m_count)
	{
		push_back(&l[index]);
		index++;
	}
	return *this;
}

DynamicObjectList & DynamicObjectList::operator&=(const DynamicObjectList &l)
{
	DynamicObjectList a(*this);
	DynamicObjectList b(l);

	if(a.getCount() < b.getCount())
	{
		for(int i = 0; i < a.getCount(); i++)
		{
			bool wasfound = false;
			for(int j = 0; j < b.getCount(); j++)
			{
				if (i == a.getCount())
					break;
				if (a[i] == b[j])
				{
					b.destroyObject(j);
					wasfound = true;
				}
				if(!wasfound && (j == (b.getCount() - 1)))
				{
					a.destroyObject(i);
				}
			}
		}
		return a;
	}
	else
	{
		for (int i = 0; i < b.getCount(); i++)
		{
			bool wasfound = false;
			for (int j = 0; j < a.getCount(); j++)
			{
				if (i == b.getCount())
					break;
				if (b[i] == a[j])
				{
					a.destroyObject(j);
					wasfound = true;
				}
				if (!wasfound && (j == (b.getCount() - 1)))
				{
					b.destroyObject(i);
				}
			}
		}
		return b;
	}
}

Object & DynamicObjectList::operator[](const unsigned int index) const
{
	return *getAt(index);
}

Object & DynamicObjectList::operator[](const unsigned int index)
{
	return *getAt(index);
}