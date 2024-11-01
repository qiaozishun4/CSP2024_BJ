#include <iostream>
using namespace std;

const int N=114;
int d[N],c[N],h[N],s[N];

int ans=52;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	int n,num;
	cin>>n;

	for (int i=0;i<n;i++)
	{
		char a,b;
		cin>>a>>b;

		if (b<='9'&&b>='0') num=b-'0';
		if (b=='A') num=1;
		if (b=='T') num=10;
		if (b=='J') num=11;
		if (b=='Q') num=12;
		if (b=='K') num=13;

		if (a=='D') d[num]++;
		if (a=='C') c[num]++;
		if (a=='H') h[num]++;
		if (a=='S') s[num]++;
	}
	for (int i=1;i<=13;i++)
	{
		if (d[i]!=0) ans--;
		if (c[i]!=0) ans--;
		if (h[i]!=0) ans--;
		if (s[i]!=0) ans--;
	}

	cout<<ans<<'\n';

	return 0;
}