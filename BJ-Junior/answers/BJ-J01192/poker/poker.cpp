#include<bits/stdc++.h>
using namespace std;
const int N=60;
string a[N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        --ans;
        string s;
        cin>>s;
        int c=0;
        for(int j=1;j<=cnt;++j){
            if(a[j]==s){
                c=1;
                ++ans;
                break;
            }
        }
        if(c==0)a[++cnt]=s;
    }
    cout<<ans<<'\n';
    return 0;
}