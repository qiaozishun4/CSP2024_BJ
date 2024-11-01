#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int pos=1,cnt=0;
    for(int i=1;i<=n;i++){
        if(pos<=n&&a[i]>a[pos]){
            pos++;
            cnt++;
        }
    }
    int ans=n-cnt;
    printf("%d\n",ans);
    return 0;
}