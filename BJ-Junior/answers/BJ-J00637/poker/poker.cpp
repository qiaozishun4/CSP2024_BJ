#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[14][5]={0};
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        int m;
        cin>>x>>y;
        if(y<='9'&&y>='0')m=y-'0';
        if(y=='A')m=1;
        if(y=='T')m=10;
        if(y=='J')m=11;
        if(y=='Q')m=12;
        if(y=='K')m=13;
        if(x=='D')a[m][1]++;
        if(x=='C')a[m][2]++;
        if(x=='H')a[m][3]++;
        if(x=='S')a[m][4]++;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(a[i][j]==0)ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
