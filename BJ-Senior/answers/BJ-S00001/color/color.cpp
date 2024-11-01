#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int n;
long long a[N];
long long ans=0;
long long vl[1000005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<=1000000;i++)vl[i]=-i;
        long long sum=0;
        long long mx=0;
        for(int i=1;i<=n;i++)
        {
            long long val=max(vl[a[i]]+sum+a[i],mx+sum);
            if(a[i]==a[i-1])
            {
                //cerr<<"??\n";
                sum+=a[i-1];
            }
            vl[a[i-1]]=max(vl[a[i-1]],val-sum);
            mx=max(mx,vl[a[i-1]]);
			//cerr<<vl[1]<<' ';
        }
        
        //cerr<<'\n';
        cout<<mx+sum<<'\n';
    }
}
