#include <bits/stdc++.h>
using namespace std;
int a[10],b[8],ans[14290];
bool f=0;
int T;
int num;
int n, m;
void dfs(int s, int c) {
    //cout<<s<<" "<<c<<"\n";
     if(c==1){
        if(s>7||s<2)return;
        else {
            if(s!=6)ans[c]=b[s];
            else if(c==m)ans[c]=6;
            else ans[c]=b[s];
        }
        if(f);
        else {
            for(int i=m;i>=1;i--)cout<<ans[i];
            cout<<"\n";
            f=!f;
        }
     }
     else{
        if(c==m){
            for(int i=1;i<=9;i++){
                ans[c]=i;
                dfs(s-a[i],c-1);
            }
         }else {
            for(int i=0;i<=9;i++){
                ans[c]=i;
                dfs(s-a[i],c-1);
            }
         }
     }
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[0]=6;a[1]=2;a[2]=5;a[3]=5;a[4]=4;a[5]=5;a[6]=6;a[7]=3;a[8]=7;a[9]=6;
    b[2]=1;b[3]=7;b[4]=4;b[5]=2;b[6]=0;b[7]=8;

    cin>>T;
    while(T){
        cin>>n;
        if(n<=14){
            if(n%7==0) {
                m=n/7;
                for(int i=1;i<=m;i++)cout<<8;
                cout<<"\n";
            }
            else{
                m=n/7+1;dfs(n,m);
                if(f==0)cout<<-1<<"\n";
                else f=0;
            }

        }
        else{
            m=n/7;
            if(n%7==0) {
                for(int i=1;i<=m;i++)cout<<8;
                cout<<"\n";
            }else if(n%7==1) {
                cout<<"10";
                for(int i=2;i<=m;i++)cout<<8;
                cout<<"\n";
            }else if(n%7==2){
                cout<<1;
                for(int i=1;i<=m;i++)cout<<8;
                cout<<"\n";
            }else if(n%7==3){
                cout<<"200";
                for(int i=3;i<=m;i++)cout<<8;
                cout<<"\n";
            }else if(n%7==4){
                cout<<"20";
                for(int i=2;i<=m;i++)cout<<8;
                cout<<"\n";
            }else if(n%7==5){
                cout<<2;
                for(int i=1;i<=m;i++)cout<<8;
                cout<<"\n";
            }else {
                cout<<6;
                for(int i=1;i<=m;i++)cout<<8;
                cout<<"\n";
            }
        }
        T--;
    }

    return 0;
}
