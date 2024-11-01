#include<bits/stdc++.h>
using namespace std;
int r[100005];
bool defeat[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        defeat[i]=true;
    }
    sort(r+1,r+n+1);
    int ans=n;
    for(int i=2;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(r[j]<r[i]&&defeat[j]){
                ans--;
                defeat[j]=false;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
