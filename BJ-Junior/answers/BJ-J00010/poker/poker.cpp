#include<bits/stdc++.h>
using namespace std;
int n,a[160][160],cnt;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        a[s[0]][s[1]]=1;
    }
    for(int i=1;i<=150;i++){
        for(int j=1;j<=150;j++){
            cnt+=a[i][j];
        }
    }
    cout<<52-cnt;
    return 0;
}
