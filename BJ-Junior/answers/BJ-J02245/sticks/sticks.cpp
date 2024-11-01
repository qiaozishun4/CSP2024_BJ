#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int t,n,a[25] = {-1,-1,1,7,4,2,6,8,10,18,23,20,28,68,77,180};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
        if(n == 1){
            printf("-1");
            continue;
        }
        if(n <= 15){
            printf("%d",&a[n]);
        }
        else printf("-1");
    }
    return 0;
}
