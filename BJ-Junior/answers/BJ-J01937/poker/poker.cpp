#include <bits/stdc++.h>
using namespace std;
int n,ans,a[110],d,tmp;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    ans=52;
    for(int i=1; i<=n; i++){
        cin>>s;
        if(s[0]=='D') d=0;
        else if(s[0]=='C') d=13;
        else if(s[0]=='H') d=26;
        else if(s[0]=='S') d=39;
        if(s[1]>='0' && s[1]<='9') tmp=s[1]-'0'-1;
        else{
            if(s[1]=='A') tmp=0;
            else if(s[1]=='T') tmp=9;
            else if(s[1]=='J') tmp=10;
            else if(s[1]=='Q') tmp=11;
            else if(s[1]=='K') tmp=12;
        }
        if(a[tmp+d]!=1){
            ans--;
            a[tmp+d]=1;
        }
        //printf("%s\n%d\n",s.c_str(),ans);
    }
    printf("%d",ans);
    return 0;
}
