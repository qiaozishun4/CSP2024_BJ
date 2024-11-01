#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],id[100005],top,ans1,ans2;
bool vis[100005];
vector <int> st[100005],ed[100005];
int myceil(int x,int y){
    return x / y + (bool)(x % y);
}
void solve(int ll,int rr,int x){
    ll = lower_bound(p + 1,p + 1 + m,ll) - p;
    rr = upper_bound(p + 1,p + 1 + m,rr) - p - 1;
    if(ll <= rr){
        st[ll].push_back(x);
        ed[rr].push_back(x);
        ans1++;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            vis[i] = false;
        }
        for(int i = 1;i <= m;i++){
            scanf("%d",&p[i]);
        }
        for(int i = 1;i <= m;i++){
            st[i].clear();
            ed[i].clear();
        }
        ans1 = ans2 = top = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] > 0){
                if(V < v[i]){
                    solve(d[i],l,i);
                }
                else{
                    solve(d[i] + (V * V - v[i] * v[i]) / (2 * a[i]) + 1,l,i);
                }
            }
            else if(a[i] < 0){
                if(V < v[i]){
                    solve(d[i],d[i] + myceil(v[i] * v[i] - V * V,-2 * a[i]) - 1,i);
                }
            }
            else if(V < v[i]){
                solve(d[i],l,i);
            }
        }
        for(int i = 1;i <= m;i++){
            for(int j = 0;j < st[i].size();j++){
                id[++top] = st[i][j];
            }
            for(int j = 0;j < ed[i].size();j++){
                if(!vis[ed[i][j]]){
                    for(int k = 1;k <= top;k++){
                        vis[id[k]] = true;
                    }
                    top = 0;
                    ans2++;
                }
            }
        }
        printf("%d %d\n",ans1,m - ans2);
    }
    return 0;
}
