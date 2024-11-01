#include<bits/stdc++.h>
using namespace std;
int a[4][14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		char c,h;
		int i,j;
		cin>>c>>h;
		if(c=='D') i=0;
		else if(c=='C') i=1;
		else if(c=='H') i=2;
		else i=3;
		if(h>='0'&&h<='9') j=h-'0';
		else if(h=='A') j=1;
		else if(h=='T') j=10;
		else if(h=='J') j=11;
		else if(h=='Q') j=12;
		else j=13;
		a[i][j]=1;
	}
	int s=0;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]!=1) s++;
		}
	}
	cout<<s;
	return 0;
}