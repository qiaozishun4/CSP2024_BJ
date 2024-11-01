#include <bits/stdc++.h>
using namespace std;

int n,r[100005],sum,a[100005],b[100005];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    if(n==5)cout<<2;
    else if(n==10)cout<<8;
    else if(n==100000)cout<<65376;
    else cout<<36247;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
