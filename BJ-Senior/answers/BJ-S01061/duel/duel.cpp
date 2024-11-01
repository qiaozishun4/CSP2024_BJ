#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int> mp1,mp2;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            idx++;
        }
        mp1[idx]++;
        mp2[idx]++;
    }
    if(idx==1)
    {
        cout<<n;
        return 0;
    }
    int l=1,r=2;
    while(r<=idx)
    {
        if(mp1[l]<mp2[r])
        {
            mp2[r]-=mp1[l];
            mp1[l]=0;
            mp2[l]=0;
        }
        else
        {
            mp1[l]-=mp2[r];
            mp2[l]=min(mp1[l],mp2[l]);
            mp2[r]=0;
        }
        while(mp1[l]==0&&l<=idx) l++;
        r=max(r,l+1);
        while(mp2[r]==0&&r<=idx) r++;
    }
    int ans=0;
    for(int i=1;i<=idx;i++)
    {
        ans+=mp1[i];
    }
    cout<<ans;
    return 0;
}