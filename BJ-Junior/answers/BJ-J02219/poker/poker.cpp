#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N=1e5+10;
int INF=0x3f3f3f3f;
int n;
map<string,int>m;
string s;
int cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(m.find(s)==m.end()){
            cnt++;
        }
        m[s]++;
    }
    cout<<(52-cnt);
    return 0;
}
