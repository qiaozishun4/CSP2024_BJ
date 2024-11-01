#include<bits/stdc++.h>
using namespace std;
int T,a[114514],ans;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        unsigned int a;
        scanf("%d",&a);
        unsigned int b=(a<<28);
        a^=b;
        b=(b>>16);
        a^=b;
        printf("%u\n",a);
    }
    return 0;
}
