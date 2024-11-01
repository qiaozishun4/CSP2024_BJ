#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int h[4][100];
int cnt;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char C,N;
		cin>>C>>N;
		int pos,id;
		if (C=='D')
		{
			pos=0;
		}
		else if (C=='C')
		{
			pos=1;
		}
		else if (C=='H')
		{
			pos=2;
		}
		else if (C=='S')
		{
			pos=3;
		}
		if (N>='2' && N<='9')
		{
			id=N-'0';
		}
		else if (N=='A')
		{
			id=1;
		}
		else if (N=='T')
		{
			id=10;
		}
		else if(N=='J')
		{
			id=11;
		}
		else if (N=='Q')
		{
			id=12;
		}
		else if (N=='K')
		{
			id=13;
		}
		if (h[pos][id]==0) 
		{
			cnt++;
		}

		h[pos][id]++;
	}

	cout<<52-cnt;
	return 0;
}
