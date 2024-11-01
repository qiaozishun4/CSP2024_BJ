#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum=52;
    char hs[5]={'D','C','H','S'};
    char ds[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    int n;
    char s[101][101]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<=12;j++){
            for(int k=1;k<=n;k++){
                if(s[k][0]==hs[i]&&s[k][1]==ds[j]){
                    sum--;
                    break;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}