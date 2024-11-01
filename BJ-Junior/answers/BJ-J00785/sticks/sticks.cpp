#include<iostream>
using namespace std;
int T;
int num[15]={6,2,5,5,4,5,6,3,7,6};
long long n;
long long stringToInt(string str){
    long long len=str.length();
    long long rslt=0;
    for(long long i=0;i<len;i++){
        rslt=rslt*10+(str[i]-48);
    }
    return rslt;
}
long long minn=0x3f3f3f3f;
void dfs(long long rest,string s){
    if(rest<=0){
        if(rest==0){
            if(s[0]!='0'){
                long long ans=stringToInt(s);


                if(ans<minn){
                    minn=ans;
                }
            }
        }
        return;
    }
    for(int i=0;i<=9;i++){

        dfs(rest-num[i],s+char(i+48));

    }

}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        minn=0x3f3f3f3f;
        cin>>n;
        dfs(n,"");
        if(minn==0x3f3f3f3f){
            cout<<-1<<endl;
        }else{
            cout<<minn<<endl;
        }
    }
    return 0;
}
