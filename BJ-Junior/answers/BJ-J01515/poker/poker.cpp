#include<bits/stdc++.h>
using namespace std;
bool a[4+5][13+5]; 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		char c;
		int t1,t2;
		c=s[0];
		if(c=='D')
		{
			t1=1;
		}
		else if(c=='C')
		{
			t1=2;
		}
		else if(c=='H')
		{
			t1=3;
		}
		else if(c=='S')
		{
			t1=4;
		}
		c=s[1];
		int tmp=int(c)-'0';
		if(2<=tmp&&tmp<=9)
		{
			t2=tmp;
		}
		else if(c=='A')
		{
			t2=1;
		}
		else if(c=='T')
		{
			t2=10;
		}
		else if(c=='J')
		{
			t2=11;
		}
		else if(c=='Q')
		{
			t2=12;
		}
		else if(c=='K')
		{
			t2=13;
		}
		a[t1][t2]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!a[i][j])
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}