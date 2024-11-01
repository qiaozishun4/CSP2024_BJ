#include <bits/stdc++.h>
using namespace std;
const int N=100;
int n,ans=52;
bool s[N][N];
char a,b;
int numbe(char x)
{
		if(x=='A') return 1;
		if(x=='T') return 10;
		if(x=='J') return 11;
		if(x=='Q') return 12;
		if(x=='K') return 13;
		return x-'0';
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
				cin>>a>>b;
				int num2,num3;
				if(a=='C') num2=1;
				if(a=='D') num2=2;
				if(a=='H') num2=3;
				if (a=='S')num2=4;
				num3=numbe(b);
				s[num2][num3]=1;
		}
		for(int i=1;i<=4;i++)
		{
				for(int j=1;j<=13;j++)
				{
					if(s[i][j]==1) ans=ans-1;
				}
		}
		cout<<ans<<endl;
		return 0;
}