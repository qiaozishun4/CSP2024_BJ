#include<bits/stdc++.h>
using namespace std;
int n,a[100006],ans,maxx,minn,max2;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sort(a+1,a+n+1);
        maxx=a[n];
        minn=a[1];
        if(a[i]<maxx){
            ans++;
        }else{
            ans=1;
        }
    }
    //cout<<maxx<<" "<<minn<<" ";
    cout<<ans;
return 0;
}
