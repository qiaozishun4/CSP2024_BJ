#include <bits/stdc++.h>
using namespace std;
char a[5][60];
int main() {
    int n,s=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char p,q;
    for(int i=1;i<=n;i++){
        cin>>p>>q;
        a[1][i]=p;
        a[2][i]=q;
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[1][i]==a[1][j]&&a[2][i]==a[2][j]&&a[1][j]!='#')a[1][j]='#';
        }
    }for(int i=1;i<=n;i++){
        if(a[1][i]!='#')s++;
    }cout<<s;
    return 0;
}