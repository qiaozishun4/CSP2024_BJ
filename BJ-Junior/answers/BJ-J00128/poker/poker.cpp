#include <iostream>
#include <cstring>
using namespace std;
int n,sign[5][15],p1,p2,cnt=0;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        if(s[0]=='D')p1=1;
        else if(s[0]=='C')p1=2;
        else if(s[0]=='H')p1=3;
        else if(s[0]=='S')p1=4;
        if('0'<=s[1]&&s[1]<='9')p2=s[1]-'0';
        else if(s[1]=='A')p2=1;
        else if(s[1]=='T')p2=10;
        else if(s[1]=='J')p2=11;
        else if(s[1]=='Q')p2=12;
        else if(s[1]=='K')p2=13;
        if(sign[p1][p2])continue;
        sign[p1][p2]=1;
        cnt++;
    }
    cout << 52-cnt<<endl;
    return 0;
}
