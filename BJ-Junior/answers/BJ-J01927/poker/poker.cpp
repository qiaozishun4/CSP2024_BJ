#include<bits/stdc++.h>
using namespace std;

int n;
string s[59];

int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    int ans=52;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        bool flag=true;
        if(i==1){
            ans--;
            continue;
        }
        for(int j=1;j<i;++j){
            if(s[j]==s[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
