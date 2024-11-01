#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
string st,a,b;
map <string,int> m;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st;
        m[st]=1;
    }
    for(int i=1;i<=4;i++){
        if(i==1)b="D";
        else if(i==2)b="C";
        else if(i==3)b="H";
        else b="S";
        for(int j=1;j<=13;j++){
            if(j==1)a="A";
            else if(j==2)a="2";
            else if(j==3)a="3";
            else if(j==4)a="4";
            else if(j==5)a="5";
            else if(j==6)a="6";
            else if(j==7)a="7";
            else if(j==8)a="8";
            else if(j==9)a="9";
            else if(j==10)a="T";
            else if(j==11)a="J";
            else if(j==12)a="Q";
            else a="K";
            if(m[b+a]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
