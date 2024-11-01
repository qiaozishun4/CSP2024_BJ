#include <iostream>
#include <cstring>
using std::ios;
using std::cin;
using std::cout;
using std::endl;

const int N=1e5+5;
int T,n,m,L,V,d[N],v[N],a[N],p[N],ans1=0,ans2=0;
bool vis[N];

inline int get_speed_sq(int v0,int a,int x)
{
    return 2*a*x+v0*v0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;
    while(T--){
        bool aa=1,bb=1,cc=1;
        memset(vis,0,sizeof(vis));
        ans1=0; ans2=0;
        cin>>n>>m>>L>>V;
        V=V*V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0){
                aa=0;
                bb=0;
            }
            if(a[i]>0){
                aa=0;
                cc=0;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(aa){
            ans2=m-1;
            for(int i=1;i<=n;i++){
                if(v[i]*v[i]>V){
                    ans1++;
                }
            }
            cout<<ans1<<' '<<ans2<<endl;
            continue;
        }
        if(bb){
            ans2=m-1;
            for(int i=1;i<=n;i++){
                if(get_speed_sq(v[i],a[i],p[m]-d[i])>V){
                    ans1++;
                }
            }
            cout<<ans1<<' '<<ans2<<endl;
            continue;
        }
        for(int i=m;i>=1;i--){
            bool fl=1;
            for(int j=1;j<=n;j++){
                if(p[i]>=d[j] && p[i]*2*a[j]>=(d[j]*2*a[j]-v[j]*v[j]) && !vis[j]){
                    if(get_speed_sq(v[j],a[j],p[i]-d[j])>V){
                        fl=0;
                        vis[j]=1;
                    }
                }
            }
            if(fl) ans2++;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                ans1++;
            }
        }
        cout<<ans1<<' '<<ans2<<endl;
    }
 
    fclose(stdin);
    fclose(stdout);
    return 0;
}