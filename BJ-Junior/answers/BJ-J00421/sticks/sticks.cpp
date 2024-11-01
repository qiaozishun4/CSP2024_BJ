#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[20]={6,2,5,5,4,5,6,3,7,6};
string b[20]={"0","1","2","3","4","5","6","7","8","9"};
int t,k,num[N],ma;
string f[N];
string check(string a,string b){
    if(a.size()<b.size()) return a;
    if(a.size()>b.size()) return b;
    for(int i = 0;i < a.size();i++){
        if(a[i]<b[i]) return a;
        else if(a[i]>b[i]) return b;
    }
    return a;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i = 1;i <= t;i++){
        scanf("%d",&num[i]);
        ma=max(ma,num[i]);
    }
    for(int i = 0;i <= ma;i++) f[i]="-1";
    for(int i = 1;i <= 9;i++){
        string tmp=b[i];
        if(f[a[i]]=="-1") f[a[i]]=tmp;
        else f[a[i]]=check(f[a[i]],tmp);
    }
    for(int i = 8;i <= ma;i++){
        for(int j = 0;j <= 9;j++){
            string tmp=f[i-a[j]]+b[j];
            if(f[i]=="-1") f[i]=tmp;
            else f[i]=check(f[i],tmp);
        }
    }
    for(int i = 1;i <= t;i++){
        cout<<f[num[i]]<<endl;
    }
    return 0;
}
