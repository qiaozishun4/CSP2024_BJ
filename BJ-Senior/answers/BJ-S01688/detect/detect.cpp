#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m,l,v;
struct car{
    int d0,v0,acc;
}a[N];
int b[N];
bool flg[N]={false};
bool flg2[N]={false};
vector<int> g[N];
bool cmp(vector<int> v1,vector<int> v2){
    return v1.size()>v2.size();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].d0>>a[i].v0>>a[i].acc;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        bool fflg=true;
        for(int i=1;i<=n;i++){
            if(a[i].acc!=0){
                fflg=false;
                break;
            }
        }
        if(fflg){
            int ans1=0;
            int maxn=0;
            for(int i=1;i<=m;i++){
                maxn=max(maxn,b[i]);
            }
            for(int i=1;i<=n;i++){
                if(a[i].v0>v&&a[i].d0<=maxn){
                    ans1++;
                }
            }
            if(ans1==0){
                cout<<0<<' '<<m<<'\n';
            }
            else{
                cout<<ans1<<' '<<m-1<<'\n';
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            flg[i]=false,flg2[i]=false;
        }
        for(int i=1;i<=m;i++){
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i].d0>b[j]){
                    continue;
                }
                int s=b[j]-a[i].d0;
                if(1ll*a[i].v0*a[i].v0+2ll*a[i].acc*s>1ll*v*v){//是否超速，注意ll
                    flg[i]=true;
                    g[j].push_back(i);
                }
            }
        }
        int ans1=0;
        for(int i=1;i<=n;i++){
            ans1+=flg[i];
        }
        cout<<ans1<<' ';
        int kkk=0,ans2=0;
        for(int i=1;i<=m;i++){
            if(kkk==ans1){
                break;
            }
            sort(g+1,g+1+m,cmp);
            ans2++;
            for(int j=0;j<g[1].size();j++){
                if(flg2[g[1][j]]==false){
                    kkk++;
                }
                flg2[g[1][j]]=true;
            }
            for(int j=1;j<=m;j++){
                vector<int> tmp;
                for(int k=0;k<g[j].size();k++){
                    if(!flg2[g[j][k]]){
                        tmp.push_back(g[j][k]);
                    }
                }
                g[j]=tmp;
            }
        }
        cout<<m-ans2<<'\n';
        //记录他都检测了那些车
        //记录他的大小
    }
    return 0;
}