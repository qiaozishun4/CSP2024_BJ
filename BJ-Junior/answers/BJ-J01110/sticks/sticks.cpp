#include<bits/stdc++.h>
using namespace std;
int n,x,j;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0||x==1){
            cout<<-1<<endl;
            continue;
        }
        j=1;
        while(true){
            int tmp=j,st=0;
            while(tmp/=10){
                st+=a[tmp%10];
            }
            if(st==x){
                cout<<j/10<<endl;
                break;
            }
            j++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}