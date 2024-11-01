#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int pai[52]={};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char hua,dian;
        cin>>hua>>dian;
        int id=0;
        if(hua=='H')
            id+=13;
        if(hua=='D')
            id+=26;
        if(hua=='C')
            id+=39;
        if(dian=='T')
            id+=9;
        else if(dian=='J')
            id+=10;
        else if(dian=='Q')
            id+=11;
        else if(dian=='K')
            id+=12;
        else if(dian>'1')
            id+=(dian-'1');
        pai[id]++;
    }
    int cnt=0;
    for(int i=0;i<52;i++)
    {
        if(pai[i]==0)
            cnt++;
    }
    cout<<cnt;
    fclose("poker.in");
    fclose("poker.out");
    return 0;
}