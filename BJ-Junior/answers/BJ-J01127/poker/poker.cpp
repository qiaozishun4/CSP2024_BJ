#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s[102];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        int o=1;
        for(int j=1;j<i;j++){
            if(s[j]==s[i]){
                o=0;
                break;
            }
        }
        cnt+=o;
    }
    cout<<52-cnt;
    return 0;
}
