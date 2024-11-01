#include<bits/stdc++.h>
using namespace std;
long long n,a[101001],c[101001],cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=100000;i++){
        if(c[i]){
            if(c[i]>=c[cnt])n-=c[cnt];
            else {n-=c[i];c[i]+=c[cnt]-c[i];}
            cnt=i;
        }
    }
    cout<<n;
    return 0;
}