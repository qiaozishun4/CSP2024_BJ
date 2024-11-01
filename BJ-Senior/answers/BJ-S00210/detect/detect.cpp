#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,d[N],v[N],p[N],a[N],cur[N],cnt,shadow[N][N];
//  d:south place    v:chu speed  a:jia speed
int main()
{
freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);                                   
    cin>>t;
    while(t--)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>v[i]>>a[i]; 
        for(int j=1;j<=m;j++)
        {
            int minn;
            cin>>p[j];
            cur[j]=sqrt((p[j]-d[j])*abs(a[i])*v[i]);
            if(cur[j]<V)
                shadow[j][minn++]=0;
        }
        for(int i=1;i<=n;i++){
                
        for(int j=1;j<=m;j++)
            if(shadow[i][j]>V)
                break;
            cnt++;
        }
        cout<<cnt<<' ';
    }
    return 0;
}