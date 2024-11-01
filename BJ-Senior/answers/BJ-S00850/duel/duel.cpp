#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=1;
	}
	
		
	for(int i=0;i<=n;i++)
	{
		if(a[i]==0)
		{
			b[i]=0;
		}
		for(int j=0;j<=i;j++)
		{
			if(a[i+1]>a[i]&&b[i]!=0)
			b[i]=0;
			
			
		}
	}
	for(int j=0;j<=n;j++)
	{	
		if(b[j]!=0) ans++;
	}
	cout<<ans;
	

}
