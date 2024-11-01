#include <bits/stdc++.h>
using namespace std;
int n,cnt=52;
bool flag[14][5];
int num,c;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        cin>>s;
        if(s[1]=='A'){
            num=1;
        }
        if(s[1]=='2'){
            num=2;
        }
        if(s[1]=='3'){
            num=3;
        }
        if(s[1]=='4'){
            num=4;
        }
        if(s[1]=='5'){
            num=5;
        }
        if(s[1]=='6'){
            num=6;
        }
        if(s[1]=='7'){
            num=7;
        }
        if(s[1]=='8'){
            num=8;
        }
        if(s[1]=='9'){
            num=9;
        }
        if(s[1]=='T'){
            num=10;
        }
        if(s[1]=='J'){
            num=11;
        }
        if(s[1]=='Q'){
            num=12;
        }
        if(s[1]=='K'){
            num=13;
        }
        if(s[0]=='D'){
            c=1;
        }
        if(s[0]=='C'){
            c=2;
        }
        if(s[0]=='H'){
            c=3;
        }
        if(s[0]=='S'){
            c=4;
        }
        if(!flag[num][c]){
            flag[num][c]=true;
            cnt--;
        }
    }
    printf("%d",cnt);
    return 0;
}