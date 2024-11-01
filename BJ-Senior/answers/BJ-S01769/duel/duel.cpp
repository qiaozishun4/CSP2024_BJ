#include<bits/stdc++.h>
using namespace std;
int a[100005],h[100005];
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int k = a[1],x=1,y=0;
    h[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==k){
            h[x]++;
        }else{
            k = a[i];
            x++;
            h[x]++;
        }
    }
    for(int i=1;i<=x;i++){
        if(h[i]-h[i+1]>0){
            ans=ans + h[i]-h[i+1];
        }else if(h[i]-h[i+1]<0){
            if(ans-h[i+1]+h[i]>=0){
                ans = ans-h[i+1]+h[i];
            }else{
                ans = 0;
            }
        }
    }
    cout<<ans;
    return 0;
}
