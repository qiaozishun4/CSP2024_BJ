#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char have[53][2];
bool poker[53];
int n,cnt;
int change(char poker[]){
    int result=0;
    char color=poker[0],number=poker[1];

    if(color=='C') result+=13;
    if(color=='H') result+=26;
    if(color=='S') result+=39;

    if(number=='A') result+=1;
    if(number=='2') result+=2;
    if(number=='3') result+=3;
    if(number=='4') result+=4;
    if(number=='5') result+=5;
    if(number=='6') result+=6;
    if(number=='7') result+=7;
    if(number=='8') result+=8;
    if(number=='9') result+=9;
    if(number=='T') result+=10;
    if(number=='J') result+=11;
    if(number=='Q') result+=12;
    if(number=='K') result+=13;

    return result;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>have[i];
        poker[change(have[i])]=1;
    }
    for(int i=1;i<=52;i++){
        if(!poker[i]) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}