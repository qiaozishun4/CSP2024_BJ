#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int maxn=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[l]){
            continue;
        }
        l++;
    }
    printf("%d",n-l+1);
    return 0;
}
