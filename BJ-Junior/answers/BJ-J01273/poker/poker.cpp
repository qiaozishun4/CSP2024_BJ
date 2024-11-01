#include<bits/stdc++.h>
using namespace std;
int card[4][13],n,num;
char a,b;
void add(int j,int k){
    if((b>='2')&&(b<='9'))card[j][b-'0'-1]++;
    else if(b=='A')card[j][0]++;
    else if(b=='T')card[j][9]++;
    else if(b=='J')card[j][10]++;
    else if(b=='Q')card[j][11]++;
    else card[j][12]++;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a=='D')add(0,b);
        else if(a=='C')add(1,b);
        else if(a=='H')add(2,b);
        else add(3,b);
    }
    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            if(card[i][j]==0)num++;
        }
    }
    cout<<num;
    return 0;
}