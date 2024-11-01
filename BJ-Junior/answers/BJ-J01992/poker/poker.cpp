#include<bits/stdc++.h>
using namespace std;
int n,ans;
char hua[2];
bool s[30][50];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans=52;
    for(int i=1;i<=n;i++){
        cin>>hua;
        if(s[hua[0]-'A'][hua[1]-'1']==0)s[hua[0]-'A'][hua[1]-'1']=1,ans--;
    }
    cout<<ans<<endl;
    return 0;
}
