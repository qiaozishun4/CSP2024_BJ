#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100005;
int T,n,m,L,V,d[MAX],v[MAX],a[MAX],p[MAX],lt[MAX],rt[MAX],pass[MAX],pl[MAX],pr[MAX],ru[MAX*2];
vector<int> adj[25][MAX*2];

int findp(int x){
    int l=1,r=m,ans,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(p[mid]<=x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(lt,0,sizeof(lt));
        memset(rt,0,sizeof(rt));
        memset(pass,0,sizeof(pass));
        memset(pl,0,sizeof(pl));
        memset(pr,0,sizeof(pr));
        memset(ru,0,sizeof(ru));

        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];

            if(a[i]==0){
                if(v[i]<=V){
                    pass[i]=1;
                }else{
                    lt[i]=d[i];
                    rt[i]=L;
                }
            }

            if(a[i]>0){
                if(v[i]>V){
                    lt[i]=d[i];
                    rt[i]=L;
                }else{
                    ll x = (V*V-v[i]*v[i])/(2*a[i]);
                    if(x >= L-d[i]){
                        pass[i]=1;
                    }else{
                        lt[i]=d[i]+x+1;
                        rt[i]=L;
                    }
                }
            }

            if(a[i]<0){
                if(v[i]<=V){
                    pass[i]=1;
                }else{
                    ll x = -(v[i]*v[i]-V*V)/(2*a[i]);
                    if(x >= L-d[i]){
                        lt[i]=d[i];
                        rt[i]=L;
                    }else{
                        lt[i]=d[i];
                        rt[i]=d[i]+x;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }

        int ill=0,del=0;
        for(int i=1;i<=n;i++){
            if(!pass[i]){
                if(p[1]<=rt[i] && rt[i]<=p[m]){
                    pr[i]=findp(rt[i]);
                }
                if(p[1]<=lt[i] && lt[i]<=p[m]){
                    pl[i]=findp(lt[i]);
                    if(p[pl[i]]<=lt[i]){
                        pl[i]++;
                    }
                }
                if((p[pl[i]]>=lt[i] && p[pl[i]]<=rt[i]) || (p[pr[i]]>=lt[i] && p[pr[i]]<=rt[i])){
                        ill++;
                }else{
                    pass[i]=1;
                }
            }
        }
        int id=1;
        for(int i=1;i<=n;i++){
            if(!pass[i]){
                for(int j=pl[i];j<=pr[i];j++){
                    adj[T][id].push_back(j+MAX);
                    adj[T][j+MAX].push_back(id);
                    ru[j+MAX]++;
                    ru[id]++;
                }
                id++;
            }
        }
        for(int i=1;i<=id;i++){
            for(int j=MAX+1;j<=MAX+m;j++){
                if(ru[j]==i){
                    bool flag=true;
                    for(int k=0;k<adj[T][j].size();k++){
                        int to=adj[T][j][k];
                        if(ru[to]<=1){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        ru[j]=-1;
                        for(int k=0;k<adj[T][j].size();k++){
                            int to=adj[T][j][k];
                            ru[to]--;
                        }
                    }
                }
            }

        }
        for(int j=MAX+1;j<=MAX+m;j++){
            if(ru[j]>0){
                del++;
            }
        }
        cout<<ill<<" "<<m-del<<endl;
    }
    return 0;
}

