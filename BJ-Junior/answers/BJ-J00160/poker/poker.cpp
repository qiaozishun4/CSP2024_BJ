#include <iostream>
#include <string>
using namespace std;
bool p[64];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=0;i<64;i++)   p[i]=false;
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        string s;
        int r=0;
        cin>>s;
        if(s[0]=='S') r+=39;
        else if(s[0]=='H') r+=26;
        else if(s[0]=='D') r+=13;
        if(s[1]=='2') r++;
        else if(s[1]=='3') r+=2;
        else if(s[1]=='4') r+=3;
        else if(s[1]=='5') r+=4;
        else if(s[1]=='6') r+=5;
        else if(s[1]=='7') r+=6;
        else if(s[1]=='8') r+=7;
        else if(s[1]=='9') r+=8;
        else if(s[1]=='T') r+=9;
        else if(s[1]=='J') r+=10;
        else if(s[1]=='Q') r+=11;
        else if(s[1]=='K') r+=12;
        p[r]=true;
        //cout<<r;
    }
    int ans=52;
    for(int i=0;i<52;i++)   if(p[i])    ans--;
    cout<<ans;
    return 0;
}
