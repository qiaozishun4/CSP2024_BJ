#include<bits/stdc++.h>
using namespace std;
const int ma=20;
int d[ma],c[ma],h[ma],s[ma];
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        char a=k[0],b=k[1];
        if(a=='D')
        {
            switch(b)
            {
            case 'A':d[1]=1;break;
            case '2':d[2]=1;break;
            case '3':d[3]=1;break;
            case '4':d[4]=1;break;
            case '5':d[5]=1;break;
            case '6':d[6]=1;break;
            case '7':d[7]=1;break;
            case '8':d[8]=1;break;
            case '9':d[9]=1;break;
            case 'T':d[10]=1;break;
            case 'J':d[11]=1;break;
            case 'Q':d[12]=1;break;
            case 'K':d[13]=1;break;
            }
        }
        if(a=='C'){
            switch(b)
            {
            case 'A':c[1]=1;break;
            case '2':c[2]=1;break;
            case '3':c[3]=1;break;
            case '4':c[4]=1;break;
            case '5':c[5]=1;break;
            case '6':c[6]=1;break;
            case '7':c[7]=1;break;
            case '8':c[8]=1;break;
            case '9':c[9]=1;break;
            case 'T':c[10]=1;break;
            case 'J':c[11]=1;break;
            case 'Q':c[12]=1;break;
            case 'K':c[13]=1;break;
            }
        }
        if(a=='H'){
            switch(b)
            {
            case 'A':h[1]=1;break;
            case '2':h[2]=1;break;
            case '3':h[3]=1;break;
            case '4':h[4]=1;break;
            case '5':h[5]=1;break;
            case '6':h[6]=1;break;
            case '7':h[7]=1;break;
            case '8':h[8]=1;break;
            case '9':h[9]=1;break;
            case 'T':h[10]=1;break;
            case 'J':h[11]=1;break;
            case 'Q':h[12]=1;break;
            case 'K':h[13]=1;break;
            }
        }
        if(a=='S'){
            switch(b)
            {
            case 'A':s[1]=1;break;
            case '2':s[2]=1;break;
            case '3':s[3]=1;break;
            case '4':s[4]=1;break;
            case '5':s[5]=1;break;
            case '6':s[6]=1;break;
            case '7':s[7]=1;break;
            case '8':s[8]=1;break;
            case '9':s[9]=1;break;
            case 'T':s[10]=1;break;
            case 'J':s[11]=1;break;
            case 'Q':s[12]=1;break;
            case 'K':s[13]=1;break;
            }
        }
    }
    int ss=0;
    for(int i=1;i<=13;i++){
        if(d[i]==0)
                ss++;
        if(c[i]==0)
                ss++;
        if(h[i]==0)
                ss++;
        if(s[i]==0)
                ss++;
    }
    cout<<ss;
    return 0;
}