#include<bits/stdc++.h>
using namespace std;
int vis[1000001]={};
int ot[1000001]={};
long long a[100001];
bool k(long long a,long long b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,k);
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            if(a[j]>a[i]){
                if((!ot[i])&&(!vis[j])){
                    ot[i]=1;
                    vis[j]=1;
                }
            }
        }
    }
    long long sum=0;
    for(long long i=1;i<=n;i++){
        if(ot[i]==0){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}