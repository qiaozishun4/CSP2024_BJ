#include<bits/stdc++.h>
using namespace std;
int a[100086];
int b[100086];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    int ca=0;
    int ans=n;
    for(int i=1;i<=100000;i++)
    {
        if(b[i]==0) continue;
        if(b[i]>ca)
        {
            ans-=ca;
            ca=b[i];
        }
        else
        {
            ans-=b[i];
        }

    }
    cout<<ans<<endl;
    return 0;
}
