#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    int ans=0;
    int len=2;
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(;len<=n;len++){
            if(r[i]<r[len]){
                len++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans=n-i+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}