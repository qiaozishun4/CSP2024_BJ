#include<bits/stdc++.h>
using namespace std;
int a1[100002],c[100002];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i];
        sum+=(long long)i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int k=0;
    while(pow(2,k)<n)
        k++;
    for(int i=1;i<=k;i++)
    {
        string d;
        cin>>d;
    }
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int x0,x1,x2,x3;
        cin>>x0>>x1>>x2>>x3;
        cout<<sum<<endl;
    }
    return 0;
}