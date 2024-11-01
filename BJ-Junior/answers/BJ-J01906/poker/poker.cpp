#include<bits/stdc++.h>
using namespace std;
int n;
bool a[5][15];
char b[200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i='2';i<='9';i++) b[i]=i-'0';
    b['A']=1;
    b['T']=10;
    b['J']=11;
    b['Q']=12;
    b['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;
        cin>>x;
        if(x[0]=='D') a[1][b[x[1]]]=1;
        else if(x[0]=='C') a[2][b[x[1]]]=1;
        else if(x[0]=='H') a[3][b[x[1]]]=1;
        else a[4][b[x[1]]]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}