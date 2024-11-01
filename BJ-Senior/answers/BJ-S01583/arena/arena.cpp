#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
struct node{
    int d,v,a;
}k[N];
int n,m,l,v,p[N];
bool b[N],f[N];
int minn=1e9+7;
void dfs(int x,vector<int> h[]){
    if(x==m){
        int cnt=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++){
            if(b[i]==true){
                for(int j=0;j<h[i].size();j++){
                    f[h[i][j]]=true;
                }
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]==false){
                return ;
            }
        }
        minn=min(minn,cnt);
    }
    b[x]=true;
    dfs(x+1,h);
    b[x]=false;
    dfs(x+1,h);
}
int main(){
    freopen("detect1.in","r",stdin);
    int T;cin>>T;
    while(T--){
        vector<int> h[N];
        memset(b,0,sizeof(b));
        memset(h,0,sizeof(h));
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
            cin>>k[i].d>>k[i].v>>k[i].a;
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++){
            double left,right,d=0;
            if(k[i].a!=0){
                d=ll(v*v-k[i].v*k[i].v)*1.0/ll(2*k[i].a);
                if(k[i].v>v)    left=k[i].d,right=k[i].d+d;
                else    left=k[i].d+d,right=N;
            }else{
                if(k[i].v>v)left=k[i].d,right=N;
                else    left=-1,right=-1;
            }
            for(int j=1;j<=m;j++)
                if(p[j]<right && p[j]>left)
                    h[j].push_back(i);
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(h[i].size()>0){
                cnt++;
            }
        }
        dfs(0,h);
        cout<<cnt<<' '<<minn<<'\n';
    }
    return 0;
}
//cout<<"在"<<p[j]<<"位置的"<<j<<"号检测仪探测到"<<i<<"号车辆超速\n";
