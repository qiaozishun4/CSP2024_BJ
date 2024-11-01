#include<bits/stdc++.h>
using namespace std;

int n,cnt,ans;
string tmp;
string a[100];

void solve(){
    //for(int o=0;o<=52;o++)cout<<a[o]<<endl;
    ans = 52-n+cnt;
    cout<<ans;
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>tmp;
        for(int j=0;j<=52;j++){
            if(a[j]==tmp) cnt++;
        }
        a[i] = tmp;
    }
    solve();
    return 0;
}
