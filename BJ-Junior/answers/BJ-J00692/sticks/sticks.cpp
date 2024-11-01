#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[1]=6;
    b[1]=0;

    a[2]=2;
    b[2]=1;

    a[3]=5;
    b[3]=2;

    a[4]=5;
    b[4]=3;

    a[5]=4;
    b[5]=4;

    a[6]=5;
    b[6]=5;

    a[7]=6;
    b[7]=6;

    a[8]=3;
    b[8]=7;

    a[9]=7;
    b[9]=8;

    a[10]=6;
    b[10]=9;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        bool isfind=false;
        for(int i=1;i<=10;i++){
            if(a[i]==x&&b[i]!=0){
                isfind=true;
                cout<<b[i]<<endl;
                break;
            }
        }
        if(isfind==false){
            cout<<-1<<endl;
        }
    }
    return 0;
}
