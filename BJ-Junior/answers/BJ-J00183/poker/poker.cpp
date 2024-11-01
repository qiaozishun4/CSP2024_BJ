#include<bits/stdc++.h>
using namespace std;
bool Poker[27][4];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        if (s[1]=='A')
            s[1]='1';
        if (s[1]=='T')
            s[1]='0'+10;
        if (s[1]=='J')
            s[1]='0'+11;
        if (s[1]=='Q')
            s[1]='0'+12;
        if (s[1]=='K')
            s[1]='0'+13;
        if (s[0]=='D')
            Poker[s[1]-'0'][0]=true;
        else if (s[0]=='C')
            Poker[s[1]-'0'][1]=true;
        else if (s[0]=='H')
            Poker[s[1]-'0'][2]=true;
        else if (s[0]=='S')
            Poker[s[1]-'0'][3]=true;
    }
    int sum=0;
    for (int i=1;i<=13;i++)
        for (int j=0;j<4;j++)
            if (Poker[i][j])
                sum++;
    cout<<52-sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
