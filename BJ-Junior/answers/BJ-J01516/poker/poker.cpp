#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    //freopen("poker.in","r",stdin);
    //freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            if((n>=1&&n<52)&&(a[i]>=2&&a[i]<=10)||(a[i]=='J'&&a[i]=='Q'&&a[i]=='K'&&a[i]=='A')){
                if(a[1]=='D'||a[1]=='A'||a[1]=='S'||a[1]=='D'){
                    cout<<52-n;
                }
                else{

                }
            }
            else{

            }
        }
    }


    return 0;
}
