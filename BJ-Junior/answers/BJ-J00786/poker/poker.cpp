#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a[4][13]={0},ans=52;
    char c[4]={'H','D','S','C'};
    char num[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<4;j++){
            if(s[0]==c[j]){
                int c=j;
                for(int k=0;k<13;k++){
                    if(s[1]==num[k]){
                        a[c][k]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==1){
                ans--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
