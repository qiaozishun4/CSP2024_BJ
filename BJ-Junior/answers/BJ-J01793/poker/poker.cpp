#include<bits/stdc++.h>
using namespace std;
struct pocker{
    bool d;
    bool c;
    bool h;
    bool s;
}a[55];
int n,num,sum;
string np;
int main(){
      freopen("poker.in","r",stdin);
      freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){

    cin>>np;
    if(np[1]>='A' and np[1]<='Z'){
        if(np[1]=='A'){
            num=1;
        }else if(np[1]=='J'){
            num=11;
        }else if(np[1]=='Q'){
            num=12;
        }else if(np[1]=='K'){
            num=13;
        }else if(np[1]=='T'){
			num=10;
		}

    }else{
        num=np[1]-48;
    }
    if(np[0]=='D'){
        a[num].d='1';
    }else if(np[0]=='C'){
        a[num].c='1';
    }else if(np[0]=='H'){
        a[num].h='1';
    }else if(np[0]=='S'){
        a[num].s='1';

    }

    }
    if(n==52){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=13;i++){
        if(!a[i].d){
            sum++;
        }
        if(!a[i].c){
            sum++;
        }
        if(!a[i].h){
            sum++;
        }
        if(!a[i].s){
            sum++;
        }
    }
    cout<<sum;

    return 0;
}
