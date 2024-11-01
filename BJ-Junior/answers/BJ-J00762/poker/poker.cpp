#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long po[205][205];
char potype[5]={'K','D','C','H','S'};
char pokind[14]={'S','A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
long long n,ans;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    memset(po,0,sizeof(po));
    for(int i=1;i<=n;i++){
        cin>>s;
        char type=s[0];
        char kind=s[1];
        po[type][kind]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(po[potype[i]][pokind[j]]>=1)ans++;
        }
    }

    cout << 52-ans << endl;
    return 0;
}

