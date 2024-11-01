#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],t[N],b[N],ans,g;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),t[a[i]]++;
    for(int i=1;i<=1e5;i++){
        if(g>=t[i])g-=t[i],ans+=t[i];
        else ans+=g,g=0;
        g+=t[i];
    }
    printf("%d",n-ans);
    return 0;
}
