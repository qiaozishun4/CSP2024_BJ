#include <algorithm>
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int N=1e5+2;
int n,ans;
int a[N];
int lb;//next start point,increasing num
bool bs(int k)
{
	int l=lb,r=n;
	while(r-l>3)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=k) l=mid+1;
		else r=mid;
	}
	for(int i=l;i<=r;i++)
	{
		if(a[i]>k) 
		{
			lb=i+1;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		bool tmp=bs(a[i]);
		if(!tmp) break;
		//no num is bigger than a[i],nor bigger than a[i+1]
		ans+=1;
	}
	printf("%d\n",n-ans);
	return 0;
}