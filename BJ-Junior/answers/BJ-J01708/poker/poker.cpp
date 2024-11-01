#include<bits/stdc++.h>
using namespace std;
string s[55];
bool flag;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        flag=true;
        cin>>s[i];
        for(int j=1;j<i;j++){
            if(s[j]==s[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
