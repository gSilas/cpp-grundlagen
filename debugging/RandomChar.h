#ifndef  RANDOMCHAR_H
#define RANDOMCHAR_H

#include <stdlib.h>

/// Just for picking a random char from an array of chars.
// also contains errors to fix, see program.cpp for instructions
// SUPER OPTIONAL BONUS: write a better random char generator. ;)
class RandomChar
{
public:
    RandomChar();
    ~RandomChar();
	static char RandomChar::getRandomChar();

private:
	static int const m_Length = 71;
	static const char m_AllPossibleChars[m_Length];
};

#endif // ! RANDOMCHAR_H
