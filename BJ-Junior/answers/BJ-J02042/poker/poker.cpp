#include <bits/stdc++.h>
using namespace std;
bool a[105][105];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c,b;
        cin>>c>>b;
        if(a[c-'0'][b-'0']==0)s++;
        a[c-'0'][b-'0']=1;
    }
    cout<<52-s;
    return 0;
}
