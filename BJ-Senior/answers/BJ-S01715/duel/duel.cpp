#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool FIO = 1;
int n;
int r[100005];
int PT = 0;
int main()
{
	if(FIO)
	{
		freopen("duel.in","r", stdin);
		freopen("duel.out","w",stdout);
	}
	cin >> n;
	if(n <= 10)
	{
		PT = 1;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> r[i];
	}
	sort(r + 1 , r + 1 + n);
	int scnt = 0 , nv = -1 , ncnt = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(r[i] > nv)
		{
			nv = r[i];
			scnt -= ncnt;
			if(scnt < 0)
			{
				scnt = 0;
			}
			scnt += ncnt;
			ncnt = 0;
		}
		ncnt ++;
	}
	scnt -= ncnt;
	if(scnt < 0)
	{
		scnt = 0;
	}
	scnt += ncnt;
	cout << scnt;
	return 0;
}
