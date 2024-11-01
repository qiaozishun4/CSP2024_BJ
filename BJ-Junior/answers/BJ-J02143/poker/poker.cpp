#include<bits/stdc++.h>
using namespace std;
int n,h[205],ans,num[205];
string s;
bool f[15][25];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    h['D']=1,h['C']=2,h['S']=3,h['H']=4;
    num['A']=1,num['T']=10,num['J']=11,num['Q']=12,num['K']=13;
    cin>>n;
    for(int i=2;i<=9;i++){
        num[i+'0']=i;
    }
    while(n--){
        cin>>s;
        f[h[s[0]]][num[s[1]]]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!f[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
}
