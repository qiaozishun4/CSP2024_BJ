#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    string s[60];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bool flag=0;
        for(int j=1;j<i;j++){
            if(s[j]==s[i]) flag=1;
        }
        if(flag==0) cnt++;
    }
    cout<<52-cnt;
    return 0;
}