#include <bits/stdc++.h>
using namespace std;
int each[14] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	long long i, j, t, n;
	cin >> t;
	for(i = 1; i <= t; i++)
	{
	    cin >> n;
	    if(n <= 1)
        {
            cout << -1 << endl;
            continue;
        }

	    else if(n >= 2 && n <= 6)
	    {
	        cout << each[n] << endl;
	        continue;
	    }

	    else if(n % 7 == 0)
        {
            for(j = 1; j <= (n / 7); j++)
                cout << 8;
            cout << endl;
            continue;
        }

        else if(n % 7 != 3 || n <= 13)
        {
            cout << each[(n % 7) + 7];
            for(j = 1; j <= (n / 7 - 1); j++)
                cout << 8;
            cout << endl;
            continue;
        }

        else if(n % 7 == 3)
        {
            cout << 200;
            for(j = 1; j <= (n / 7 - 2); j++)
                cout << 8;
            cout << endl;
        }

	}


	return 0;
}
