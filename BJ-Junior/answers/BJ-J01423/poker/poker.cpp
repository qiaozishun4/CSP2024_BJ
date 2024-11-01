#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    char h,s;
}a[70];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].h;
        cin>>a[i].s;
    }
    int ans=52;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=i-1;j++){
            if(a[i].h==a[j].h && a[i].s==a[j].s){
                sum+=1;
            }
        }
        if(sum==0){
            ans-=1;
        }
    }
    cout<<ans;
    return 0;
}

