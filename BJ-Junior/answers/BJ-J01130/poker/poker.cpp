#include<bits/stdc++.h>
using namespace std;
string s;
char ma[15]={0,'A','2','3', '4', '5', '6', '7', '8' ,'9' ,'T','J', 'Q', 'K'};
char mb[5]={0,'D','C','H','S'};
bool h[1005][1005];
int n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        h[s[0]*1][s[1]*1]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!h[mb[i]*1][ma[j]*1]){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}