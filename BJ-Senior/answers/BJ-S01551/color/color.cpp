#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],b[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int pt=1;pt<=t;pt++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int sum=0,ans=-1;
        for(int p1=1;p1<=2;p1++){
            b[1]=p1;
            for(int p2=1;p2<=2;p2++){
                b[2]=p2;
                for(int p3=1;p3<=2;p3++){
                    b[3]=p3;
                    for(int p4=1;p4<=2;p4++){
                        b[4]=p4;
                        for(int p5=1;p5<=2;p5++){
                            b[5]=p5;
                            for(int p6=1;p6<=2;p6++){
                                b[6]=p6;
                                for(int p7=1;p7<=2;p7++){
                                    b[7]=p7;
                                    for(int p8=1;p8<=2;p8++){
                                        b[8]=p8;
                                        for(int p9=1;p9<=2;p9++){
                                            b[9]=p9;
                                            for(int p10=1;p10<=2;p10++){
                                                b[10]=p10;
                                                for(int p11=1;p11<=2;p11++){
                                                    b[11]=p11;
                                                    for(int p12=1;p12<=2;p12++){
                                                        b[12]=p12;
                                                        for(int p13=1;p13<=2;p13++){
                                                            b[13]=p13;
                                                            for(int p14=1;p14<=2;p14++){
                                                                b[14]=p14;
                                                                for(int p15=1;p15<=2;p15++){
                                                                    b[15]=p15;
                                                                    sum=0;
                                                                    for(int j=1;j<=15;j++){
                                                                        int l=j-1;
                                                                        while(l>=1){
                                                                            if(b[l]==b[j]){
                                                                                if(a[l]==a[j]){
                                                                                    sum+=a[j];
                                                                                }
                                                                                break;
                                                                            }
                                                                            l--;
                                                                        }
                                                                    }
                                                                    ans=max(sum,ans);
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
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
