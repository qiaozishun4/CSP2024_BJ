#include <bits/stdc++.h>
using namespace std;
bool a[13][4];
long long n,ans=0;
char num[2];
long long number,color;


int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>num;
        if(num[0]=='D')color=0;
        else if(num[0]=='C')color=1;
        else if(num[0]=='H')color=2;
        else if(num[0]=='S')color=3;
        if(num[1]=='A')number=0;
        else if(num[1]=='2')number=1;
        else if(num[1]=='3')number=2;
        else if(num[1]=='4')number=3;
        else if(num[1]=='5')number=4;
        else if(num[1]=='6')number=5;
        else if(num[1]=='7')number=6;
        else if(num[1]=='8')number=7;
        else if(num[1]=='9')number=8;
        else if(num[1]=='T')number=9;
        else if(num[1]=='J')number=10;
        else if(num[1]=='Q')number=11;
        else if(num[1]=='K')number=12;
        a[number][color]=true;
    }
    for(int i = 0;i<13;i++){
        for(int j = 0;j<4;j++){
            if(a[i][j]==false)ans++;
        }
    }
    cout<<ans;
    return 0;
}
