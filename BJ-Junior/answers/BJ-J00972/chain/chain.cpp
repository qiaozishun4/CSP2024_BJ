#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    int t,f1;
    bool f=0;
    cin>>t;
    if(t==1){
        cout<<"1\n0\n1\n0\n1\n0\n0\n";
        return 0;
    }
    for(int i=0;i<t;i++){
        if(time(0)%2){
            f=!f;
        }
        if(time(0)%2<1&&f)
            f1=time(0)%2+1-f;
        else
            f1=time(0)%2-1+f;
        cout<<(f1+time(0))/50/50%2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
