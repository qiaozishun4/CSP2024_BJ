#include<bits/stdc++.h>
using namespace std;

long long n;
bool D[15],C[15],H[15],S[15];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //初始化
    for(int i=1;i<=13;i++)
    {
        D[i]=false;
        C[i]=false;
        H[i]=false;
        S[i]=false;
    }
    long long sum=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            if(s[1]=='A') D[1]=true;
            else if(s[1]=='2') D[2]=true;
            else if(s[1]=='3') D[3]=true;
            else if(s[1]=='4') D[4]=true;
            else if(s[1]=='5') D[5]=true;
            else if(s[1]=='6') D[6]=true;
            else if(s[1]=='7') D[7]=true;
            else if(s[1]=='8') D[8]=true;
            else if(s[1]=='9') D[9]=true;
            else if(s[1]=='T') D[10]=true;
            else if(s[1]=='J') D[11]=true;
            else if(s[1]=='Q') D[12]=true;
            else if(s[1]=='K') D[13]=true;

        }
        else if(s[0]=='C')
        {
            if(s[1]=='A') C[1]=true;
            else if(s[1]=='2') C[2]=true;
            else if(s[1]=='3') C[3]=true;
            else if(s[1]=='4') C[4]=true;
            else if(s[1]=='5') C[5]=true;
            else if(s[1]=='6') C[6]=true;
            else if(s[1]=='7') C[7]=true;
            else if(s[1]=='8') C[8]=true;
            else if(s[1]=='9') C[9]=true;
            else if(s[1]=='T') C[10]=true;
            else if(s[1]=='J') C[11]=true;
            else if(s[1]=='Q') C[12]=true;
            else if(s[1]=='K') C[13]=true;
        }
        if(s[0]=='H')
        {
            if(s[1]=='A') H[1]=true;
            else if(s[1]=='2') H[2]=true;
            else if(s[1]=='3') H[3]=true;
            else if(s[1]=='4') H[4]=true;
            else if(s[1]=='5') H[5]=true;
            else if(s[1]=='6') H[6]=true;
            else if(s[1]=='7') H[7]=true;
            else if(s[1]=='8') H[8]=true;
            else if(s[1]=='9') H[9]=true;
            else if(s[1]=='T') H[10]=true;
            else if(s[1]=='J') H[11]=true;
            else if(s[1]=='Q') H[12]=true;
            else if(s[1]=='K') H[13]=true;
        }
        else if(s[0]=='S')
        {
            if(s[1]=='A') S[1]=true;
            else if(s[1]=='2') S[2]=true;
            else if(s[1]=='3') S[3]=true;
            else if(s[1]=='4') S[4]=true;
            else if(s[1]=='5') S[5]=true;
            else if(s[1]=='6') S[6]=true;
            else if(s[1]=='7') S[7]=true;
            else if(s[1]=='8') S[8]=true;
            else if(s[1]=='9') S[9]=true;
            else if(s[1]=='T') S[10]=true;
            else if(s[1]=='J') S[11]=true;
            else if(s[1]=='Q') S[12]=true;
            else if(s[1]=='K') S[13]=true;
        }
    }
    for(int i=1;i<=13;i++)
    {
        if(D[i]==false) sum++;
        if(C[i]==false) sum++;
        if(H[i]==false) sum++;
        if(S[i]==false) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
