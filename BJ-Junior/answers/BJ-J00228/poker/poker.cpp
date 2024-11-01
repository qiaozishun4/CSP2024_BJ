#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    char a[60][5];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i][0]==a[j][0]&&a[i][1]==a[j][1])n--;
        }
    }
    cout<<52-n;

    return 0;
}
