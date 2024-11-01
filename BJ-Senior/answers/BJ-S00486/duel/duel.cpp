#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,oo=1e9,R[N],ton[N],vis[N];
void Bin(int k,int i)
{
	int l=1,r=n+1,pos=oo;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(R[mid]>k&&vis[mid]==0)  r=mid,pos=min(pos,mid);
		else  l=mid+1;
	}
	if(pos!=oo)  ton[i]=1,vis[pos]=1;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>R[i];
	sort(R+1,R+n+1);
	for(int i=1;i<=n;i++)
	{
		//if(vis[i])  continue;
		Bin(R[i],i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)  if(ton[i]==0)  ans++;
	cout<<ans<<endl;
	return 0;
}