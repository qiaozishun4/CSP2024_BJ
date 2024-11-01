#include<bits/stdc++.h>
using namespace std;
int d[100010],v[100010],a[100010],p[100010];
int n,m,l,V,lst;
void solve1(){
    printf("%d %d",0,n);
}
void solveA(){
    int ans = 0;
    for (int i = 1;i <= n;i++){
        if(v[i] > V && d[i] <= lst) ans++;
    }
    printf("%d ",ans);
    if(ans) printf("%d\n",n - 1);
    else printf("%d\n",n);
}
void solveB(){

}
void solve(){
    scanf("%d%d%d%d",&n,&m,&l,&V);
    for (int i = 1;i <= n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
    lst = 0;
    for (int i = 1;i <= m;i++){
        scanf("%d",&p[i]);
        lst = max(lst,p[i]);
    }
    bool flag = true;
    for (int i = 1;i <= n;i++) if(a[i] != 0){
        flag = false;
        break;
    }
    if(flag) solveA();
    solve1();
}
int main ()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
