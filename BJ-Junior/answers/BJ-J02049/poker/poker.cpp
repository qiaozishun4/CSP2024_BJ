#include<bits/stdc++.h>
using namespace std;
int l[10][20];
int main(){
    int a,b,c,d,e;
    char f,g;
    cin>>a;
    b=0;
    for (c=1;c<=a;c++)
    {
        cin>>f>>g;
        if (g>='2'&&g<='9') d=g-'0';
        else
        {
            if (g=='A') d=1;
            else if (g=='T') d=10;
            else if (g=='J') d=11;
            else if (g=='Q') d=12;
            else d=13;
        }
        if (f=='D') e=1;
        else if (f=='C') e=2;
        else if (f=='H') e=3;
        else e=4;
        if (l[e][d]==0) l[e][d]=1,b++;
    }
    cout<<52-b;
    return 0;
}
