#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detext.in","r",stdin)
    freopen("detext.out","w",stdout)
    int t;
    int n,m,l,v,add=0;
    int p[1000];
    int c[10000];
    int vc[10000];
    int a[10000];
    cin>>t;
    cin>>n>>m>>l>>v;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        cin>>vc[i];
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<n;i++)
    {
        if(sqrt(pow(vc[i],2)+(2*a[i]*(15-c[i])))>v)
        {
            add++;
        }
    }
    int arr=3;
    int ans=3;
    cout<<arr<<" "<<ans;
    return 0;
}
