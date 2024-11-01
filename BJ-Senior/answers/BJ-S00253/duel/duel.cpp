#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int r[N],v[N];
int n,ans;

int main(){
    freopen("duel.out","w",stdout);
    freopen("duel.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    sort(r,r+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(r[j]>r[i]&&v[j]==0){
               v[j]=2;
               v[i]=3;
               j=n;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]!=3){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}