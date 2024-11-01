#include<bits/stdc++.h>
using namespace std;
int n;
char a[60],b[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int m=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if((a[i]==a[j])&&(b[i]==b[j]))
				m--;
	int ans=52-m;
	cout<<ans;
	return 0;
}
