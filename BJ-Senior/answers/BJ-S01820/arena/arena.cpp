#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m,a[100010],c[100010],k,num[25];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
    for(int i = 1;i <= m;++i) scanf("%d",&c[i]);
    int t = 0;
    for(int i = 1;i <= 20;++i){
        if(pow(2,i) >= n){
            t = i;
            break;
        }
    }
    for(int i = 1;i <= t;++i){
        scanf("%d",&num[i]);
    }
    scanf("%d",&t);
    while(t--){
        int x0,x1,x2,x3;
        scanf("%d%d%d%d",&x0,&x1,&x2,&x3);
        int x = x0 * 2 + x1 + x2 + x3;
        printf("%d\n",x);
    }
    return 0;
}
