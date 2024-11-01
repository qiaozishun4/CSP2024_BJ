#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[11]={6,2,5,5,4,5,6,3,7,6};
    int n,cnt=0;
    cin>>n;
    freopen("sticks.in","r",stdin);
    int z[n+1];
    for(int i=1;i<=n;i++){
        cin>>z[i];
        freopen("sticks.in","r",stdin);
    }
    for(int i=0;i<=n;i++){
        for(int e=0;e<=7;e++){
            for(int j=0;j<=7;j++){
                for(int k=0;k<=7;;k++){
                    for(int l=0;l<=7;l++){
                        for(int m=0;m<=7;m++){
                            for(int g=0;g<=7;g++){
                                for(int a=0;a<=7;a++){
                                    for(int b=0;b<=7;b++){
                                        for(int c=0;c<=7;c++){
                                            for(int d=0;d<=7;d++){
                                                if(e+j+k+l+m+g+a+b+c+d<=z[i]){
                                                    cout<<e<<" "<<j<<" "<<l<<" "<<m<<" "<<g<<" "<<a<<" "<<b<<" "<<c<<" "<<d;
                                                    freopen("sticks.out","w",stdout);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
