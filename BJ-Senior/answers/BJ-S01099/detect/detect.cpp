#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::sqrt;
int T,d[3002],v[3002],a[3002],p[3002],kcnt[3002];
bool flg[3002][3002];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int kkksc03=1;kkksc03<=T;kkksc03++){
        memset(flg,0,sizeof(flg));
        memset(kcnt,0,sizeof(flg));
        int n,m,L;double V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++)
            {
                if(p[k]<d[i])continue;
                int S = p[k]-d[i],v2 = v[i]*v[i];
                double Vnow = sqrt(((double)v2+S*2.0*a[i]));
                if(V<Vnow){
                    flg[i][k]=1;
                    break;
                }
            }
        }
        int ans=0,cnt=1;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(flg[i][k]==1){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" "<<cnt<<"\n";
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
