#include<bits/stdc++.h>
using namespace std;
string s1;
int n,ans,d[13],c[13],h[13],s[13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1;
        if(s1=="DA"){
            d[0]=1;
        }else if(s1=="D2"){
            d[1]=1;
        }else if(s1=="D3"){
            d[2]=1;
        }else if(s1=="D4"){
            d[3]=1;
        }else if(s1=="D5"){
            d[4]=1;
        }else if(s1=="D6"){
            d[5]=1;
        }else if(s1=="D7"){
            d[6]=1;
        }else if(s1=="D8"){
            d[7]=1;
        }else if(s1=="D9"){
            d[8]=1;
        }else if(s1=="DT"){
            d[9]=1;
        }else if(s1=="DJ"){
            d[10]=1;
        }else if(s1=="DQ"){
            d[11]=1;
        }else if(s1=="DK"){
            d[12]=1;
        }else if(s1=="CA"){
            c[0]=1;
        }else if(s1=="C2"){
            c[1]=1;
        }else if(s1=="C3"){
            c[2]=1;
        }else if(s1=="C4"){
            c[3]=1;
        }else if(s1=="C5"){
            c[4]=1;
        }else if(s1=="C6"){
            c[5]=1;
        }else if(s1=="C7"){
            c[6]=1;
        }else if(s1=="C8"){
            c[7]=1;
        }else if(s1=="C9"){
            c[8]=1;
        }else if(s1=="CT"){
            c[9]=1;
        }else if(s1=="CJ"){
            c[10]=1;
        }else if(s1=="CQ"){
            c[11]=1;
        }else if(s1=="CK"){
            c[12]=1;
        }else if(s1=="HA"){
            h[0]=1;
        }else if(s1=="H2"){
            h[1]=1;
        }else if(s1=="H3"){
            h[2]=1;
        }else if(s1=="H4"){
            h[3]=1;
        }else if(s1=="H5"){
            h[4]=1;
        }else if(s1=="H6"){
            h[5]=1;
        }else if(s1=="H7"){
            h[6]=1;
        }else if(s1=="H8"){
            h[7]=1;
        }else if(s1=="H9"){
            h[8]=1;
        }else if(s1=="HT"){
            h[9]=1;
        }else if(s1=="HJ"){
            h[10]=1;
        }else if(s1=="HQ"){
            h[11]=1;
        }else if(s1=="HK"){
            h[12]=1;
        }else if(s1=="SA"){
            s[0]=1;
        }else if(s1=="S2"){
            s[1]=1;
        }else if(s1=="S3"){
            s[2]=1;
        }else if(s1=="S4"){
            s[3]=1;
        }else if(s1=="S5"){
            s[4]=1;
        }else if(s1=="S6"){
            s[5]=1;
        }else if(s1=="S7"){
            s[6]=1;
        }else if(s1=="S8"){
            s[7]=1;
        }else if(s1=="S9"){
            s[8]=1;
        }else if(s1=="ST"){
            s[9]=1;
        }else if(s1=="SJ"){
            s[10]=1;
        }else if(s1=="SQ"){
            s[11]=1;
        }else if(s1=="SK"){
            s[12]=1;
        }
    }
    for(int i=0;i<13;i++){
        if(d[i]==0) ans++;
        if(c[i]==0) ans++;
        if(h[i]==0) ans++;
        if(s[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
