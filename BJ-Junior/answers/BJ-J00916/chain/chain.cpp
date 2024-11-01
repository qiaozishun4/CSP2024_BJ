#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l[100000],r[101],c[100000];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>r[i]>>c[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
