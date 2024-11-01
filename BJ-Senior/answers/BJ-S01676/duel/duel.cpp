#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int cnt[100005];
int cnt2[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int maxx=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        cnt2[a[i]]++;
        maxx=max(maxx,a[i]);
    }
    int l,r=0;
    l=0;
    int ans=0;
    for(r=l+1;r<=maxx;r++)
    {
        if(cnt2[l]==0)
        {
            while(cnt2[l]==0) l++;
            r=l+1;
        }
        //cout<<l<<' '<<r<<'*'<<endl;
        if(cnt[r]==0)
        {
            //cout<<"+";
            continue;
        }
        if(cnt2[l]<cnt[r])
        {
            ans+=cnt2[l];
            cnt[r]-=cnt[l];
            cnt[l]=0;
            cnt2[l]=0;
        }
        else if(cnt2[l]==cnt[r])
        {
            ans+=cnt[l];
            cnt[l]=0;
            cnt[r]=0;
            cnt2[l]=0;
        }
        else if(cnt2[l]>cnt[r])
        {
            ans+=cnt[r];
            cnt[l]-=cnt[r];
            cnt[r]=0;
            cnt2[l]-=cnt2[r];
        }
    }
    cout<<n-ans<<endl;//
    //

    return 0;
}
