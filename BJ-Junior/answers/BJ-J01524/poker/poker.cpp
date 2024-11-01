#include<bits/stdc++.h>
using namespace std;
int n,ans=52,i,j;
string s;
bool a[14][5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        if(s[1]=='A')   i=1;
        if(s[1]=='2')   i=2;
        if(s[1]=='3')   i=3;
        if(s[1]=='4')   i=4;
        if(s[1]=='5')   i=5;
        if(s[1]=='6')   i=6;
        if(s[1]=='7')   i=7;
        if(s[1]=='8')   i=8;
        if(s[1]=='9')   i=9;
        if(s[1]=='T')   i=10;
        if(s[1]=='J')   i=11;
        if(s[1]=='Q')   i=12;
        if(s[1]=='K')   i=13;
        if(s[0]=='D')   j=1;
        if(s[0]=='C')   j=2;
        if(s[0]=='H')   j=3;
        if(s[0]=='S')   j=4;
        a[i][j]=1;
    }
    for(i=1;i<=13;i++)
        for(int j=1;j<=4;j++)
            if(a[i][j]==1)  ans--;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}