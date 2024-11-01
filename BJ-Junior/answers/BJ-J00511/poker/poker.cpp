#include <bits/stdc++.h>
using namespace std;
int n,sum;
bool a[10][20];
char s;
char m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<20;i++)
        for(int j=0;j<10;j++)
            a[i][j]=0;

    for(int i=0;i<n;i++){
        int y,l;
        cin>>s;
        cin>>m;
        if(s=='D') y=1;
        if(s=='C') y=2;
        if(s=='H') y=3;
        if(s=='S') y=4;
        if(m=='A') l=1;
        if(m=='2') l=2;
        if(m=='3') l=3;
        if(m=='4') l=4;
        if(m=='5') l=5;
        if(m=='6') l=6;
        if(m=='7') l=7;
        if(m=='8') l=8;
        if(m=='9') l=9;
        if(m=='T') l=10;
        if(m=='J') l=11;
        if(m=='Q') l=12;
        if(m=='K') l=13;
        a[y][l]=1;
        }
    for(int i=1;i<5;i++){
        for(int j=1;j<14;j++){
            if(a[i][j]) sum+=1;
        }
    }
    cout<<52-sum;
    return 0;
}
