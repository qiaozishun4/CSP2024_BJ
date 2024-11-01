#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
 int n;
 cin>>n;
 int r[100005];
 int ans=0;
 int sum=0;
 for(int i=1;i<=n;i++){
    cin>>r[i];

 }
 sort(r,r+n+1);
 for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(r[i]<r[j]){
            if(a[j]==0){
                i++;
                a[j]=1;
                ans++;

            }
        }
    }
 }
 cout<<n-ans;
}
