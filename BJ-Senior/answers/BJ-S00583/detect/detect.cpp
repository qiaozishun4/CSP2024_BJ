#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,ans,ans2,x;
pair<int,int> f[3010];
struct data{
    int sum,s;
    bool vis[3010];
}p[3010];
bool visf[3010],flag;
bool cmp(data x,data y){
    if(x.sum>y.sum){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            if(a>0){
                if(v<=V){
                    if((V*V-v*v)%2*a==0){
                        x=(V*V-v*v)/2*a;
                    }else{
                        x=(V*V-v*v)/2*a;
                        x++;
                    }
                    if(d+x<L){
                        f[i].first=d+x;
                        f[i].second=L;
                    }
                }
            }else{
                f[i].first=d;
                f[i].second=L;
            }
            if(a==0){
                if(v>V){
                    f[i].first=d;
                    f[i].second=L;
                }
            }
            if(a<0){
                if(v>V){
                    if((V*V-v*v)%2*a==0){
                        x=(V*V-v*v)/2*a;
                    }else{
                        x=(V*V-v*v)/2*a;
                        x++;
                    }
                    if(d+x<L){
                        f[i].first=d;
                        f[i].second=d+x;
                    }else{
                        f[i].first=d;
                        f[i].second=L;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i].s;
        }
        for(int i=1;i<=n;i++){
            flag=1;
            for(int k=1;k<=m;k++){
                if(p[k].s>=f[i].first&&p[k].s<=f[i].second){
                    p[k].vis[i]=1;
                    flag=0;
                    visf[i]=1;
                }
            }
            if(flag&& f[i].first==0 &&f[i].second==0 ){
                ans++;
            }
        }
        cout<<(n-ans)<<" ";
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i].vis[j]){
                    p[i].sum++;
                }
            }
        }
        sort(p+1,p+1+m,cmp);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(visf[j]){
                    if(p[i].vis[j]){
                        visf[j]=0;
                        ans2++;
                    }
                }
            }
        }
        cout<<(n-ans2);
    }
    return 0;
}
