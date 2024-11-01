#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt[10][20],ans;
int check2(char x){
    if(x>='2'&&x<='9') return x-'0';
    else if(x=='A') return 1;
    else if(x=='T') return 10;
    else if(x=='J') return 11;
    else if(x=='Q') return 12;
    else if(x=='K') return 13;
    else return 0;
}
int check1(char x){
    if(x=='D') return 1;
    else if(x=='C') return 2;
    else if(x=='H') return 3;
    else if(x=='S') return 4;
    else return 0;
}
vector<pair<char,char>> vt;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        vt.push_back(make_pair(a,b));
    }
    for(auto i:vt){
        //cout<<i.first<<" "<<i.second<<endl;
        cnt[check1(i.first)][check2(i.second)]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(cnt[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
