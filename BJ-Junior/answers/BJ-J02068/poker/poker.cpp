#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s]==0){
            cnt++;
            mp[s]=1;
        }
    }
    printf("%d",52-cnt);
    return 0;
}
