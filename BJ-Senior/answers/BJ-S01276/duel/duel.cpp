#include<bits/stdc++.h>
using namespace std;
int m[1000100],b[1000100],num[1000100];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    int Mmax=0;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        b[m[i]]++;
        Mmax=max(m[i],Mmax);
    }
    int pp=0;
    for(int i=1;i<=Mmax;i++){
        if(b[i]!=0){
            num[++pp]=b[i];
        }
    }
    for(int i=1;i<pp;i++){
        if(num[i+1]>=num[i]){
            num[i]=0;
        }else if(num[i+1]<num[i]){
            num[i+1]+=(num[i]-num[i+1]);
            num[i]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=pp;i++){
        ans+=num[i];
    }
    cout<<ans;
    return 0;
}

