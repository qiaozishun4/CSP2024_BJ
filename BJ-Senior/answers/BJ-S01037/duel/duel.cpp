#include<bits/stdc++.h>
using namespace std;
long long a[100010]={0};
long long pre[100010]={0};

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    long long ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long last=0;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=a[i]-a[i-1];

        if(pre[i]!=0)
        {
            ans-=min(cnt,last);
            last-=min(cnt,last);
            last+=cnt;
            cnt=0;
        }
        cnt++;
    }
    ans-=min(cnt,last);
    cout<<ans;
    return 0;
}
