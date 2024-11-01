#include<bits/stdc++.h>
using namespace std;
double speed(int d,int v,int a,int p){
    if(d>p)return -1.00;
    return sqrt(v*v+2*a*(p-d));
}
struct node{
    int d,v,a;
}c[100005];
int p[100005];
int n,m,l;
queue<int> q[100005];
bool vis[100005];
int minn;
bool k=1;
void dfs(int step,int sum){
    if(!k)return;
    if(sum>=minn)return;
    if(step==m+1){
        for(int i=1;i<=n;i++){
            if(vis[i])return;
        }
        minn=sum;
        k=0;
        return;
    }
    dfs(step+1,sum);
    queue<int> s=q[step];
    queue<int> s2;
    while(!s.empty()){
        if(vis[s.front()]){
            vis[s.front()]=0;
            s2.push(s.front());
        }
        s.pop();
    }
    dfs(step+1,sum+1);
    while(!s2.empty()){
        vis[s2.front()]=1;
        s2.pop();
    }
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        minn=10000000;
        double V;
        scanf("%d %d %d",&n,&m,&l);
        cin>>V;
        for(int i=1;i<=n;i++)scanf("%d %d %d",&c[i].d,&c[i].v,&c[i].a);
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i].a<=0&&c[i].d>p[j]&&speed(c[i].d,c[i].v,c[i].a,p[j])>V)break;
                if(speed(c[i].d,c[i].v,c[i].a,p[j])>V){
                    ans++;
                    vis[i]=1;
                    for(int k=j;k<=m;k++){
                        if(speed(c[i].d,c[i].v,c[i].a,p[k])>V){
                            q[k].push(i);
                        }else{
                            if(c[i].a<=0)break;
                        }
                    }
                    break;
                }
            }
        }
        printf("%lld ",ans);
        // for(int i=1;i<=m;i++){
        //     while(!q[i].empty()){
        //         cout<<p[i]<<":"<<q[i].front()<<" ";
        //         q[i].pop();
        //     }
        //     cout<<endl;
        // }
        // cout<<"---------------"<<endl;
        k=1;
        dfs(1,0);
        printf("%d\n",m-minn);
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=m;i++){
            while(!q[i].empty())q[i].pop();
        }
    }
    return 0;
}