#include<bits/stdc++.h>
using namespace std;
int d[10]={6,2,5,5,4,5,6,3,7,6};
string f[100005];
string num(string a,int b){
    if(b==0){
        string s2;
        s2+=a[0];
        s2+=(char)(b+'0');
        for(int i=1;i<a.size();i++){
            s2+=a[i];
        }
        return s2;
    }else{
        string s2;
        bool q=1;
        bool q2=0;
        for(int i=0;i<a.size();i++){
            if((char)(b+'0')<=a[i]&&q){
                s2+=(char)(b+'0');
                q=0;
            }
            if(a[i]!='0'||q2){
                s2+=a[i];
                q2=1;
            }
        }
        if(q)s2+=(char)(b+'0');
        return s2;
    }
}
string mins(string a,string b){
    if(a.size()<b.size())return a;
    if(a.size()>b.size())return b;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            if(a[i]>b[i])return b;
            else return a;
        }
    }
    return a;
}
int main(){
    freopen("sticks.cpp","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<=100000;i++)f[i]='0';
    for(int i=0;i<=9;i++){
        if(f[d[i]][0]=='0')
        f[d[i]]=(char)(i+'0');
    }
    for(int i=0;i<=10000;i++){
        for(int j=0;j<=9;j++){
            bool q=0;
            for(int k=0;k<f[i].size();k++)if(f[i][k]!='0')q=1;
            if(!q)
            continue;
            string a=num(f[i],j);
            if(f[i+d[j]][0]=='0'&&j!=0)f[i+d[j]]=a;
            else f[i+d[j]]=mins(f[i+d[j]],a);
        }
    }
    int n;
    cin>>n;
    while(n--){
        int i;
        cin>>i;
        if(f[i][0]=='0'&&f[i].size()==1)cout<<"-1"<<endl;
        else{
            bool q=0;
            for(int j=0;j<f[i].size();j++){
                if(f[i][j]!='0'||q){
                    cout<<f[i][j];
                    q=1;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}