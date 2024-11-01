#include <bits/stdc++.h>
using namespace std;
long long t,n,minn=0;
void s(int sticks,long long num){
    if(sticks==0){
        if(minn==0) minn = num;
        else if(num<minn) minn = num;
        return ;
    }
    if(sticks<2) return ;
    if(num>214748364) return ;
    if(sticks>=2) s(sticks-2,num*10+1);
    if(sticks>=3) s(sticks-3,num*10+7);
    if(sticks>=4) s(sticks-4,num*10+4);
    if(sticks>=5) s(sticks-5,num*10+2);
    if(sticks>=6&&num==0) s(sticks-6,num+10+6);
    else if(sticks>=6) s(sticks-6,num*10);
    if(sticks>=7) s(sticks-7,num*10+8);
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i = 0;i < t;i++){
        cin>>n;
        if(n%7==0){
            for(int j = 1;j <= n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<10;
            for(int j = 1;j < n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            s(n,0);
            if(minn!=0) cout<<minn<<endl;
            else cout<<-1<<endl;
            minn = 0;
        }
	}
    return 0;
}
