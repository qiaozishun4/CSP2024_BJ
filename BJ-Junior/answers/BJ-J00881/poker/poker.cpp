#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    ans=52-n;
    vector<char> s[2];
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        bool num=true;
        for(int j=0;j<s[0].size();j++){
            if(s[0][j]==a&&s[1][j]==b){
                num=false;
                break;
            }
        }
        if(num==true){
            s[0].push_back(a);
            s[1].push_back(b);
        }else {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
