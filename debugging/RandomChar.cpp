#include "RandomChar.h"
static const char m_AllPossibleChars[] = { "01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!§$%&?@" };
RandomChar::RandomChar()
{
}

RandomChar::~RandomChar()
{
}


char RandomChar::getRandomChar()
{
	return m_AllPossibleChars[rand() % m_Length];
}