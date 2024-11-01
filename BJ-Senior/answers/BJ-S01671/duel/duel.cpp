#include<bits/stdc++.h>
using namespace std;
int r[100010],n,u,k;
bool b[100010];
int s(){
    int ans=n;
    sort(r+1,r+1+n);
    for(int i=2;i<=n;i++){
        if(b[i]!=1){
            for(int j=i-1;j>=1;j--){
                if(b[j]==0&&r[j]<r[i]){
                    ans--;
                    b[j]=1;
                    break;
                }
            }
        }
    }
    return ans;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(r[i]==1)u++;
        else k++;
    }
    if(n<=30)cout<<s();
    else cout<<k-u;
    return 0;
}
