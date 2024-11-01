#include <bits/stdc++.h>

using namespace std;
int n,ans=52;
string s[55];
bool f=true;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(s[i]==s[j])
                f=false;
        }
        if(f==true){
            ans--;
        }
        f=true;
    }
    cout <<ans;
    return 0;
}
