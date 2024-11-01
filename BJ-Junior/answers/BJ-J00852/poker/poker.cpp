#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        bool flag=0;
        for(int j=1;j<=i;j++){
            if(a[j]==s){
                flag=1;
            }
        }
        if(flag) continue;
        else a[i]=s;
    }
    for(int i=1;i<=52;i++){
        if(a[i]!=""){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
