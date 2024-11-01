#include <bits/stdc++.h>

using namespace std;
bool p[100][100];
char f,c;
/*
字符 D 代表方片,字符 C 代表草花,
字符 H 代表红桃,字符 S 代表黑桃,
*/
int df(){
    if(f=='D')return 0;
    if(f=='C')return 1;
    if(f=='H')return 2;
    if(f=='S')return 3;
}
//A 2 3 4 5 6 7 8 9 T  J  Q  K
//1 2 3 4 5 6 7 8 9 10 11 12 13
int dc(){
    if(c=='A')return 1;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    return c-48;
}
int main(){
    freopen("poker1.in","r",stdin);
    freopen("poker1.out","w",stdout);
    int n;cin>>n;
    while(n--){
        cin>>f>>c;
        p[df()][dc()]=1;
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++)
            if(p[i][j]==0)
                sum++;
    }
    cout<<sum<<endl;
    return 0;
}
