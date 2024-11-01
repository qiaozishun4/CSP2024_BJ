#include <iostream>

using namespace std;
bool poker[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int k;
    int res=52;
    cin>>k;
    for(int i=1; i<=k; i++){
        char p[2];
        cin>>p;
        int neww;
        if(p[1]=='T')neww=10;
        else if(p[1]=='J')neww=11;
        else if(p[1]=='Q')neww=12;
        else if(p[1]=='K')neww=13;
        else if(p[1]=='A')neww=1;
        else neww=p[1]-'0';

        if(p[0]=='D')poker[neww]=1;
        if(p[0]=='C')poker[13+neww]=1;
        if(p[0]=='H')poker[26+neww]=1;
        if(p[0]=='S')poker[39+neww]=1;
    }
    for(int i=1; i<=52; i++){
        res-=poker[i];
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
