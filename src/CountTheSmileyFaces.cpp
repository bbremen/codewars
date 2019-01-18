//============================================================================
// Name        : CountTheSmileyFaces.cpp
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



int countSmileys(std::vector<std::string> arr)
{
	std::string Smiley;
	int numOfSmileys = 0;
	for(vector<std::string>::iterator iter = arr.begin(); iter != arr.end(); iter++)
	{
		bool isSmiley = false;
		Smiley = *iter;
		cout << Smiley << endl;
		/* Analyze Smiley step by step */
		/* Step 1: eyes - valid chars ':' ';' */
		if((':' == Smiley[0]) || (';' == Smiley[0]))
		{
			/* Step 1 passed, continue with check */
			/* Step 2: with nose - detect nose - valid chars '-' '~' */
			if(('-' == Smiley[1]) || ('~' == Smiley[1]))
			{
				/* Step 2 passed, continue with check */
				/* Step 3: mouth - valid chars ')' 'D' */
				if((')' == Smiley[2]) || ('D' == Smiley[2]))
				{
					/* Step 3 passed, continue with check */
					/* Step 4: end of smiley, '\0' have to be present here */
					if('\0' == Smiley[3])
					{
						/* Step 4 passed -> Yay, we have a smiley */
						isSmiley = true;
					}
				}
			}
			/* Step 2: without nose: detect mouth - valid chars ')' 'D' */
			else if((')' == Smiley[1]) || ('D' == Smiley[1]))
			{
				/* Step 2 passed, continue with check */
				/* Step 3: end of smiley, '\0' have to be present here */
				if('\0' == Smiley[2])
				{
					/* Step 3 passed -> Yay, we have a smiley */
					isSmiley = true;
				}
			}
		}
		if(true == isSmiley)
		{
			numOfSmileys++;
		}
	}
	return numOfSmileys;
}








class Assert
{
public:
	static void testequal(string ans, string sol);
	static void Equals(int result, int expected);
private:
};


/* Support code here - not part of answer */
/* from codewars */
void Assert::Equals(int result, int expected)
{
	if(result == expected)
	{
		C_GREEN;
		cout << "PASSED - result valid " << result << endl;
		C_RESET;
	}
	else
	{
		C_RED;
		cout << "FAILED - expected " << result << " , but expected " << expected << endl;
		C_RESET;
	}
}

void Assert::testequal(std::string ans, std::string sol)
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

    Assert::Equals(countSmileys({}), (0));
    Assert::Equals(countSmileys({":D", ":~)", ";~)", ":)"}), (4));
    Assert::Equals(countSmileys({":)", ":(", ":D", ":O", ":;"}), (2));
    Assert::Equals(countSmileys({";]", ":[", ";*", ":$", ";-D"}), (1));

	/* --- end of from Codewars --- */
	return 0;
}
