//============================================================================
// Name        : SumByFactors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define TEST


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

/* Color macros */
#ifdef TEST
#include <windows.h>
#define C_HANDLE	GetStdHandle(STD_OUTPUT_HANDLE)
#define C_RESET		SetConsoleTextAttribute(C_HANDLE, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#define C_RED		SetConsoleTextAttribute(C_HANDLE, FOREGROUND_RED);
#define C_INRED		SetConsoleTextAttribute(C_HANDLE, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define C_GREEN		SetConsoleTextAttribute(C_HANDLE, FOREGROUND_GREEN);
#else
#define C_HANDLE
#define C_RESET
#define C_RED
#define C_INRED
#define C_GREEN
#endif


class SumOfDivided
{
public:
    static string sumOfDivided(vector<int> &lst);

private:
    static vector<int> findPrimes(int input);
    static bool isPrime(int input);
    static void addToListOfPrimes(vector<int> newPrimes);
    static vector<int> ListOfPrimes;
};

vector<int> SumOfDivided::ListOfPrimes;

bool SumOfDivided::isPrime(int input)
{
  int divider = 2;
  while(true)
  {
    if((divider * divider) > input)
    {
      /* tested all dividers -> end */
      /* have not found any divider -> is prime */
      return true;
    }
    if(0 == (input % divider))
    {
      /* found divider -> is not prime -> can end the function now */
      return false;
    }
    /* no result so far -> repeat for next possible divider */
    divider ++;
  }
}

vector<int> SumOfDivided::findPrimes(int input)
{
  vector<int> primes;


	C_GREEN;
	cout << "Processing " << input << " : " << endl;
	C_RESET;
  int divider = 2;
  /* abs */
  if(input < 0) input *= (-1);

  /* input is prime */
  if(isPrime(input))
  {
	  primes.push_back(input);
	  return primes;
  }

  while(true)
  {
    if((divider * 2) > input)
    {
      /* ran through all the possible dividers -> end */
      return primes;
    }
    if(isPrime(divider))
    {
      /* tested divider is prime -> test if wholenumber divider */
      if(0 == (input % divider))
      {
        /* add divider to list */
    	  cout << "found " << divider << endl;
        primes.push_back(divider);
      }
    }
    /* test next divider */
    divider ++;
  }
  return primes;
}

void SumOfDivided::addToListOfPrimes(vector<int> newPrimes)
{
	if(0 == newPrimes.size()) return;	/* empty input vector */

	/* List of primes is empty */
	if(0 == ListOfPrimes.size())
	{
		/* Add first element to empty list */
		ListOfPrimes.push_back(*(newPrimes.begin()));
	}

	for(vector<int>::iterator NPiter = newPrimes.begin(); NPiter != newPrimes.end(); NPiter++)
	{
		if((*NPiter) > ListOfPrimes.back())
		{
			/* Prime is bigger than any previously saved - put it to back of store vector */
			ListOfPrimes.push_back(*NPiter);

		}
		else
		{
			for (vector<int>::iterator LPiter = ListOfPrimes.begin(); LPiter != ListOfPrimes.end(); LPiter++)
			{
				if((*NPiter) == (*LPiter))
				{
					/* prime already found for other input */
					/* Go to next input */
					break;
				}
				else if((*NPiter) < (*LPiter))
				{
					/* place before tested element of ListOfPrimes */
					ListOfPrimes.insert(LPiter, *NPiter);
					/* Saved -> go for next input */
					break;
				}
				else
				{
					/* test against next of ListOfPrimes */
					/* handled by for cycle -> do nothing */
				}
			}
		}
	}

	return;
}

/* Main function of answer */
/* Only this method should be public */
string SumOfDivided::sumOfDivided(vector<int> &lst)
{
	string result;
	vector<int> primes;
	int sumOfInputs;
	char buff[32];

	/* Clear list of primes */
	ListOfPrimes.clear();

	for(vector<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		primes = findPrimes(*iter);
		addToListOfPrimes(primes);
	}

	cout << "\nPrinting list of inputs:\n";
	for(vector<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		cout << *iter << ", ";
	}
	cout << "\n";

	cout << "\nPrinting list of primes:\n";
	for(vector<int>::iterator iter = SumOfDivided::ListOfPrimes.begin(); iter != SumOfDivided::ListOfPrimes.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << "\n";

	/* Now prepare result */
	for(vector<int>::iterator iter = SumOfDivided::ListOfPrimes.begin(); iter != SumOfDivided::ListOfPrimes.end(); iter++)
	{
		sumOfInputs = 0;
		/* For each prime, go through inputs, sum all the valid ones*/
		for(vector<int>::iterator InpIter = lst.begin(); InpIter != lst.end(); InpIter++)
		{
			/* Check if is prime of this input */
			if(0 == ((*InpIter) % (*iter)))
			{
				sumOfInputs += *InpIter;
			}
		}
		result.append("(");
		sprintf(buff, "%d", *iter);
		result.append(buff);
		result.append(" ");
		sprintf(buff, "%d", sumOfInputs);
		result.append(buff);
		result.append(")");
	}
	cout << result << endl;


	return result;
}


/* Support code here - not part of answer */
/* from codewars */
void testequal(std::string ans, std::string sol)
{
	cout << "Comparing results" << endl;
	int res;
    //Assert::That(ans, Equals(sol));
	res = ans.compare(sol);
	cout << "Result of comparison: " << res << endl;
}

/* example test in here */
int main() {
	cout << "Start of test" << endl << endl;

	/* --- from Codewars --- */

        std::vector<int> d1 = {7098, 12201, 14726, 3489, 11871, 4881, 8161, 29329, -13587, 15486, 31467, 778, 36507, 2242, 24306, 23316, 14060, 33801, 23448};
		//std::vector<int> d1 = {-16649};
        std::string ans1 = SumOfDivided::sumOfDivided(d1);
        std::string sol1 = "(2 125460)(3 214284)(5 14060)(7 5712)(13 7098)(17 31467)(19 50103)(29 38802)(37 28786)(43 36507)(59 2242)(67 23316)(83 12201)(89 15486)(139 29329)(199 14726)(211 29329)(283 36507)(389 778)(593 33801)(617 31467)(647 -13587)(977 23448)(1163 3489)(1319 11871)(1627 4881)(4051 24306)(8161 8161)";

        testequal(ans1, sol1);

	/* --- end of from Codewars --- */
	return 0;
}
