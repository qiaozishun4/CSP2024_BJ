#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int c=0;
    int a[100010]={0};
    for(int i=0;i<n;i++){
        int b=0;
        cin>>b;
         a[b]++;
        if(b>=c){
            c=b;
        }

    }
    int ans=0;
    for(int i=0;i<=c;i++){
        if(a[i]>=ans){
            ans=a[i];
        }
    }
    cout<<ans;
    return 0;
}
