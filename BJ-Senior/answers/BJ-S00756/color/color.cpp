#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+7;
int c[N],a[N],n;
bool v[N];
void subset(){
    memset(c,0,sizeof(c));
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<i;j++){
            if(i&(1<<j))v[j+1]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==1){
            for(int j=i-1;j>=1;j--){
                if(v[j]==1){
                    if(a[i]==a[j])
                    c[i]=a[i];
                    break;
                }
            }
        }else{
            for(int j=i-1;j>=1;j--){
                if(v[j]==0){
                    if(a[i]==a[j])
                    c[i]=a[i];
                    break;
                }
            }
        }
    }
}
void s(){
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    subset();
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=c[i];
    }
    cout<<ans;
}
int main(){
    int r;
    cin>>r;
    while(r--){
        s();
    }
    return 0;
}
