#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int i=2,j=1;
    for(i=2,j=1;i<=n;i++)if(a[i]>a[j])j++;
    printf("%d",i-j);
    return 0;
}
