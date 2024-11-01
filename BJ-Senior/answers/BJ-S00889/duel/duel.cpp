#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
int n,ans=1e9;
bool vis[20],exited[20];
map<int,int>app;
vector<int>a;
void dfs(){
    int cnt=0,cntexit=0;
    for(int i=0;i<n;i++){
        cnt+=(vis[i]||exited[i]);
        cntexit+=exited[i];
    }
    if(n-cnt<2){
        ans=min(ans,n-cntexit);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //if(!vis[i]&&!vis[j]){
                bool tvi=vis[i],tvj=vis[j];
                if(a[i]==a[j]&&!vis[i]&&!exited[j]){
                    vis[i]=true;
                    dfs();
                }
                else if(a[i]>a[j]&&!vis[i]&&!exited[j]){
                    vis[i]=vis[j]=true;
                    exited[j]=true;
                    dfs();
                    exited[j]=false;
                }
                vis[i]=tvi,vis[j]=tvj;
                if(a[i]==a[j]&&!vis[j]&&!exited[i]){
                    vis[j]=true;
                    dfs();
                    vis[j]=false;
                }
            //}
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        app[a[i]]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    if(n<=7){
        dfs();
        cout<<ans<<endl;
        
        return 0;
    }
    if(app.size()==2){
        cout<<max(app.begin()->second,app.rbegin()->second)<<endl;
        return 0;
    }
    if(app.size()==n){
        cout<<n/2<<endl;
        return 0;
    }
    return 0;
}
/*
3 2 2 1 1
3 2 v(2) e(1) 1
3 v(2) v(2) e(1) e(1)
v(3) e(2) v(2) e(1) e(1)
OK
*/