#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool poker[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            char c,d;
            cin>>c>>d;
            int a,b;
            if(c=='S')a=1;
            if(c=='H')a=2;
            if(c=='D')a=3;
            if(c=='C')a=4;
            if(d=='A')b=1;
            else if(d=='T')b=10;
            else if(d=='J')b=11;
            else if(d=='Q')b=12;
            else if(d=='K')b=13;
            else b=d-'0';
            poker[a][b]=true;
        }
    for(int i=1;i<=4;i++)for(int j=1;j<=13;j++)if(poker[i][j]==false)ans++;
    cout<<ans;
    return 0;
}