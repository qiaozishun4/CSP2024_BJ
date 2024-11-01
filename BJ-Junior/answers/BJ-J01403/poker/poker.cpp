#include<bits/stdc++.h>
using namespace std;
int n;
string s[55];
int f,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        f=1;
        for(int j=1;j<i;j++){
            if(s[i]==s[j]){
                f=0;
                break;
            }
        }
        ans+=f;
    }
    cout<<52-ans;
    return 0;
}
