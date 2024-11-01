#include<bits/stdc++.h>
using namespace std;
int n,ans[55],sum;
string s;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>s;
    if(s=="DA"){
        ans[1]=1;
    }else if(s=="CA"){
        ans[2]=1;
    }else if(s=="HA"){
        ans[3]=1;
    }else if(s=="SA"){
        ans[4]=1;
    }else if(s=="D2"){
        ans[5]=1;
    }else if(s=="H2"){
        ans[6]=1;
    }else if(s=="C2"){
        ans[7]=1;
    }else if(s=="S2"){
        ans[8]=1;
    }else if(s=="D3"){
        ans[9]=1;
    }else if(s=="H3"){
        ans[10]=1;
    }else if(s=="C3"){
        ans[11]=1;
    }else if(s=="S3"){
        ans[12]=1;
    }else if(s=="D4"){
        ans[13]=1;
    }else if(s=="H4"){
        ans[14]=1;
    }else if(s=="C4"){
        ans[15]=1;
    }else if(s=="S4"){
        ans[16]=1;
    }else if(s=="D5"){
        ans[17]=1;
    }else if(s=="H5"){
        ans[18]=1;
    }else if(s=="C5"){
        ans[19]=1;
    }else if(s=="S5"){
        ans[20]=1;
    }else if(s=="D6"){
        ans[21]=1;
    }else if(s=="H6"){
        ans[22]=1;
    }else if(s=="C6"){
        ans[23]=1;
    }else if(s=="S6"){
        ans[24]=1;
    }else if(s=="D7"){
        ans[25]=1;
    }else if(s=="H7"){
        ans[26]=1;
    }else if(s=="C7"){
        ans[27]=1;
    }else if(s=="S7"){
        ans[28]=1;
    }else if(s=="D8"){
        ans[29]=1;
    }else if(s=="H8"){
        ans[30]=1;
    }else if(s=="C8"){
        ans[31]=1;
    }else if(s=="S8"){
        ans[32]=1;
    }else if(s=="D9"){
        ans[33]=1;
    }else if(s=="H9"){
        ans[34]=1;
    }else if(s=="C9"){
        ans[35]=1;
    }else if(s=="S9"){
        ans[36]=1;
    }else if(s=="DT"){
        ans[37]=1;
    }else if(s=="HT"){
        ans[38]=1;
    }else if(s=="CT"){
        ans[39]=1;
    }else if(s=="ST"){
        ans[40]=1;
    }else if(s=="DJ"){
        ans[41]=1;
    }else if(s=="HJ"){
        ans[42]=1;
    }else if(s=="CJ"){
        ans[43]=1;
    }else if(s=="SJ"){
        ans[44]=1;
    }else if(s=="DQ"){
        ans[45]=1;
    }else if(s=="HQ"){
        ans[46]=1;
    }else if(s=="CQ"){
        ans[47]=1;
    }else if(s=="SQ"){
        ans[48]=1;
    }else if(s=="DK"){
        ans[49]=1;
    }else if(s=="HK"){
        ans[50]=1;
    }else if(s=="CK"){
        ans[51]=1;
    }else if(s=="SK"){
        ans[52]=1;
    }
}
for(int i=1;i<=52;i++){
    if(ans[i]==0){
        sum++;
    }
}
cout<<sum;
return 0;
}
