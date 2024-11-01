#include<bits/stdc++.h>
using namespace std;
string s[55];
int n,cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        cnt++;
        for(int j=i-1;j>0;j--){
            if(s[i][0]==s[j][0]&&s[i][1]==s[j][1]){
                cnt--;
            }
        }
    }
    cout<<52-cnt;
}