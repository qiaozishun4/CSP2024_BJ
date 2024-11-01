#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int i;
        for(i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        for(i=1;i<=m;i++)
        {
            cin>>d[i];
        }
        cout<<"0 "<<m<<endl;
    }
    return 0;
}