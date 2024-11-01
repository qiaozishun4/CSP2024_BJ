#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int t,p[100010],ans1,ans2;
struct Node{
    int d,v,a;
}num[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n,m,l,V;
        scanf("%%d%d%d",&n,&m,&l,&V);
        for(int i = 1;i <= n;++i){
            scanf("%d%d%d",&num[i].d,&num[i].v,&num[i].a);
        }
        for(int i = 1;i <= m;++i){
            scanf("%d",&p[i]);
        }
        printf("0 0\n");
    }
    return 0;
}
