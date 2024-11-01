#include<bits/stdc++.h>
using namespace std;
map<char,int>ci={{'T',10},{'J',11},{'Q',12},{'K',13},{'A',1},{'D',1},{'C',2},{'H',3},{'S',4}};
bool ok[10][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int i,j,x,y,n,ans=0;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        x=ci[str[0]];
        if(str[1]>='0'&&str[1]<='9')y=str[1]-'0';
        else y=ci[str[1]];
        ok[x][y]=1;
    }
    for(i=1;i<=4;i++)
        for(j=1;j<=13;j++)
            if(!ok[i][j])
                ans++;
    cout<<ans;
    return 0;
}
