#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r","stdin");
    freopen("duel.out","w","stdout");
    int n,a[100005],v[100005];
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&v[j]==1&&a[j]!=-1&&a[i]!=-1){
                ans--;
                a[i]=-1;
                v[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}