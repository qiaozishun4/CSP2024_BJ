#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c;
bool a[500][500];
char c1,c2;
string x="DCHS",y="A23456789TJQK";
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>c1>>c2;
        a[c1][c2]=1;
    }
    for(auto i:x)
        for(auto j:y)
            if(!a[i][j])
            c++;
    cout<<c;
    return 0;
}
