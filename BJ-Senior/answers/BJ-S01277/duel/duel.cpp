#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]==1?s1++:s2++;
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(1)
    {
        while(r<=n+1&&a[l]==a[r++]);
        if(l>n||r>n+1) break;
        //printf("l=%d r=%d ans=%d\n",l,r,ans);
        l++;
        ans++;
    }
    cout<<n-ans;
    return 0;
}
