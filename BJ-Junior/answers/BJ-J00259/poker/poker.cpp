#include <iostream>
using namespace std;
bool Poker[52];
int n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        char a,b;
        cin >> a >> b;
        int bn;
        if(b>='2' && b<='9')bn=b-'0'-1;
        else if(b=='A')bn=0;
        else if(b=='T')bn=9;
        else if(b=='J')bn=10;
        else if(b=='Q')bn=11;
        else if(b=='K')bn=12;
        if(a=='D')Poker[bn]=true;
        if(a=='C')Poker[bn+13]=true;
        if(a=='H')Poker[bn+2*13]=true;
        if(a=='S')Poker[bn+3*13]=true;
    }
    for(int i=0;i<52;i++)if(!Poker[i])ans++;
    cout << ans;
    return 0;
}
