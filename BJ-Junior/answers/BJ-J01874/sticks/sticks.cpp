#include<bits/stdc++.h>
using namespace std;
int sh[10]={6,2,5,5,4,5,6,3,7,6};//0,
bool px(string a,string b){
    if(a.size()==b.size()){
        int x=a.size();
        for(int i=0;i<x;i++){
            if(a[i]==b[i])
                continue;
            return a[i]<b[i];
        }
    }
    else
        return a.size()<b.size();
}
string xun(int x){
    string minn="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

    if(x==0){
        return "";
    }
    if(x==1||x<0){
        return "-1";
    }
    for(int i=9;i>=0;i--){
        string b=xun(x-sh[i]);
        if(b!="-1"){
            string a;
            if(i==0)
                a='0';
            else if(i==1)
                a='1';
            else if(i==2)
                a='2';
            else if(i==3)
                a='3';
            else if(i==4)
                a='4';
            else if(i==5)
                a='5';
            else if(i==6)
                a='6';
            else if(i==7)
                a='7';
            else if(i==8)
                a='8';
            else if(i==9)
                a='9';
            string ab=a+b;
            if(px(ab,minn))
            minn=ab;
        }
    }
    return minn;
}
string xun1(int x){
string minn="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

    if(x==1||x<0){
        return "-1";
    }
    for(int i=1;i<=9;i++){
        string b=xun(x-sh[i]);
        if(b!="-1"){
            string a;
            if(i==1)
                a='1';
            else if(i==2)
                a='2';
            else if(i==3)
                a='3';
            else if(i==4)
                a='4';
            else if(i==5)
                a='5';
            else if(i==6)
                a='6';
            else if(i==7)
                a='7';
            else if(i==8)
                a='8';
            else if(i==9)
                a='9';
            string ab=a+b;
            if(px(ab,minn))
            minn=ab;
        }
    }
    return minn;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin >> n;

    while(n--){

        int x;
        cin >> x;
        if(x%7==0){
        for(int i=0;i<x/7;i++){
            cout << 8;
        }
        cout << endl;
    }else if((x-1)%7==0&&x!=1){
        cout << 10;
        for(int i=0;i<(x-1)/7-1;i++)
            cout << 8;
        cout <<endl;
    }else if (x%7==4&&x!=4){
        cout << 20;
        for(int i=0;i<(x-4)/7-1;i++)
            cout << 8;
        cout <<endl;
    }else if(x%7==2&&x!=2){
        cout << 18;
        for(int i=0;i<(x-2)/7-1;i++)
            cout << 8;
        cout <<endl;
    }else if (x%7==3&&x!=3){
        cout << 46;
        for(int i=0;i<(x-3)/7-1;i++)
            cout << 8;
        cout <<endl;}else if (x%7==5&&x!=5){
        cout << 28;
        for(int i=0;i<(x-5)/7-1;i++)
            cout << 8;
        cout <<endl;}else if (x%7==6&&x!=6){
        cout << 26;
        for(int i=0;i<(x-6)/7-1;i++)
            cout << 8;
        cout <<endl;}
        else{
        cout << xun1(x);
        cout <<'\n';
    }
    }
    return  0;
}
