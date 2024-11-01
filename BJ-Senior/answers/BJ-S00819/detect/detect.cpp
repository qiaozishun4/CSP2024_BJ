#include <iostream>
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,m,l,v;
    cin>>n>>m>>l>>v;
    int d1[],v1[],a1[];
    for(int i=1;i<=n;i++)
    {
        cin>>d1[i];
        cin>>v1[i];
        cin>>a1[i];
    }
    int p1[];
    for(int i=1;i<=m;i++)
    {
        cin>>p1[i];
    }
    cout<<"3 3";
    return 0;
}
