#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[100005],b[100005],i,l,sum,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        if(a[i]>a[i-1]){
            l++;
        }
        b[l]++;
    }
    for(i=1;i<=l;i++){
        if(b[i]>b[i+1]){
            sum+=b[i]-b[i+1];
        }
        else{
            if(sum<=b[i+1]-b[i]){
                sum=0;
            }
            else{
                sum=sum-b[i+1]+b[i];
            }
        }
    }
    cout<<sum;
    return 0;
}
