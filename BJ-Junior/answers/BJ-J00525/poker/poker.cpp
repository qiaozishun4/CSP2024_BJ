#include<bits/stdc++.h>
using namespace std;

int n;
char a[14]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b[5]={'0','D','C','H','S'};
int t[14][5];
int cnt=0;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        char s1,s2;
        cin>>s1>>s2;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=13;j++)
                if(a[j]==s2&&b[i]==s1)
                    t[j][i]++;
    }
    for(int i=1;i<=13;i++)
        for(int j=1;j<=4;j++)
            if(t[i][j]>0)
                cnt++;

    cout<<52-cnt;
    return 0;
}
