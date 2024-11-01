#include<bits/stdc++.h>
using namespace std;
int r[100005];
bool f[100005];
bool c[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    sort(r,r+n);
    int j=0;
    for(int i=0;i<n;i++){
        while(r[j]<=r[i]||c[j]==1) j++;
        if(j<n){
            f[i]=1;
            c[j]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(f[i]==0){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
