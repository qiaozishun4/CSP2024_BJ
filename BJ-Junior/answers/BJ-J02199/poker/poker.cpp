#include<bits/stdc++.h>
using namespace std;
bool a[80];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int b;
    char c[2];
    cin>>b;
    for(int i=0;i<b;i++){
        cin>>c[0]>>c[1];
        if(c[1]>'0'&&c[1]<='9'){
            if(c[0]=='D'){
                a[c[1]-48]=1;
            }else if(c[0]=='C'){
                a[c[1]-28]=1;
            }else if(c[0]=='H'){
                a[c[1]-8]=1;
            }else{
                a[c[1]+12]=1;
            }
        }else{
            if(c[1]=='A'){
                if(c[0]=='D'){
                    a[1]=1;
                }else if(c[0]=='C'){
                    a[21]=1;
                }else if(c[0]=='H'){
                    a[41]=1;
                }else{
                    a[61]=1;
                }
            }else if(c[1]=='T'){
                if(c[0]=='D'){
                    a[10]=1;
                }else if(c[0]=='C'){
                    a[30]=1;
                }else if(c[0]=='H'){
                    a[50]=1;
                }else{
                    a[70]=1;
                }
            }else if(c[1]=='J'){
                if(c[0]=='D'){
                    a[11]=1;
                }else if(c[0]=='C'){
                    a[31]=1;
                }else if(c[0]=='H'){
                    a[51]=1;
                }else{
                    a[71]=1;
                }
            }else if(c[1]=='Q'){
                if(c[0]=='D'){
                    a[12]=1;
                }else if(c[0]=='C'){
                    a[32]=1;
                }else if(c[0]=='H'){
                    a[52]=1;
                }else{
                    a[72]=1;
                }
            }else if(c[1]=='K'){
                if(c[0]=='D'){
                    a[13]=1;
                }else if(c[0]=='C'){
                    a[33]=1;
                }else if(c[0]=='H'){
                    a[53]=1;
                }else{
                    a[73]=1;
                }
            }
        }
    }
    int sum=52;
    for(int i=0;i<80;i++){
        if(a[i]){
            sum--;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
