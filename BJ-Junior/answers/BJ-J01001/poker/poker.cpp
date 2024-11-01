#include<bits/stdc++.h>
using namespace std;
int n;
string a[52];
int p[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int j=-1,k=-1;
        if(a[i][0]=='D')j=0;
        else if(a[i][0]=='C')j=1;
        else if(a[i][0]=='H')j=2;
        else j=3;
        if(a[i][1]=='A')k=0;
        else if(a[i][1]=='2')k=1;
        else if(a[i][1]=='3')k=2;
        else if(a[i][1]=='4')k=3;
        else if(a[i][1]=='5')k=4;
        else if(a[i][1]=='6')k=5;
        else if(a[i][1]=='7')k=6;
        else if(a[i][1]=='8')k=7;
        else if(a[i][1]=='9')k=8;
        else if(a[i][1]=='T')k=9;
        else if(a[i][1]=='J')k=10;
        else if(a[i][1]=='Q')k=11;
        else if(a[i][1]=='k')k=12;
        p[j][k]++;
    }
    int li=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(p[i][j]==0)li++;
        }
    }
    cout<<li;
    return 0;
}
