#include <bits/stdc++.h>
#include <string>
using namespace std;
int n,num,k;
int main(){
    string e[54],g[54];
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>e[i];
    }
    for (int i=0;i<n;i++){
        k=0;
        for (int j=0;j<i;j++){
            if (g[j]==e[i]){
                k=1;
            }
        }
        if (k==0){
            g[i]=e[i];
            num++;
        }
    }
    cout<<53-num;
    return 0;
}


