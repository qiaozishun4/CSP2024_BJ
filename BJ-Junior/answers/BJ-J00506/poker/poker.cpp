#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    char a[105],b[105];
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        for (int j=1;j<i;j++){
            if(a[j]==a[i] && b[j]==b[i]){
                cnt++;
                break;
            }
        }
    }
    cout<<52-n+cnt;
    return 0;
}