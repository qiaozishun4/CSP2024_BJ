#include<iostream>
using namespace std;
int n,sum;
bool b[10][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int p,q;
        if(s[0]=='D') p=1;
        else if(s[0]=='C') p=2;
        else if(s[0]=='H') p=3;
        else p=4;
        if(s[1]=='A') q=1;
        else if(s[1]=='T') q=10;
        else if(s[1]=='J') q=11;
        else if(s[1]=='Q') q=12;
        else if(s[1]=='K') q=13;
        else q=s[1]-'0';
        if(b[p][q]==0)
        {
            b[p][q]=1;
            sum++;
        }
    }
    cout<<52-sum;
    return 0;
}
