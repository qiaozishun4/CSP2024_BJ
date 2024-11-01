#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        cout<<min(k,n*m);
    }
return 0;
}
