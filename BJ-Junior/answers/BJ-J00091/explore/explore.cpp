#include<iostream>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,d,t,x,y,cnt;
    cin>>t;
    for (int i=0;i<t;i++){
        cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        string a;
        cin>>a;
        if (m==1){
            cout<<1<<endl;
        }
        else{
            if (a==".x") cout<<1<<endl;
            else if (a=="x.") cout<<1<<endl;
            else{
                if(d==1) cout<<1<<endl;
                else if (d==3) cout<<1<<endl;
                else if (d==2){
                    if (y==1) cout<<1<<endl;
                    else cout<<2<<endl;
                }
                else{
                    if (y==1) cout<<2<<endl;
                    else cout<<1<<endl;
                }
            }

        }

    }
return 0;
}


