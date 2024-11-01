#include<bits/stdc++.h>
using namespace std;
bool pl[13][4];
char pok[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int l=0;
        if(s[0]=='D')l=0;
        if(s[0]=='S')l=1;
        if(s[0]=='C')l=2;
        if(s[0]=='H')l=3;
        for(int j=0;j<13;j++){
            if(pok[j]==s[1]){
                if(!pl[j][l])ans++;
                pl[j][l]=1;
            }
        }
    }
    cout<<52-ans;
    return 0;
}
