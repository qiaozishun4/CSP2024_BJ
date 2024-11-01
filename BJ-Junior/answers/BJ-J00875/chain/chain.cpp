#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n,k,q;
vector<int> v[N];
struct node{
    int id,r,c;
};
bool bfs(int r,int c){
    queue<node> q;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == 1){
                for(int l=j+1;l<=j+k-1;l++) q.push({i,1,v[i][l]});
                j = j + k - 1;
            }
        }
    }
    while(!q.empty()){
        node t = q.front();
        q.pop();
        if(t.r == r && t.c == c){
            return true;
        }
        if(t.r < r){
            for(int i=1;i<=n;i++){
                if(i == t.id) continue;
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j] == t.c){
                        for(int l=j+1;l<=j+k-1;l++) q.push({i,t.r+1,v[i][l]});
                        j = j + k - 1;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        scanf("%d %d %d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            int L;
            scanf("%d",&L);
            while(L -- ){
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        while(q -- ){
            int r,c;
            scanf("%d %d",&r,&c);
            printf("%d\n",bfs(r,c));
        }
    }
    return 0;
}
