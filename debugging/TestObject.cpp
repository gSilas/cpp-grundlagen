#include "TestObject.h"

TestObject::TestObject()
{
    m_NumberOfStrings = 10;
    generateStrings();
}


TestObject::TestObject(int numberOfStrings)
{
    m_NumberOfStrings = numberOfStrings;
    generateStrings();
}


TestObject::~TestObject()
{
    delete m_ArrayOfStrings;
}

void TestObject::generateStrings()
{
    m_ArrayOfStrings = new std::string[m_NumberOfStrings];

    for (int i = 0; i < m_NumberOfStrings; i++)
    {
        std::string& currentString = m_ArrayOfStrings[i];
        
        int numberOfChars = rand() % 30 + 1;
        currentString.resize(numberOfChars);
        for (auto& c : currentString)
        {
            c = RandomChar::getRandomChar();
        }
     }
}

void TestObject::swapStrings(std::string& first, std::string& second)
{
    // TODO: swap elements using references.
	std::string& temp = first;
	first = second;
	second = temp;
}


void TestObject::printAllStrings()
{
    for (int i = 0; i < m_NumberOfStrings; i++)
    {
        std::cout << m_ArrayOfStrings[i];
    }
    std::cout << std::endl;
}


// return the number of elements
int& TestObject::elementCount()
{
    return m_NumberOfStrings;
}

void TestObject::reverseArray()
{

}