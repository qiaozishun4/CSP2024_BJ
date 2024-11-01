#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long a[N],b[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        b[i]=1;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            if(a[i]<a[j]&&b[j]==1&&a[i]!=-1){
                b[i]=0;
                b[j]=0;
                a[i]=-1;
                continue;
            }
        }
    }

    for(long long i=1;i<=n;i++){
        if(a[i]!=-1){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
