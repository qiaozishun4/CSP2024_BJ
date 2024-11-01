#include <bits/stdc++.h>
using namespace std;
long long n,sum;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("&ll",&n);
    long long r[n+1];
    long long s[n+1];
    long long x[n+1];
    for(long long i=1;i<=n;i++){
        scanf("&ll",&r[i]);
        s[i]=1;
        x[i]=1;
    }
    sort(r+1,r+n+1);
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            if(r[i]<r[j] && x[i]==1 && x[j]==1 && s[j]==1){
                x[i]=0;
                s[i]=0;
                s[j]=0;
            }
            else continue;
        }
    }
    for(long long i=1;i<=n;i++){
        if(x[i]){
            sum++;
        }
    }
    printf("%ll",sum);
    return 0;
}

