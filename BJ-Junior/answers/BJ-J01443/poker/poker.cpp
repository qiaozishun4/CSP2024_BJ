#include <bits/stdc++.h>
using namespace std;
int h[1000005];
/*
 * 1-13：方片
 * 14-26：草花
 * 27-39：红桃
 * 40-52：黑桃
*/
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int x=0;
		//第一位
		if (s[0]=='C') x+=13;
		if (s[0]=='H') x+=26;
		if (s[0]=='S') x+=39;
		//第二位
		if (s[1]=='A') x+=1;
		else if (s[1]=='T') x+=10;
		else if (s[1]=='J') x+=11;
		else if (s[1]=='Q') x+=12;
		else if (s[1]=='K') x+=13;
		else x+=int(s[1]-'0');
		h[x]++;
	}
	int u=52;
	for (int i=1;i<=52;i++)
	{
		if (h[i]) u--;
	}
	cout<<u;
	return 0;
}
