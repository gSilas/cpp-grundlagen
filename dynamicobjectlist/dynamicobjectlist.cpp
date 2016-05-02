#include "dynamicobjectlist.hpp"
#include "object.h";


DynamicObjectList::DynamicObjectList() {
	m_capacity = 32;
	m_count = 0;
	m_list = new Object *[m_capacity];
}

DynamicObjectList::~DynamicObjectList() {
	delete[] m_list;
}

void DynamicObjectList::reserve(unsigned int capacity) {
	if (m_capacity < capacity) {
		Object** new_m_list = new Object *[capacity];
		for (unsigned int i = 0; i < m_count; i++) {
			new_m_list[i] = m_list[i];
		}
		delete[] m_list;
		m_list = new_m_list;
		m_capacity = capacity;
	}
}

Object *DynamicObjectList::createObject_back(char *name) {
	if (m_count == m_capacity) {
		reserve(m_capacity * 2);
	}
	Object *obj = Object(name);
	m_list[m_count++] = obj;
	return obj;
}

void DynamicObjectList::destroyObject(unsigned int position) {
	if (position < m_count) {
		delete m_list[position];

		for (unsigned int i = position; i < m_count; i++) {
			m_list[i] = m_list[i + 1];
		}
		m_count--;
	}
}

Object *DynamicObjectList::getAt(unsigned int position) {
	if (position >= m_count)
		return nullptr;
	return m_list[position];
}
