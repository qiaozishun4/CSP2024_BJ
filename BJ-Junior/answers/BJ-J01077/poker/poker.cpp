#include <bits/stdc++.h>
using namespace std;
char a[58],b[58];
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++){
        bool k=false;
        cin>>a[i]>>b[i];
        for(int j=1;j<i;j++){
            if(a[j]==a[i] and k==false){
                if(b[i]==b[j]){
                    k=true;
                }
            }
        }
        if(k==false) ans--;
    }
    cout<<ans;
    return 0;
}