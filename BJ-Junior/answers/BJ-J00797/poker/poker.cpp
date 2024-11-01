#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char a[52];
    for(int v=1;v<=n;v++){
           cin>>a[v];
    }
    int b=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]){
                b++;
            }
    }
    }
    cout<<52-n+b/2;

    return 0;
}
