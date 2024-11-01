#include<bits/stdc++.h>
using namespace std;
struct node{
    int sum;
    bool is;
    bool out;
}r[1000010];
bool cmp(node x,node y)
{
    return x.sum<y.sum;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i].sum;
        r[i].is=0;
        r[i].out=0;
    }
    sort(r+1,r+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(r[i-1].out)
		{
			continue;
		}
		if(r[i-1].sum==r[i].sum)
		{
			continue;
		}
		if(r[i-1].sum!=r[i].sum)
		{
			r[i-1].out=1;
			r[i].is=1;
		}
	}
	
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!r[i].out)
        {
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}
