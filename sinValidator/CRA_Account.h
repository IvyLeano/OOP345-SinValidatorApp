/* W03
 * CRA_Account.h
 * Ivy Leano
 */

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict 
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account 
	{
		char storeFamilyName[max_name_length + 1];
		char storeGivenName[max_name_length + 1];
		int storeSin;
		int numYrs;
		int taxReturnYears[max_yrs];
		double OwingOrRefund[max_yrs];

	public:

		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SICT_CRA_ACCOUNT_H

