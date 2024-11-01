#include <bits/stdc++.h>
using namespace std;
string s[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt;
	cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		int flag=1;
		for (int j=1;j<i;j++)
		{
			if (s[i]==s[j])
			{
				flag=0;
				break;
			}
		}
		cnt+=flag;
	}
	cout<<52-cnt<<"\n";
	return 0;
}
