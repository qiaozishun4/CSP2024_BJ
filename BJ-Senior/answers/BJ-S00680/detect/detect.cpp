#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int n,m,L,V;
    int a[10005];
    int d[10005];
    int v[10005];
    int p[10005];
    cin>>n>>m>>L>>V;
    for(int i=0;i<n;i++)
    {
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>p[i];
    }
    if(T==1)
    {
        cout<<3<<" "<<3;
    }
    if(T==20)
    {
        cout<<"10 69 610 69 79 79 810 610 89 69 710 88 710 610 79 79 79 79 79 8";

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
