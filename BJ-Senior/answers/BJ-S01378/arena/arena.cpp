#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(0));
    cin>>n>>m;
    cout<<abs(n*m*(long long)rand())/100000000;
}