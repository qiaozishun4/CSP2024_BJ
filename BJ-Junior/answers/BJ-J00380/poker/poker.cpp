#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
int n;
map<string,int>mp;
char c1[15]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
string c2[5]={"0","D","C","H","S"};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            string s=c2[i];
            s+=c1[j];
            if(!mp.count(s))ans++;
        }
    }
    cout<<ans;
    return 0;
}
