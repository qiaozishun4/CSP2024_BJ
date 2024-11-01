#include <bits/stdc++.h>
using namespace std;
int H[256],G[256];
bool b[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	H['D']=0;H['S']=1;H['C']=2;H['H']=3;
	for(int i=1;i<=13;i++)
		G[i+'0']=i;
	G['A']=1;G['T']=10;G['J']=11;G['Q']=12;G['K']=13;
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		b[H[s[0]]*13+G[s[1]]]=1;
	}
	int cnt=0;
	for(int i=1;i<=52;i++)
		if(!b[i])
			cnt++;
	cout<<cnt<<'\n';
	return 0;
}