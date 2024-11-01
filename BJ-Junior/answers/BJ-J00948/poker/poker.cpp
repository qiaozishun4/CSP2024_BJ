#include<bits/stdc++.h>
using namespace std;
int n,ans=52,l=n;
char a[53];
int main(){
    freopen("r","poker.in",stdin);
    freopen("w","poker.out",stdout);
    cin>>n;
    for(int i=1;i<=n*2;i++){
        cin>>a[i];
    }

                 for(int i=1;i<=n*2;i++){
        if(a[i]-a[i+1]==a[i+2]-a[i+3]){
            ans+=n-1;
        break;
        }
            }

    cout <<ans-n;
    return 0;
}
