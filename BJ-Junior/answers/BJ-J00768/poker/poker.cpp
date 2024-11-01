#include <bits/stdc++.h>
using namespace std;
int d[14];
int c[14];
int h[14];
int s[14];
string y,x;
int n,xh,ans=0;
int shuzi(string x){
    if(x=="A")return 1;
    else if(x=="2")return 2;
    else if(x=="3")return 3;
    else if(x=="4")return 4;
    else if(x=="5")return 5;
    else if(x=="6")return 6;
    else if(x=="7")return 7;
    else if(x=="8")return 8;
    else if(x=="9")return 9;
    else if(x=="T")return 10;
    else if(x=="J")return 11;
    else if(x=="Q")return 12;
    else if(x=="K")return 13;
    return 0;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        y=x[0];
        x=x[1];
        xh=shuzi(x);
        if(y=="D")d[xh]=1;
        else if(y=="C")c[xh]=1;
        else if(y=="H")h[xh]=1;
        else if(y=="S")s[xh]=1;
    }
    for(int i=1;i<=14;i++)if(d[i]==1)ans++;
    for(int i=1;i<=14;i++)if(c[i]==1)ans++;
    for(int i=1;i<=14;i++)if(h[i]==1)ans++;
    for(int i=1;i<=14;i++)if(s[i]==1)ans++;
    cout<<52-ans<<endl;
    return 0;
}