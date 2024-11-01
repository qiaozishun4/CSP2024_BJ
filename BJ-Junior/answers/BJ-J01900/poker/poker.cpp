#include<bits/stdc++.h>
using namespace std;
int n,sum,f[501][501];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(f[s[0]-'0'][s[1]-'0']==0){
            f[s[0]-'0'][s[1]-'0']=1;
            sum++;
        }
    }cout<<52-sum;
    return 0;
}
