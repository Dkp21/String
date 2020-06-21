#include <iostream>
#include <string>

using namespace std;


bool stringHasUniqueCharBruteForce(const string & s)
{
	const char *str = s.c_str();

	// Assuming only ASCII chars 
	if(s.length() > 128)
	{
		return false;
	}

	for(int i = 0; i < s.length(); ++i)
	{
		for(int j = i +1; j < s.length(); ++j)
		{
			if( str[i] == str[j])
			{
				return false;
			}
		}
	}

	return true;
}

bool stringHasUniqueCharOptimized(const string & s)
{
	const char *str = s.c_str();

	// Assuming only ASCII chars 
	if(s.length() > 128)
	{
		return false;
	}

	bool *char_present = new bool[128];

	for(int i = 0; i < s.length(); ++i)
	{
		int j = str[i];

		if(char_present[j])
		{
			return false;
		}
		
		char_present[j] = true;
	}

	return true;
}

int main(int argc, char **argv)
{
	string str("Dhruval");

#ifdef BRUTE_FORCE
	if(stringHasUniqueCharBruteForce(str))
#else 
	if(stringHasUniqueCharOptimized(str))
#endif
	{
		cout << str << " string has all unique chars" << endl;
	}
	else
	{
		cout << str << " string has a repeating chars" << endl;
	}

	return 0;
}
