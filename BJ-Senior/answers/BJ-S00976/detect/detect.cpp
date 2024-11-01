#include<iostream>
#include<algorithm>
using namespace std;
long long T,n,m,L,V;
long long p[100010];
long long ans;
struct car{
    int d;
    int v;
    int a;
}c[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
            cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>p[i];
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++)
            if(c[i].d<=p[m]&&c[i].v>V) ans++;
        cout<<ans<<" ";
        if(ans!=0) cout<<m-1<<endl;
        else cout<<m<<endl;
    }
    return 0;
}

