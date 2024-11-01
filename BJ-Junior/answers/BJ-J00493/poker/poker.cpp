#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,num;
char a[10005][10005];
int main(){
    cin>>n;
    freopen(poker,"r",stdin);
    freopen(poker,"w",stdout);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][1]==a[j][1]){
                if(a[i][2]==a[j][2]){
                    num++;
                }
            }
        }
    }
    cout<<52-n+num;
    return 0;
}