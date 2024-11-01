#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50,INF = 0x3f3f3f3f;
int t,n;
int a[maxn];
int color[maxn];
int cal(int colo[]){
    int ans = 0,c[maxn],pos;
    for(int i = 1;i <= n;i++){
        bool flag =1;
        for(int j = i - 1;j >= 1;j--){
            if(colo[i] == colo[j]){
                flag = 0,pos = j;
                break;
            }
        }
        if(flag)c[i] = 0;
        else{
            if(a[pos] == a[i])c[i] = a[i];
            else c[i] = 0;
        }
    }
    for(int i = 1;i <= n;i++)ans += c[i];
    return ans;
}
int ans;
void DFS(int x,int col){
    if(x == n + 1){
        //for(int i =1;i <= n;i++)printf("%d ",color[i]);
        ans = max(ans,cal(color));
        //printf("\n%d\n",ans);
        return;
        //return ans;
    }
    color[x] = col;
    DFS(x + 1,1);
    DFS(x + 1,0);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans = -INF;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        DFS(1,1);
        printf("%d\n",ans);
    }
    return 0;
}
