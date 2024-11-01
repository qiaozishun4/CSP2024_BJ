#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string fi={'D','C','H','S'};
    string se={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    int n;
    cin>>n;
    int a[5][14]={0};
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        int p,q;
        for(int j=0;j<4;j++){
            if(s[0]==fi[j]){
                p=j+1;
            }
        }
        for(int j=0;j<13;j++){
            if(s[1]==se[j]){
                q=j+1;
            }
        }
        a[p][q]++;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0)  cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}