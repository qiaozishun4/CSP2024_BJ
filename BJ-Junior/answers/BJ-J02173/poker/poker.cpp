#include<bits/stdc++.h>
using namespace std;
string s[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    int cnt=0;
    sort(s+1,s+n+1);
    for(int i=1;i<=n;){
        if(s[i]!=s[i+1]){
            cnt++;
            i++;
        }else{
            while(s[i]==s[i+1])i++;
        }
    }
    cout<<52-cnt;
    return 0;
}
