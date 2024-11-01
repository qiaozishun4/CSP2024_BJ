//passwd:GL@17SXYZ
//PDF:Y#C*GF@24
//LUCK COMES TO ME
//POKER
//CHECK:
//long long
//freopen
//return 0

#include<bits/stdc++.h>
using namespace std;
bool check[14][5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int sum=52;
    //D:FangPian=1;C:CaoHua=2;H:Hongtao=3;S:HeiTao=4;
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        int c;
        if(s[0]=='D') c=1;
        else if(s[0]=='C') c=2;
        else if(s[0]=='H') c=3;
        else /*if(s[0]=='S') */c=4;
        int num;
        if(s[1]>='0'&&s[1]<='9') num=(int) s[1]-'0';
        else if(s[1]=='T') num=10;
        else if(s[1]=='J') num=11;
        else if(s[1]=='Q') num=12;
        else if(s[1]=='K') num=13;
        else num=(int) s[1]-'0';
        if(check[num][c]==0){
            sum--;
            //cout<<"---"<<"c="<<c<<",num="<<num<<",the string is "<<s<<",DELETED,ans is "<<sum<<endl;
            check[num][c]=1;
        }
        //else cout<<"---"<<"c="<<c<<",num="<<num<<",the string is "<<s<<",WAS DELETED,ans is "<<sum<<endl;
    }
    cout<<sum;

    return 0;
}
