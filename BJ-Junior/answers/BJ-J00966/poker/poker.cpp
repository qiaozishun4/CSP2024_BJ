#include<bits/stdc++.h>
using namespace std;
long long n,g;
bool a[300][300];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(!a[s[0]][s[1]]){
            g++;
            a[s[0]][s[1]]=1;
        }
    }
    cout<<52-g;
    return 0;
}
