#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],rkrk[N],sum[N],sum1[N];
int ans,cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    rkrk[1] = 1; sum[1] = 1;
    for(int i=2;i<=n;i++){
        if(a[i] == a[i-1]){
            rkrk[i] = rkrk[i-1];
            sum[rkrk[i]]++;
        }
        else{
            rkrk[i] = rkrk[i-1]+1;
            sum[rkrk[i]]++;
        }
    }
    cnt = rkrk[n];
    for(int i=1;i<=cnt;i++) sum1[i] = sum[i];
    int p = 2,tmp;
    for(int i=1;i<=cnt;i++){
        tmp = 0;
        p = max(p,i+1);
        while(tmp<sum1[i] && p<=cnt){
            tmp += sum[p];
            if(tmp <= sum1[i]){
                p++;
            }
            else{
                sum[p] = tmp-sum1[i];
            }
        }
        if(tmp < sum1[i]){
            ans += sum1[i]-tmp;
        }
    }
    printf("%d",ans);
    return 0;
}
