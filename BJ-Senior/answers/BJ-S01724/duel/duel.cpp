#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2,j=1;i<=n;i++){
        if(a[i]>a[j]) ans++,j++;
    }
    printf("%d\n",n-ans);
    return 0;
}