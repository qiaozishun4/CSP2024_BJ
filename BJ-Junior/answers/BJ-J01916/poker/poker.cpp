#include <bits/stdc++.h>
using namespace std;
int n;
char a,b;
bool sum[105];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'&&b=='A') sum[1]=1;
        if(a=='D'&&b=='2') sum[2]=1;
        if(a=='D'&&b=='3') sum[3]=1;
        if(a=='D'&&b=='4') sum[4]=1;
        if(a=='D'&&b=='5') sum[5]=1;
        if(a=='D'&&b=='6') sum[6]=1;
        if(a=='D'&&b=='7') sum[7]=1;
        if(a=='D'&&b=='8') sum[8]=1;
        if(a=='D'&&b=='9') sum[9]=1;
        if(a=='D'&&b=='T') sum[10]=1;
        if(a=='D'&&b=='J') sum[11]=1;
        if(a=='D'&&b=='Q') sum[12]=1;
        if(a=='D'&&b=='K') sum[13]=1;

        if(a=='C'&&b=='A') sum[14]=1;
        if(a=='C'&&b=='2') sum[15]=1;
        if(a=='C'&&b=='3') sum[16]=1;
        if(a=='C'&&b=='4') sum[17]=1;
        if(a=='C'&&b=='5') sum[18]=1;
        if(a=='C'&&b=='6') sum[19]=1;
        if(a=='C'&&b=='7') sum[20]=1;
        if(a=='C'&&b=='8') sum[21]=1;
        if(a=='C'&&b=='9') sum[22]=1;
        if(a=='C'&&b=='T') sum[23]=1;
        if(a=='C'&&b=='J') sum[24]=1;
        if(a=='C'&&b=='Q') sum[25]=1;
        if(a=='C'&&b=='K') sum[26]=1;

        if(a=='H'&&b=='A') sum[27]=1;
        if(a=='H'&&b=='2') sum[28]=1;
        if(a=='H'&&b=='3') sum[29]=1;
        if(a=='H'&&b=='4') sum[30]=1;
        if(a=='H'&&b=='5') sum[31]=1;
        if(a=='H'&&b=='6') sum[32]=1;
        if(a=='H'&&b=='7') sum[33]=1;
        if(a=='H'&&b=='8') sum[34]=1;
        if(a=='H'&&b=='9') sum[35]=1;
        if(a=='H'&&b=='T') sum[36]=1;
        if(a=='H'&&b=='J') sum[37]=1;
        if(a=='H'&&b=='Q') sum[38]=1;
        if(a=='H'&&b=='K') sum[39]=1;

        if(a=='S'&&b=='A') sum[40]=1;
        if(a=='S'&&b=='2') sum[41]=1;
        if(a=='S'&&b=='3') sum[42]=1;
        if(a=='S'&&b=='4') sum[43]=1;
        if(a=='S'&&b=='5') sum[44]=1;
        if(a=='S'&&b=='6') sum[45]=1;
        if(a=='S'&&b=='7') sum[46]=1;
        if(a=='S'&&b=='8') sum[47]=1;
        if(a=='S'&&b=='9') sum[48]=1;
        if(a=='S'&&b=='T') sum[49]=1;
        if(a=='S'&&b=='J') sum[50]=1;
        if(a=='S'&&b=='Q') sum[51]=1;
        if(a=='S'&&b=='K') sum[52]=1;
    }
        int ans=0;
        for(int i=1;i<=52;i++){
            //cout<<sum[i]<<" ";
            if(sum[i]==0) ans++;
        }
        cout<<ans;
        return 0;
}
