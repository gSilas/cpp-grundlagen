#include "timer.hpp"
#include <iostream>
#include <cmath>

/// \brief This tasks shows you how fast your console is.
void heavyWork1()
{
	// TODO: put a timer here
	ScopeTimer t(1);
	for( int i = 0; i < 1000; ++i )
	{
		std::cout << "I am working\n";
	}
}

/// \brief Count the number of primes in an interval.
/// \details This implementation has a very bad performance and a lot of potential
///		to be optimized
///		
///		This code is a modified version of the frequency of primes example
///		from http://www.cplusplus.com/reference/ctime/clock/
int heavyWork2( int n0, int n1 )
{
	// TODO: put a timer here
	ScopeTimer t(2);
	int freq = n1-n0+1;
	for(int i = n0; i <= n1; ++i)
	{
		// Have fun: use the alternative iteration direction and see how fast
		// it gets!
		// for(int j = 2; j < i; ++j)
		for(int j = i-1; j > 1; --j)
		{
			if(i%j == 0)
			{
				--freq;
				break;
			}
		}
	}
	return freq;
}

/// \brief Count the number of primes in an interval.
/// \details In contrast to heavyWork2() this implementation loops over
///		less numbers to test for a prime and should be
///		faster.
///		
///		This code is a modified version of the frequency of primes example
///		from http://www.cplusplus.com/reference/ctime/clock/
int heavyWork3( int n0, int n1 )
{
	// TODO: put a timer here
	ScopeTimer t(3);
	int freq = n1-n0+1;
	for(int i = n0; i <= n1; ++i)
	{
		int max = (int)sqrt(i);
		for(int j = 2; j <= max; ++j)
		{
			if(i%j == 0)
			{
				--freq;
				break;
			}
		}
	}
	return freq;
}

/// \brief This function calls all test functions and measures the overall time
///		of all tasks.
void doAllTheHeavyWork()
{
	// TODO: put a timer here
	ScopeTimer t(0);
	heavyWork1();
	std::cout << "Number of primes in [0, 100000]: " << heavyWork2(0, 100000) << std::endl;
	std::cout << "Number of primes in [0, 100000]: " << heavyWork3(0, 100000) << std::endl;
}


int main()
{
	int lol;
	doAllTheHeavyWork();
	std::cin >> lol;
	return 0;
}