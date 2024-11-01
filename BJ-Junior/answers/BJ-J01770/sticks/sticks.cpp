#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T, n;
string h[MAXN]={"-1", "-1", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88", "108", "188", "200", "208", "288", "688", "888"};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for(int i=22; i<=MAXN; i++)
    {
        h[i]=h[i-7]+"8";
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<h[n]<<"\n";
    }
    return 0;
}
