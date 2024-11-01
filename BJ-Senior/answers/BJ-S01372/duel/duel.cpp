#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int x,atk,sz;
    bool operator<(const node &rhs)const{
        return rhs.x<x;
    }
};
priority_queue<node> Q,alv;
int sz[100007],m;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sz[x]++;
        m=max(m,x);
    }
    for(int i=1;i<=m;i++){
        if(sz[i]){
            Q.push((node){i,sz[i],sz[i]});
            alv.push((node){i,sz[i],sz[i]});
        }
    }
    int ans=0;
    while(!Q.empty() && !alv.empty()){
        while(!alv.empty() && alv.top().x<=Q.top().x) alv.pop();
        if(alv.empty()) break;
        node u=Q.top();
        Q.pop();
        node v=alv.top();
        alv.pop();
        ans++;
        v.atk--;
        u.sz--;
        if(u.sz) Q.push(u);
        if(v.atk) alv.push(v);
    }
    printf("%d",n-ans);
    return 0;
}