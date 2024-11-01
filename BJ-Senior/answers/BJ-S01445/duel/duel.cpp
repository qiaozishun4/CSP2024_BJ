#include<bits/stdc++.h>
using namespace std;
int p[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int t=n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    sort(p+1,p+n+1);
    for(int i=1;i<n;i++)
    {
        if(p[i+1]>p[i]) t--;
    }
    cout<<t-1<<endl;
    return 0;
}
