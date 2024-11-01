#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int cnt=0;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int n;
    cin>>n;
    bool f=0;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>2)f=1;
        if(a[i]==2)cnt2++;
        if(a[i]==1)cnt1++;
        b[a[i]]++;
    }
    sort(a+1,a+n+1,cmp);
    if(f==0)
    {
        if(cnt2>=cnt1)
        {
            cout<<n-cnt1;
            return 0;
        }
        if(cnt2<cnt1)
        {
            cout<<n-cnt2;
            return 0;
        }
    }
    if(f==1)
    {
        int cnt_=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])continue;
            cnt_+=b[a[i-1]];
            if(b[a[i]]>=cnt_)
            {
                cnt+=cnt_;
                cnt_=0;
            }
            if(b[a[i]]<cnt_)
            {
                cnt+=b[a[i]];
                cnt_-=b[a[i]];
            }
        }
        cout<<n-cnt;
    }
    return 0;
}