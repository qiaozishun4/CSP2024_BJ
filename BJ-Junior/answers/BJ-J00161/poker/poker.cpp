#include<bits/stdc++.h>
using namespace std;
char c[100010];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		c['a']=1;
		if(c['a']>1)
		{
			continue;
		}
		else
		{
			cnt++;
		}
	}
	cout<<52-cnt<<endl;
	return 0;
}
