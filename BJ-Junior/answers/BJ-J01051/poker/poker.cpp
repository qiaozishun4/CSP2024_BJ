#include<iostream>
using namespace std;
bool have[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
/*    map<char,int> huase;
    huase['D']=0;
    huase["C"]=1;
    huase["H"]=2;
    huase["S"]=3;
    map<char,int> dianshu;
    dianshu["A"]=1;
    dianshu["2"]=2;
    dianshu["3"]=3;
    dianshu["4"]=4;
    dianshu["5"]=5;
    dianshu["6"]=6;
    dianshu["7"]=7;
    dianshu["8"]=8;
    dianshu["9"]=9;
    dianshu["T"]=10;
    dianshu["J"]=11;
    dianshu["Q"]=12;
    dianshu["K"]=13;*/
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char ds,hs;
        cin>>hs>>ds;
        int aa,bb;
        switch(hs){
            case 'D':aa=0;break;
            case 'C':aa=1;break;
            case 'H':aa=2;break;
            case 'S':aa=3;break;
        }
        if(ds>='2'&&ds<='9'){
            bb=ds-'0';
        }
        else{
            switch(ds){
                case 'A':bb=1;break;
                case 'T':bb=10;break;
                case 'J':bb=11;break;
                case 'Q':bb=12;break;
                case 'K':bb=13;break;
            }
        }
        have[aa*13+bb]=1;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(have[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
