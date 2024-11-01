#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool fl=true;
string s;
void f(int n,vector<string>&k){
    if(n==0){
        k.push_back(s);
        return ;
    }
    if(n>=2&&n!=3){
        s+='1';
        f(n-2,k);
        s=s.substr(0,s.length()-1);
    }
    if(n>=3&&n!=4){
        s+='7';
        f(n-3,k);
        s=s.substr(0,s.length()-1);
    }
    if(n>=4&&n!=5){
        s+='4';
        f(n-4,k);
        s=s.substr(0,s.length()-1);
    }
    if(n>=5&&n!=6){
        s+='2';
        f(n-5,k);
        s=s.substr(0,s.length()-1);
        s+='3';
        f(n-5,k);
        s=s.substr(0,s.length()-1);
        s+='5';
        f(n-5,k);
        s=s.substr(0,s.length()-1);
    }
    if(n>=6&&n!=7){
        s+='0';
        f(n-6,k);
        s=s.substr(0,s.length()-1);
        s+='6';
        f(n-6,k);
        s=s.substr(0,s.length()-1);
        s+='9';
        f(n-6,k);
        s=s.substr(0,s.length()-1);
    }
    if(n>=7&&n!=8){
        s+='8';
        f(n-7,k);
        s=s.substr(0,s.length()-1);
    }
}
bool f2(string a,string b){
    if(a[0]=='0'||b[0]=='0')return 0;
    if(a.length()<b.length())return 1;
    if(a.length()>b.length())return 0;
    int da=a.length()-1,db=b.length()-1;
    while(da>=0&&db>=0){
        if(a[da]<b[db])return 1;
        da--;
        db--;
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int k;
    vector<string>v;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int mx=0,n;
        scanf("%d",&n);
        if(n==2){
            cout<<1<<endl;
            continue;
        }
        else if(n==3){
            cout<<7<<endl;
            continue;
        }
        else if(n==4){
            cout<<4<<endl;
            continue;
        }
        else if(n==5){
            cout<<2<<endl;
            continue;
        }
        else if(n==6){
            cout<<6<<endl;
            continue;
        }
        else if(n==7){
            cout<<8<<endl;
            continue;
        }
        f(n,v);
        if(v.size()==0){
            cout<<"-1"<<endl;
            continue;
        }
        for(int j=0;j<v.size();j++){
            sort(v[j].begin(),v[j].end());
            if(v[j][0]=='0'){
                int xxx=0;string linshi,hou;
                for(int df=0;df<v[j].length();df++){
                    if(v[j][df]=='0')xxx++;
                    else hou+=v[j][df];
                }
                for(int df=0;df<xxx;df++)linshi+='0';
                if(xxx>=v[j].length())continue;
                else v[j]=hou[0]+linshi+hou.substr(1,hou.length());
            }
            if(f2(v[j],v[mx]))mx=j;
        }
        cout<<v[mx]<<endl;
        v.erase(v.begin(),v.end());
    }
    return 0;
}