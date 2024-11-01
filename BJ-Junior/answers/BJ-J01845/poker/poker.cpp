#include<bits/stdc++.h>
using namespace std;
char a[60][5];
int n,ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
        ans--;
        for(int j=1;j<=i-1;j++){
            if(a[j][1]==a[i][1] && a[j][2]==a[i][2]){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
