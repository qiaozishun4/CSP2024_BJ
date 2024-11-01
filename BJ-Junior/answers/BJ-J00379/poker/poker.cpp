#include <bits/stdc++.h>
using namespace std;
int n,ans=52,flag;
string s[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        flag=1;
        for(int j=1;j<i;j++){
            if(s[i]==s[j]){
                flag=0;
            }
        }
        ans-=flag;
    }
    cout<<ans;
    return 0;
}