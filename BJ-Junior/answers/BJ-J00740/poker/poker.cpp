#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    string s[60];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bool flag=0;
        for(int j=1;j<i;j++){
            if(s[i]==s[j]){
                flag=1;
                break;
            }
        }
        if(flag)continue;
        else ans++;
    }
    cout<<52-ans;
    return 0;
}
