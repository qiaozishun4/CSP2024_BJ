#include <bits/stdc++.h>
using namespace std;
int a[4][14],n,cnt;
int i,j;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int ii=0;ii<n;ii++)
    {
        string s;

        cin>>s;
        char c1=s[0];
        char c2=s[1];
        if(c1=='C')
        {
            i=0;
        }
        else if(c1=='D')
        {
            i=1;
        }
        else if(c1=='S')
        {
            i=2;
        }
        else{i=3;}
        if('0'<c2&&c2<='9'){j=c2-'0';}
        else if(c2=='T'){j=10;}
        else if(c2=='J'){j=11;}
        else if(c2=='Q'){j=12;}
        else if(c2=='A'){j=1;}
        else{j=13;}

        if(a[i][j]==0){cnt++;a[i][j]=1;}
    }
    if(cnt<0){cnt=0;}
    cout<<52-cnt;
    return 0;
}