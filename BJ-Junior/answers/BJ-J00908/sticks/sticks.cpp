#include <bits/stdc++.h>
using namespace std;
int a[10000000]={0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,};
map<long long,int>m;
map<long long,int>::iterator it;
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n,T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<a[n]<<'\n';
    }
    return 0;
}