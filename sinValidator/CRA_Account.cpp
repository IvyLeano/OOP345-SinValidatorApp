/* W03
 * CRA_Account.cpp
 * Ivy Leano
 */

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict 
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) 
	{
		int sinArray[9] = { 0 };
		int tempSin = sin;
		int evens = 0;
		int odds = 0;
		int difference = 0;

		for (int i = 8; i >= 0; i--) 
		{
			sinArray[i] = tempSin % 10;
			tempSin = tempSin / 10;

			if (i % 2 == 0 && i != 8) 
			{
				evens += sinArray[i];
			}
			else if (i % 2 != 0 && sinArray[i] >= 5) 
			{
				odds += ((sinArray[i] * 2) - 10) + 1;
			}
			else if (i % 2 != 0 && sinArray[i] < 5) 
			{
				odds += sinArray[i] * 2;
			}
		}

		difference = 10 - ((evens + odds) % 10);

		if (sin > min_sin && sin < max_sin && difference == sinArray[8] && familyName[0] != '\0' && givenName[0] != '\0') 
		{
			strncpy(storeFamilyName, familyName, max_name_length + 1);
			strncpy(storeGivenName, givenName, max_name_length + 1);
			storeSin = sin;
			numYrs = 0;
		}
		else 
		{
			storeFamilyName[0] = '\0';
			storeGivenName[0] = '\0';
			storeSin = 0;
		}
	}
	
	void CRA_Account::set(int year, double balance) 
	{
			if (!isEmpty() && numYrs < max_yrs) 
			{
				OwingOrRefund[numYrs] = balance;
				taxReturnYears[numYrs] = year;
				numYrs++;
		}
	}

	bool CRA_Account::isEmpty() const 
	{
		return (storeSin == 0);
	}

	void CRA_Account::display() const 
	{
		if (!isEmpty()) 
		{
			cout << fixed << setprecision(2);
			cout << "Family Name: " << storeFamilyName << endl;
			cout << "Given Name : " << storeGivenName << endl;
			cout << "CRA Account: " << storeSin << endl;

			for (int i = 0; i < numYrs; i++) 
			{	
				if (OwingOrRefund[i] > 2) 
				{
					cout << "Year (" << taxReturnYears[i] << ") balance owing: " << OwingOrRefund[i] << endl;
				}
				else if (OwingOrRefund[i] < -2) 
				{
					cout << "Year (" << taxReturnYears[i] << ") refund due: " << OwingOrRefund[i] * -1 << endl;
				}
				else 
				{
					cout << "Year (" << taxReturnYears[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}

	else
		{
			cout << "Account object is empty!" << endl;
		}
	}
}
