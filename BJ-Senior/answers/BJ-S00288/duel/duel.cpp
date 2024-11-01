#include <bits/stdc++.h>

using namespace std;
int b[100005]={},a;
long long ans=0,z=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        b[a]++;
    }
    for(int i=1;i<=100001;i++){
        if(z>=b[i]){
            ans=ans+b[i];
        }
        if(z<b[i]){
            ans=ans+z;
            z=b[i];
        }
    }
    cout<<n-ans;

    return 0;
}
