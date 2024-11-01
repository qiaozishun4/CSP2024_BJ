#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 10,M = 1e6 + 10;
int n;
int a[N];
bool color[N];
int c[N];
long long ans;
bool st[M];
void dfs(int u){
    if(u == n + 1){
        long long sum = 0;
        for(int i=1;i<=n;i++){
            bool flag = false;
            for(int j=1;j<i;j++){
                if(color[i] == color[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag) c[i] = 0;
            else{
                for(int j=i-1;j>=1;j--){
                    if(color[i] == color[j]){
                        if(a[i] == a[j]) c[i] = a[i];
                        else c[i] = 0;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) sum += c[i];
        ans = max(ans,sum);
        return ;
    }
    color[u] = 0;
    dfs(u + 1);
    color[u] = 1;
    dfs(u + 1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        memset(c,0,sizeof(c));
        memset(color,0,sizeof(color));
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n <= 15){
            dfs(1);
            printf("%lld\n",ans);
        }
        else{
            for(int i=1;i<=n;i++) st[a[i]]++;
            long long ans = 0;
            for(int i=1;i<=1e6;i++){
                if(st[i]){
                    ans += i * (st[i] - 1);
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
