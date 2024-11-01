#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],v[N],a[N];
int p[N];
int l_e[N],r_e[N];
bool b[N];
bool dis[N];
int n,m;
int le(int k,int V,int L){
    if(a[k]==0){
        if(v[k]>V)l_e[k]=d[k],r_e[k]=L;
        else l_e[k]=-1,r_e[k]=-1;
    }
    if(a[k]>0)l_e[k]=d[k]+ceil(((double)((V+1)*(V+1)-(double)(v[k]*v[k])))/(double)(2*a[k])),r_e[k]=L;
    if(a[k]<0){
        if(v[k]>V)l_e[k]=d[k],r_e[k]=d[k]+floor(((double)(V*V)-(double)(v[k]*v[k]))/(double)(2*a[k]));
        else l_e[k]=-1,r_e[k]=-1;
    }
}
bool cmp(int a,int b){
    return a<b;
}
int ans;
void dfs(int now,int k){
    if(now>n){
        for(int i=1;i<=n;i++){
            if(l_e[i]==-1)continue;
            bool flag=0;
            for(int j=1;j<=m;j++)
                if(dis[j]==1&&l_e[i]<=p[j]&&p[j]<=r_e[i]){flag=1;}
            if(flag==0)return;
        }
        ans=min(ans,k);
    }else{
        dis[now]=1;
        dfs(now+1,k+1);
        dis[now]=0;
        dfs(now+1,k);
    }
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int L,V;
        cin>>n>>m>>L>>V;
        int type=2;
        int dro=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0)type=1;
            le(i,V,L);
            if(l_e[i]==-1)dro++;
        }
        for(int i=1;i<=m;i++)
            cin>>p[i];
        int ans_1=0;
        for(int i=1;i<=n;i++){
            if(l_e[i]==-1)continue;
            int x=(upper_bound(p+1,p+m+1,r_e[i])-1)-p;
            if(r_e[i]>=p[x]&&l_e[i]<=p[x]){
                ans_1++;
            }
        }
        cout<<ans_1<<" ";
        if(type==1){
            ans=1e9;
            memset(dis,0,sizeof(dis));
            dfs(1,0);
            cout<<n-ans-dro<<endl;
        }else{
            cout<<p[m]<<endl;
        }
    }
    return 0;
}
