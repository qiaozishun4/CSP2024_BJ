#include<iostream>
#include<stdio.h>
using namespace std;
int n;
bool P[4][15];
int acc=0;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        char color,num;
        cin>>color>>num;
        int row,column;
        switch(color){
            case 'D':
                row=0;
                break;
            case 'C':
                row=1;
                break;
            case 'H':
                row=2;
                break;
            default:
                row=3;
        }
        if(num>='2'&&num<='9')
            column=num-'0'-1;
        else if(num=='A')
            column=0;
        else if(num=='T')
            column=9;
        else if(num=='J')
            column=10;
        else if(num=='Q')
            column=11;
        else
            column=12;

        if(!P[row][column]){
            P[row][column]=1;
            acc++;
        }
    }
    cout<<52-acc;

    fclose(stdin);
    fclose(stdout);
    return 0;
}