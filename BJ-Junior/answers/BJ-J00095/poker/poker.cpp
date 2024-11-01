#include <bits/stdc++.h>
using namespace std;
bool a[5][15];
int cnt=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        char col,num;
        cin>>col>>num;
        int color,number;
        if(col=='D')color=1;
        if(col=='C')color=2;
        if(col=='H')color=3;
        if(col=='S')color=4;
        if(num<='9')number=num-'0';
        else if(num=='T')number=10;
        else if(num=='A')number=1;
        else if(num=='J')number=11;
        else if(num=='Q')number=12;
        else if(num=='K')number=13;
        if(a[color][number]==0){
            a[color][number]=1;
            cnt--;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
