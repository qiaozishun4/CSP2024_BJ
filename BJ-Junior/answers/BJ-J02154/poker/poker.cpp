#include<bits/stdc++.h>
using namespace std;
bool m[101][101];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,p=52;
    cin>>n;
    char a,b;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        if (!m[a][b])p--;
        m[a][b]=1;
    }
    cout<<p<<endl;
    return 0;
}
