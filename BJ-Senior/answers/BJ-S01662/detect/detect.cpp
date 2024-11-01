#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int a[100005],k[100005],v[100005],d[100005],n,m,l,r,p[100005];
vector<int> vt[100005];
int maxn=0,sum=0;
int v1[100005],v2[100005];
void dfs(int st){
    if(st>m){
        maxn=max(maxn,sum);
        return ;
    }
    memset(v2,0,sizeof(v2));
    for(int i=0;i<vt[st].size();i++){
        v2[vt[st][i]]=1;
    }
    for(int i=1;i<=m;i++){
        if(p[i]==1||i==st){
            continue;
        }
        for(int j=0;j<vt[i].size();j++){
            v2[vt[i][j]]=0;
        }
    }
    int o=0;
    for(int i=0;i<vt[st].size();i++){
        if(v2[vt[st][i]]==1&&vt[st][i]!=0){
            o=1;
            v2[vt[st][i]]=0;
        }
    }
    if(o==1){
        p[st]=0;
        dfs(st+1);
    }else{
        dfs(st+1);
        p[st]=1;
        sum++;
        dfs(st+1);
        sum--;
        p[st]=0;
    }
    return ;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out ","w",stdout);
    int t,cnt;
    cin>>t;
    for(int g=1;g<=t;g++){
        cnt=0;
        sum=0;
        maxn=0;
        if(t!=t-1){
            for(int i=1;i<=m;i++){
                for(int j=0;j<vt[i].size();j++){
                    vt[i][j]=0;
                }
            }
        }
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        memset(p,0,sizeof(p));
        cin>>n>>m>>l>>r;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>k[i];
        }
        for(int i=1;i<=n;i++){
                for(int x=1;x<=m;x++){
                    if(k[x]>=d[i]){
                        if(a[i]<0){
                        if(k[x]-d[i]>-1.0*v[i]*v[i]/2*1.0/a[i]){
                            break;
                        }
                        }
                        if(double(double(1.0*sqrt(double(1.0*v[i]*v[i])+double(2.0*a[i]*(k[x]-d[i])))))>r&&v1[i]==0){
                            cnt++;
                            v1[i]=1;
                        }
                        if(double(double(1.0*sqrt(double(1.0*v[i]*v[i])+double(2.0*a[i]*(k[x]-d[i])))))>r){
                            vt[x].push_back(i);
                        }
                    }
                }
        }
        cout<<cnt<<' ';
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
