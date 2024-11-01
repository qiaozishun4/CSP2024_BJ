#include <bits/stdc++.h>
using namespace std;

int a[60] = {0};

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);

	int n, i, j;
	int ans = 0;
	char s1, s2;
	cin >> n;
	for(i = 1; i <= n; i++)
    {
        int id = 0;
        cin >> s1 >> s2;
        if(s1 == 'C')
            id += 13;
        else if(s1 == 'H')
            id += 26;
        else if(s1 == 'S')
            id += 39;

        if(s2 >= '2' && s2 <= '9')
        {
            if(s2 == '2')
                id += 2;
            else if(s2 == '3')
                id += 3;
            else if(s2 == '4')
                id += 4;
            else if(s2 == '5')
                id += 5;
            else if(s2 == '6')
                id += 6;
            else if(s2 == '7')
                id += 7;
            else if(s2 == '8')
                id += 8;
            else if(s2 == '9')
                id += 9;
        }
        else if(s2 == 'A')
            id++;
        else if(s2 == 'T')
            id += 10;
        else if(s2 == 'J')
            id += 11;
        else if(s2 == 'Q')
            id += 12;
        else if(s2 == 'K')
            id += 13;

        a[id] = 1;

    }

    for(i = 1; i <= 52; i++)
        ans += a[i];

	cout << 52 - ans << endl;

	return 0;
}
