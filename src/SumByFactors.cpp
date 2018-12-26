//============================================================================
// Name        : SumByFactors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
  int divider = 2;

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
  vector<int>::iterator PrimesIter = ListOfPrimes.begin();
  for(vector<int>::iterator iter = newPrimes.begin(); iter != newPrimes.end(); )
  {
    if((*iter) == (*PrimesIter))
    {
      /* prime already found for other input */
      /* increment, go for next iteration */
      PrimesIter++;
      iter++;
    }
    else if((*iter) < (*PrimesIter))
    {
      /* place before tested element of ListOfPrimes */
      ListOfPrimes.insert(PrimesIter, *iter);
      iter++;
    }
    else
    {
      /* test against next of ListOfPrimes */
      PrimesIter++;
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
  primes = findPrimes(15);
  addToListOfPrimes(primes);

  primes = findPrimes(21);
  addToListOfPrimes(primes);

  cout << "\n";
  for(vector<int>::iterator iter = SumOfDivided::ListOfPrimes.begin(); iter != SumOfDivided::ListOfPrimes.end(); iter++)
  {
    cout << *iter << " ";
  }
  cout << "\n";

  return result;
}


/* Support code here - not part of answer */
/* from codewars */
void testequal(std::string ans, std::string sol)
{
	int res;
    //Assert::That(ans, Equals(sol));
	res = ans.compare(sol);
	cout << "Result of comparison: " << res << endl;
}

/* example test in here */
int main() {
	cout << "Start of test" << endl << endl;

	/* --- from Codewars --- */



        std::vector<int> d1 = {12, 15};
        std::string ans1 = SumOfDivided::sumOfDivided(d1);
        std::string sol1 = "(2 12)(3 27)(5 15)";
        testequal(ans1, sol1);

	/* --- end of from Codewars --- */
	return 0;
}
