#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int n;
void slv(){
    cin>>n;
    if(n==1){
        cout<<-1<<endl;
        return ;
    }int x=n/7,y=n%7;
    if(y==0){
        ;
    }else if(y==1){
        putchar('1');putchar('0');x--;
    }else if(y==2){
        putchar('1');
    }else if(y==3){
        if(x==0) putchar('7');
        else if(x==1) putchar('2'),putchar('2'),x--;
        else putchar('2'),putchar('0'),putchar('0'),x-=2;
    }else if(y==4){
        if(x==0) putchar('4');
        else putchar('2'),putchar('0'),x--;
    }else if(y==5){
        putchar('2');
    }else if(y==6){
        putchar('6');
    }
    for(int i=1;i<=x;i++) putchar('8');
    putchar('\n');
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
    return 0;
}//jp8akioi