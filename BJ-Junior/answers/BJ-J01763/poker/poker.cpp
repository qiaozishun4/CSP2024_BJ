#include<bits/stdc++.h>
using namespace std;
int n,num;
string s[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		cin>>s[i];
		for(int j=1;j<i;j++)
		{
			if(s[j]==s[i])
			{
				f=1;
				break;
			}
		}
		if(!f) num++;
	}
	cout<<52-num<<endl;
	return 0;
}
