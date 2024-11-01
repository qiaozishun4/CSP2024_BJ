#include<bits/stdc++.h>
using namespace std;
int n,w=52,t;
char a[3][53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        t=0;
        cin>>a[1][i]>>a[2][i];
        for(int j=1;j<i;j++){
            if(a[1][i]==a[1][j]&&a[2][i]==a[2][j])
            t=1;
        }
        if(t==0)
        w--;
    }
    cout<<w;
    return 0;
}
