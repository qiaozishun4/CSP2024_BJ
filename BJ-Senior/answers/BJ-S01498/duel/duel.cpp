#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int b[N];
int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    int res = 0;
    for(int i = 1;i<N-10;i++){
        res = max(res,b[i]);
    }
    printf("%d",res);

    return  0;
}
