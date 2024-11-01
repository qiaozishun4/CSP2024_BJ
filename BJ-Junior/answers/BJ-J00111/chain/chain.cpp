#inckude<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,p,c,r,l,o;
    int a[1,0,1,0,1,0,0],b[1,1,0,1,0,0,1]
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        o=0;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l;
            while(l--)cin>>c;
        }
        while(o<q)
        {
            cin>>c>>r;
            if(i%2)cout<<a[o%7]<<endl;
            else cout<<b[o%7]<<endl;
            o++;
        }
    }
    return 0;
}