#include<bits/stdc++.h>
using namespace std;
bool a[26][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
   // freopen("poker.in","w",stdout);
    int n,cnt=52;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(a[s[0]-'A'][int(s[1])]==0){
            cnt--;
            a[s[0]-'A'][int(s[1])]=1;
        }
    }
    cout<<cnt;
    return 0;
}
