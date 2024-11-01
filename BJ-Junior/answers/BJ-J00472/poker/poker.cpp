#include<iostream>
#include<map>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,bool>mp;
    int n;
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(!mp[a])ans--;
        mp[a]=true;
    }
    cout<<ans;
    return 0;
}
