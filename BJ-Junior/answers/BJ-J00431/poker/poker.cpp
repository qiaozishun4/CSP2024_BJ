#include <bits/stdc++.h>
using namespace std;
int s[4][13]={};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=52;
    for(int xs=1;xs<=n;xs++){
        char h,p;
        cin>>h>>p;
        int h1,p1;
        if(h=='D')h1=0;
        if(h=='C')h1=1;
        if(h=='H')h1=2;
        if(h=='S')h1=3;
        if(p>'1'&&p<='9')p1=p-'0'-1;
        else{
            if(p=='A')p1=0;
            if(p=='T')p1=9;
            if(p=='J')p1=10;
            if(p=='Q')p1=11;
            if(p=='K')p1=12;
        }
        if(s[h1][p1]==0)ans--;
        s[h1][p1]++;
    }
    cout<<ans;
    return 0;
}
