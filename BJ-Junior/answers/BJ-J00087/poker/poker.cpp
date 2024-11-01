#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int i,n,t;
    cin>>n;
    int card[13][4]={},c;
    char num,mark;
    for(i=0;i<n;i++)
    {
        cin>>mark>>num;
        if(mark=='D')
            mark=0;
        if(mark=='C')
            mark=1;
        if(mark=='H')
            mark=2;
        if(mark=='S')
            mark=3;
        if(num=='A')
            num='1';
        if(num=='T')
            num=10+'0';
        if(num=='J')
            num=11+'0';
        if(num=='Q')
            num=12+'0';
        if(num=='K')
            num=13+'0';
        num=num-'0'-1;
        card[num][mark]++;
    }
    t=0;
    for(i=0;i<13;i++)
    {
        for(c=0;c<4;c++)
        {
            if(card[i][c]<1)
                t++;
        }
    }
    cout<<t;
    return 0;
}