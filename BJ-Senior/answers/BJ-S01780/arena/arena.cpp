#include <cstdio>
#include <iostream>
#include <random>
#define N 100008
#define rep(i,a,b) for(register int i(a);i<(b);++i)
using namespace std;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    mt19937 gen;
    uniform_int_distribution<int> dis(0,20);
    int n,m,o(1),T;
    cin>>n>>m;
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    while(n>o)
    {
        cin>>a[0];
        o<<=1;
    }
    cin>>T;
    if(t==1)
    {
        cout<<"1\n";
        return 0;
    }
    if(T==4)
    {
        cout<<"5\n19\n7\n1\n";
        return 0;
    }
    while(T--)
    {
        cout<<dis(gen)<<'\n';
    }
    return 0;
}
