#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int r=2;
    for(int i=1;i<=n;i++){
        while(r<n&&(a[r]<=a[i])) ++r;
        if(a[r]>a[i]){
            r++; ans--;
        }
    }
    printf("%d",ans);
    return 0;
}
