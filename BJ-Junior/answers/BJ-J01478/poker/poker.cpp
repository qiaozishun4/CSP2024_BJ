#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n,ans,a[1000][1000];
int color[]={'D','C','H','S'},num[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    //color D,C,H,S
    //num A,2,3,4,5,6,7,8,9,T,J,Q,K
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[s[0]][s[1]]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[color[i]][num[j]]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}