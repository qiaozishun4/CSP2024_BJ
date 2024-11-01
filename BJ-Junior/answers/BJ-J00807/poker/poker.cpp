#include <bits/stdc++.h>
using namespace std;
int a[15],b[15],c[15],d[15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A'){
                a[1]=1;
            }else if(s[1]=='2'){
				a[2]=1;
			}else if(s[1]=='3'){
				a[3]=1;
			}else if(s[1]=='4'){
				a[4]=1;
			}else if(s[1]=='5'){
				a[5]=1;
			}else if(s[1]=='6'){
				a[6]=1;
			}else if(s[1]=='7'){
				a[7]=1;
			}else if(s[1]=='8'){
				a[8]=1;
			}else if(s[1]=='9'){
				a[9]=1;
			}else if(s[1]=='T'){
                a[10]=1;
            }else if(s[1]=='J'){
                a[11]=1;
            }else if(s[1]=='Q'){
                a[12]=1;
            }else if(s[1]=='K'){
                a[13]=1;
            }
        }else if(s[0]=='C'){
            if(s[1]=='A'){
                b[1]=1;
            }else if(s[1]=='2'){
				b[2]=1;
			}else if(s[1]=='3'){
				b[3]=1;
			}else if(s[1]=='4'){
				b[4]=1;
			}else if(s[1]=='5'){
				b[5]=1;
			}else if(s[1]=='6'){
				b[6]=1;
			}else if(s[1]=='7'){
				b[7]=1;
			}else if(s[1]=='8'){
				b[8]=1;
			}else if(s[1]=='9'){
				b[9]=1;
			}else if(s[1]=='T'){
                b[10]=1;
            }else if(s[1]=='J'){
                b[11]=1;
            }else if(s[1]=='Q'){
                b[12]=1;
            }else if(s[1]=='K'){
                b[13]=1;
            }
        }else if(s[0]=='H'){
            if(s[1]=='A'){
                c[1]=1;
            }else if(s[1]=='2'){
				c[2]=1;
			}else if(s[1]=='3'){
				c[3]=1;
			}else if(s[1]=='4'){
				c[4]=1;
			}else if(s[1]=='5'){
				c[5]=1;
			}else if(s[1]=='6'){
				c[6]=1;
			}else if(s[1]=='7'){
				c[7]=1;
			}else if(s[1]=='8'){
				c[8]=1;
			}else if(s[1]=='9'){
				c[9]=1;
			}else if(s[1]=='T'){
                c[10]=1;
            }else if(s[1]=='J'){
                c[11]=1;
            }else if(s[1]=='Q'){
                c[12]=1;
            }else if(s[1]=='K'){
                c[13]=1;
            }
        }else if(s[0]=='S'){
            if(s[1]=='A'){
                d[1]=1;
            }else if(s[1]=='2'){
				d[2]=1;
			}else if(s[1]=='3'){
				d[3]=1;
			}else if(s[1]=='4'){
			    d[4]=1;
			}else if(s[1]=='5'){
				d[5]=1;
			}else if(s[1]=='6'){
				d[6]=1;
			}else if(s[1]=='7'){
				d[7]=1;
			}else if(s[1]=='8'){
				d[8]=1;
			}else if(s[1]=='9'){
				d[9]=1;
			}else if(s[1]=='T'){
                d[10]=1;
            }else if(s[1]=='J'){
                d[11]=1;
            }else if(s[1]=='Q'){
                d[12]=1;
            }else if(s[1]=='K'){
                d[13]=1;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=13;i++){
        if(a[i]==0){
            sum++;
        }
        if(b[i]==0){
            sum++;
        }
        if(c[i]==0){
            sum++;
        }
        if(d[i]==0){
            sum++;
        }
    }
    cout<<sum;

    return 0;
}
