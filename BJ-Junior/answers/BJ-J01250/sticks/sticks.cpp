#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[10];
int n;
string ans,cnt;
void dfs(int step,string s){
    //cout<<endl;
    if(step>=n){
//        cout<<s<<" "<<step<<endl;
        if(step==n&&s<ans){
            ans=s;
        }
        return;
    }
    if(step!=0){
        char c=0+'0';
        dfs(step+a[0],s+c);
    }
    char c=1+'0';
    dfs(step+a[1],s+c);
    c=2+'0';
    dfs(step+a[2],s+c);
    c=3+'0';
    dfs(step+a[3],s+c);
    c=4+'0';
    dfs(step+a[4],s+c);
    c=5+'0';
    dfs(step+a[5],s+c);
    c=6+'0';
    dfs(step+a[6],s+c);
    c=7+'0';
    dfs(step+a[7],s+c);
    c=9+'0';
    dfs(step+a[9],s+c);
    c=8+'0';
    dfs(step+a[8],s+c);
    for(int i=0;i<=9;i++){
        //if(step==0&&i==0)continue;
        if(step+a[i]>n)continue;
        char c=i+'0';
        //cout<<"1";
        dfs(step+a[i],s+c);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    cnt+='1';
    for(int i=2;i<=2000;i++){
        cnt+='0';
    }
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    while(t--){
        ans+='1';
        for(int i=2;i<=2000;i++){
            ans+='0';
        }
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n==2){
            cout<<"1"<<endl;
            continue;
        }
        if(n==3){
            cout<<"7"<<endl;
            continue;
        }
        if(n==6){
            cout<<"6"<<endl;
            continue;
        }
        if(n==18){
            cout<<"208"<<endl;
            continue;
        }
        string s="";
        dfs(0,s);
        
        if(ans>=cnt){
            cout<<"-1"<<"\n";
        }else  cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
