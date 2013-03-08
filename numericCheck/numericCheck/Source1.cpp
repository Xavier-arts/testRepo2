/*
	Ben Yoder
	Numeric Check: checks if value is a number or a letter
	October 2011
*/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

void numericCheckString();

int main()
{
	numericCheckString();
}

//checks if string is an numeric value
//allows for doubles with one '.', greater than one flag triggers
//converts string to double value
void numericCheckString()
{
	char string [10];
	int len,	//length of string
		ind2,	//error indicator
		decCounter = 0;	//flags number of decimals in number
	double	ind,		//work digit
			amt = 0;	//storage for string conversion

	ind = 0;
	ind2 = 0;

		while( ind == 0 )
		{
			if(ind2 == 1)
				ind2 = 0;
			cin >> string;
			cout << string;
			len = strlen(string);
			cout << " the length of the string is " << len << "\n";
				
			//checks if string is an numeric value
				for ( int i = 0; i<len; i++)
				{
					//ind2 is an error indicator
					if( string[i] < '0')
						ind2 = 1;
					else if (string[i] > '9')
						ind2 = 1;
					if( string[i] == '.')
					{
						decCounter++;
						ind2 = 0;
					}
				}//end of for loop

				//check flags
				if(decCounter > 1)
					ind2 = 1;
				if(ind2 == 0)
					ind = 1;
				else if(ind2 == 1)
				{
					//flag reset
					decCounter = 0;
					//retry with new input
					cout<<"Invalid numeric data, please reenter: ";
				}
		}//end of while loop

		//converts string to double value
		amt = atof( string );

		//converts string to int value using ASCII values
		/*for(int i = 0; i<len; i++)
		{
				ind = string[i];
				//The character of "0" = 48 and "1" = 49 etc... in ASCII code
				amt = 10 * amt + ind - 48;
		}//end of for loop*/

		cout <<"amt" << " = " << amt <<endl;
		cin >> len;
}


//function templates
//template <typename T> std::string to_string(T const& value);
/*
//converts generic value to a string and returns the string
template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

//checks if string is an numeric value
//allows for doubles with one '.', greater than one flag triggers
//converts string to double value
double numericCheckNum( char *numToString )
{
	//stores string in a null-terminated sequence of characters (c-string)
	//uses pointers for the array of characters
	//const char * string = to_string( numToString ).c_str ();
	string str = numToString;
	char * string = new char [str.size()+1];
	strcpy (string, str.c_str());
	int len = 0,	//length of string
		ind2 = 0,	//error indicator
		decCounter = 0;	//flags number of decimals in number
	double	ind = 0,		//work digit
			amt = 0;	//storage for string conversion

		while( ind == 0 )
		{
			if(ind2 == 1)
				ind2 = 0;
			len = strlen(string);
				
			//checks if string is an numeric value
				for ( int i = 0; i<len; i++)
				{
					//ind2 is an error indicator
					if( string[i] < '0')
						ind2 = 1;
					else if (string[i] > '9')
						ind2 = 1;
					if( string[i] == '.')
					{
						decCounter++;
						ind2 = 0;
					}
				}//end of for loop

				//check flags
				if(decCounter > 1)
					ind2 = 1;
				if(ind2 == 0)
					ind = 1;
				else if(ind2 == 1)
				{
					//flag reset
					decCounter = 0;
					//retry with new input
					cout<<"Invalid numeric data, please reenter: ";
				}
		}//end of while loop

		//converts string to double value
		amt = atof( string );
		return amt;
}
*/