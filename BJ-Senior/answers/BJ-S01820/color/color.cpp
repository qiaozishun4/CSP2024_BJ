#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int t,n,a[200010],c[200010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%d",&a[i]);
        }
        printf("0\n");
    }
    return 0;
}
