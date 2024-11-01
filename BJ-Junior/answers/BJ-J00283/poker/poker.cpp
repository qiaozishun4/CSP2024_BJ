#include<bits/stdc++.h>
using namespace std;
bool flag[53];
string x;
int n,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x=="DA") flag[1]=1;
        else if(x=="D2") flag[2]=1;
        else if(x=="D3") flag[3]=1;
        else if(x=="D4") flag[4]=1;
        else if(x=="D5") flag[5]=1;
        else if(x=="D6") flag[6]=1;
        else if(x=="D7") flag[7]=1;
        else if(x=="D8") flag[8]=1;
        else if(x=="D9") flag[9]=1;
        else if(x=="DT") flag[10]=1;
        else if(x=="DJ") flag[11]=1;
        else if(x=="DQ") flag[12]=1;
        else if(x=="DK") flag[13]=1;
        else if(x=="CA") flag[14]=1;
        else if(x=="C2") flag[15]=1;
        else if(x=="C3") flag[16]=1;
        else if(x=="C4") flag[17]=1;
        else if(x=="C5") flag[18]=1;
        else if(x=="C6") flag[19]=1;
        else if(x=="C7") flag[20]=1;
        else if(x=="C8") flag[21]=1;
        else if(x=="C9") flag[22]=1;
        else if(x=="CT") flag[23]=1;
        else if(x=="CJ") flag[24]=1;
        else if(x=="CQ") flag[25]=1;
        else if(x=="CK") flag[26]=1;
        else if(x=="HA") flag[27]=1;
        else if(x=="H2") flag[28]=1;
        else if(x=="H3") flag[29]=1;
        else if(x=="H4") flag[30]=1;
        else if(x=="H5") flag[31]=1;
        else if(x=="H6") flag[32]=1;
        else if(x=="H7") flag[33]=1;
        else if(x=="H8") flag[34]=1;
        else if(x=="H9") flag[35]=1;
        else if(x=="HT") flag[36]=1;
        else if(x=="HJ") flag[37]=1;
        else if(x=="HQ") flag[38]=1;
        else if(x=="HK") flag[39]=1;
        else if(x=="SA") flag[40]=1;
        else if(x=="S2") flag[41]=1;
        else if(x=="S3") flag[42]=1;
        else if(x=="S4") flag[43]=1;
        else if(x=="S5") flag[44]=1;
        else if(x=="S6") flag[45]=1;
        else if(x=="S7") flag[46]=1;
        else if(x=="S8") flag[47]=1;
        else if(x=="S9") flag[48]=1;
        else if(x=="ST") flag[49]=1;
        else if(x=="SJ") flag[50]=1;
        else if(x=="SQ") flag[51]=1;
        else flag[52]=1;
    }
    for(int i=1; i<=52; i++) if(!flag[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
