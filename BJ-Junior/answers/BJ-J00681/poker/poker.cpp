#include <bits/stdc++.h>
using namespace std;

int n,pok[1001],answer = 0;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char q,p;
		cin >> q >> p;
		int t;
		if(p == 'A') t = 1;
		else if (p == 'T') t = 10;
		else if (p == 'J') t = 11;
		else if (p == 'Q') t = 12;
		else if (p == 'K') t = 13;
		else t = p - '0';
		if (q == 'H') t += 13;
		else if (q == 'D') t += 26;
		else if (q == 'C') t += 39;
		pok[t]++;
	}
	for (int i = 1;i <= 52;i++)
	{
		if (pok[i] > 0)
		{
			answer++;
		}
	}
	cout << 52 - answer;
	return 0;
}
