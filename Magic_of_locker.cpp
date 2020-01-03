/*
	Solution Author - Atharva Adhav
	Question Source - SPOJ
	Question - Magic of the locker (LOCKER)
	Concepts - Modular Binary Exponentiation
*/

/*
	Examples to Understand Logic:

	n = 5 = 3 + 2   Answer = 3 * 2 = 6 
	n = 6 = 3 + 3   Answer = 3 * 3 = 9
	n = 7 = 3 + 4   Answer = 3 * 4 = 12
	n = 9 = 3 + 3 + 3   Answer = 3 * 3 * 3 = 27
	n = 10 = 3 + 3 + 4   Answer = 3 * 3 * 4 = 36
	n = 11 = 3 + 3 + 3 + 2  Answer = 3 * 3 * 3 * 2 = 54
*/


#include <iostream>
using namespace std;

typedef unsigned long long int lli;
#define MOD 1000000007;

lli exponent(lli a, lli b) // Modular Binary Exponentiation function
{
	a = a % MOD;
	lli res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	lli ans, b;
	lli t;
	cin >> t;
	while (t--)
	{
		lli n;
		cin >> n;
		if (n == 1)
			cout << "1\n";
		else if (n == 2)
			cout << "2\n";
		else if(n == 3)
			cout << "3\n";
		else 
		{
			if (n % 3 == 1)
			{	
				ans = exponent(3, n / 3 - 1);
				ans = ans * 4 % MOD;
			}
			else if (n % 3 == 2)
			{
				ans = exponent(3, n / 3);
				ans = ans * 2 % MOD;
			}
			else
			{
				ans = exponent(3, n / 3);
			}

			cout << ans << "\n";
		}
	}


	return 0;
}