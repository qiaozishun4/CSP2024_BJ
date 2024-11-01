#include<bits/stdc++.h>
using namespace std;
string s[100];
bool fl[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //freopen("poker.in","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(fl[i]==false){
            for(int j=1;j<=n;j++){
                if(s[i]==s[j]){
                    cnt++;
                    fl[j]=true;
                }
            }
        cnt--;
        }
    }
    int ans=52-n;
    ans+=cnt;
    cout<<ans;
    return 0;
}
