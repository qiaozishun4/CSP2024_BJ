#include<bits/stdc++.h>
using namespace std;
//A 2 3 4 5 6 7 8 9 T J Q K。注意:点数 10 在本题中记为 T
//代表方片,字符 C 代表草花,字符 H 代表红桃,字符 S 代表黑桃
int nn,pcnt;
char a,b;
int diamonds[60],clubs[60],hearts[60],spades[60];
void poker_chooser(char x,char y){
    if(x=='D'){
        if(y=='A') diamonds[1]++;
        if(y=='2') diamonds[2]++;
        if(y=='3') diamonds[3]++;
        if(y=='4') diamonds[4]++;
        if(y=='5') diamonds[5]++;
        if(y=='6') diamonds[6]++;
        if(y=='7') diamonds[7]++;
        if(y=='8') diamonds[8]++;
        if(y=='9') diamonds[9]++;
        if(y=='T') diamonds[10]++;
        if(y=='J') diamonds[11]++;
        if(y=='Q') diamonds[12]++;
        if(y=='K') diamonds[13]++;
    }
    if(x=='C'){
        if(y=='A') clubs[1]++;
        if(y=='2') clubs[2]++;
        if(y=='3') clubs[3]++;
        if(y=='4') clubs[4]++;
        if(y=='5') clubs[5]++;
        if(y=='6') clubs[6]++;
        if(y=='7') clubs[7]++;
        if(y=='8') clubs[8]++;
        if(y=='9') clubs[9]++;
        if(y=='T') clubs[10]++;
        if(y=='J') clubs[11]++;
        if(y=='Q') clubs[12]++;
        if(y=='K') clubs[13]++;
    }
    if(x=='H'){
        if(y=='A') hearts[1]++;
        if(y=='2') hearts[2]++;
        if(y=='3') hearts[3]++;
        if(y=='4') hearts[4]++;
        if(y=='5') hearts[5]++;
        if(y=='6') hearts[6]++;
        if(y=='7') hearts[7]++;
        if(y=='8') hearts[8]++;
        if(y=='9') hearts[9]++;
        if(y=='T') hearts[10]++;
        if(y=='J') hearts[11]++;
        if(y=='Q') hearts[12]++;
        if(y=='K') hearts[13]++;
    }
    if(x=='S'){
        if(y=='A') spades[1]++;
        if(y=='2') spades[2]++;
        if(y=='3') spades[3]++;
        if(y=='4') spades[4]++;
        if(y=='5') spades[5]++;
        if(y=='6') spades[6]++;
        if(y=='7') spades[7]++;
        if(y=='8') spades[8]++;
        if(y=='9') spades[9]++;
        if(y=='T') spades[10]++;
        if(y=='J') spades[11]++;
        if(y=='Q') spades[12]++;
        if(y=='K') spades[13]++;
    }
}
void poker_checker(){
    for(int i=1;i<=13;i++){
        if(!diamonds[i]){
            pcnt++;
        }
        if(!clubs[i]){
            pcnt++;
        }
        if(!hearts[i]){
            pcnt++;
        }
        if(!spades[i]){
            pcnt++;
        }
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>a>>b;
        poker_chooser(a,b);
    }
    poker_checker();
    cout<<pcnt;
    return 0;
}
