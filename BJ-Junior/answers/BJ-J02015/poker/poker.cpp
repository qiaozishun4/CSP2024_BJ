#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
char c[maxn],ch[maxn];
int n,cnt;
bool f[310][310];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>ch[i];
        f[c[i]][ch[i]]=1;
    }
    for(int i=1;i<=300;i++){
        for(int j=1;j<=300;j++){
            if(f[i][j]) cnt++;
        }
    }
    cout<<52-cnt<<'\n';
    return 0;
}
