#include<bits/stdc++.h>
using namespace std;
bool a[5][20];
string c1="A23456789TJQK",c2="DCHS";
int n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        string s;
        cin>>s;
        int t1=0,t2=0;
        while(s[0]!=c2[t1]) t1++;
        while(s[1]!=c1[t2]) t2++;
        a[t1][t2]=1;
    }
    for(int i=0;i<4;++i)
        for(int j=0;j<13;++j)
            if(!a[i][j]) ++ans;
    printf("%d\n",ans);
    return 0;
}