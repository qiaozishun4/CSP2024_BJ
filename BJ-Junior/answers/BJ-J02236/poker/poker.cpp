#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c,d,ans=0;
    char a,a1;
    int b[30][50]={};
    cin>>n;
    while(n--){
        cin>>a>>a1;
        c=int(a)-65;
        if(a1>='A'&&a1<='Z') d=int(a1)-65;
        else d=int(a1)-48+30;
        b[c][d]++;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<50;j++){
            if(b[i][j]){
                ans++;
            }
        }
    }
    cout<<52-ans;
    return 0;
}