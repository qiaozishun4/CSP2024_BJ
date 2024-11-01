#include<bits/stdc++.h>
using namespace std;
char A[10]={0,1,2,3,4,5,6,7,8,9};
int a[10]={6,2,5,5,4,5,6,3,7,6};
string ans="";
void f(int n,int step){
    if(step==1){
        bool flag=false;
        for(int i=1;i<10;i++){
            if(n-a[i]>0){
                flag=true;
                ans+=A[i];
                f(n-a[i],++step);
            }
        }
        if(!flag){
            ans.length()--;
            return;
        }
    }else{
        bool flag=false;
        for(int i=0;i<10;i++){
            if(n-a[i]>0){
                flag=true;
                ans+=A[i];
                f(n-a[i],++step);
            }
        }
        if(!flag){
            ans.length()--;
            return;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int step=1;
        int x;
        cin>>x;
        f(x,1);
        if(ans.length()){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
        ans="";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
