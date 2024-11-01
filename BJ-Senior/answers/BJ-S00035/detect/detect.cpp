#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,p[100010];
struct car
{
    int d,v,a;
}a[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int ma=0,c=0,s=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].a;
            ma=max(ma,a[i].d);
        }
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=1;i<=m;i++)
            if(p[i]>ma) c++;
        for(int i=1;i<=n;i++)
            if(a[i].v>v) s++;
        cout<<s<<" "<<c<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
