#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[500]={},b[500]={},vis[5][14]={};
    int n,sum=52;
    a[int('C')]=1;
    a[int('D')]=2;
    a[int('H')]=3;
    a[int('S')]=4;
    b[int('A')]=1;
    b[int('T')]=10;
    b[int('J')]=11;
    b[int('Q')]=12;
    b[int('K')]=13;
    memset(vis,0,sizeof(vis));
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        if (int(s[1])>=int('1') && int(s[1])<=int('9'))
            vis[a[int(s[0])]][int(s[1])-int('1')+1]=1;
        else
            vis[a[int(s[0])]][b[int(s[1])]]=1;
    }
    for (int i=1;i<=4;i++)
        for (int j=1;j<=13;j++)
            if (vis[i][j]!=0)
                sum--;
    cout<<sum;
    return 0;
}