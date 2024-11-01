#include<bits/stdc++.h>
using namespace std;
long long a[10e5];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,k=0,max=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }for(long long i=1;i<=n;i++){
        if(a[i]>max) max=a[i];
    }k=n;
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            if(a[i]<max&&a[j]==max&&a[i]!=0&&a[j]!=0){
                k--;
                a[j]=0;
                max=0;
                for(long long i=1;i<=n;i++){
                    if(a[i]>max) max=a[i];
                }
            }
        }
    }cout<<k;


return 0;
}