#include<bits/stdc++.h>
using namespace std;
int n,c[100100],ans;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    sort(c,c+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt++;
        if(c[i]!=c[i+1])
        {
            ans=max(cnt,ans);
            cnt=0;
        }
    }
    cout<<ans;
    return 0;
}
