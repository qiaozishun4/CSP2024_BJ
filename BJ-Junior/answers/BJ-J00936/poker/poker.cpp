#include <bits/stdc++.h>
using namespace std;

map <string , bool> poker;

int main()
{
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
	int n,cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string str;
		cin >> str;
		if (poker[str] == false)
		{
			cnt ++;
			poker[str] = true;
		}
	}
	cout<<52 - cnt;
	return 0;
}
