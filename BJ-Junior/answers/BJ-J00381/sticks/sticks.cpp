#include<bits/stdc++.h>
using namespace std;
int yy[12]={0,6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        /*for(int a=0;a<=9;a++){
            for(int b=0;b<=9;b++){
                for(int c=0;c<=9;c++){
                    for(int d=0;d<=9;d++){
                        for(int e=0;e<=9;e++){
                            for(int f=0;f<=9;f++){
                                for(int g=0;g<=9;g++){
                                    for(int h=0;h<=9;h++){
                                        for(int i=0;i<=9;i++){
                                            for(int j=0;j<=9;j++){
                                                if(yy[a]+yy[b]+yy[c]+yy[d]+yy[e]+yy[f]+yy[g]+yy[h]+yy[i]+yy[j]==x){
                                                    for(int k=0;k<=4;k++){
                                                         if(a!=0&&a!=1)cout<<a;
                                                         if(b!=0&&b!=1)cout<<b;
                                                         if(c!=0&&c!=1)cout<<c;
                                                         if(d!=0&&d!=1)cout<<d;
                                                         if(e!=0&&e!=1)cout<<e;
                                                         if(f!=0&&f!=1)cout<<f;
                                                         if(g!=0&&g!=1)cout<<g;
                                                         if(h!=0&&h!=1)cout<<h;
                                                         if(i!=0&&i!=1)cout<<i;
                                                         if(j!=0&&j!=1)cout<<j;
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
        }*/
        cout<<-1<<endl;
    }

    return 0;
}
