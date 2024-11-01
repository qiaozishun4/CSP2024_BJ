#include<bits/stdc++.h>
using namespace std;
int hs[4][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        char k=a[1];
        if(a[0]=='D'){
            if(k>='2'&&k<='9'){
                int sz=k-48;
                //cout<<sz<<endl;
                if(hs[1][k]==0){
                    cnt++;
                    hs[1][k]=1;
                }
            }else{
                if(k=='A'){
                    if(hs[1][1]==0){
                        cnt++;
                        hs[1][1]=1;
                    }
                }
                if(k=='T'){
                    if(hs[1][10]==0){
                        cnt++;
                        hs[1][10]=1;
                    }
                }
                 if(k=='J'){
                    if(hs[1][11]==0){
                        cnt++;
                        hs[1][11]=1;
                    }
                }
                 if(k=='Q'){
                    if(hs[1][12]==0){
                        cnt++;
                        hs[1][12]=1;
                    }
                }
                 if(k=='K'){
                    if(hs[1][13]==0){
                        cnt++;
                        hs[1][13]=1;
                    }
                }

            }
        }else if(a[0]=='C'){
             if(k>='2'&&k<='9'){
                int sz=k-48;
                //cout<<sz<<endl;
                if(hs[2][k]==0){
                    cnt++;
                    hs[2][k]=1;
                }
            }else{
                if(k=='A'){
                    if(hs[2][1]==0){
                        cnt++;
                        hs[2][1]=1;
                    }
                }
                if(k=='T'){
                    if(hs[2][10]==0){
                        cnt++;
                        hs[2][10]=1;
                    }
                }
                 if(k=='J'){
                    if(hs[2][11]==0){
                        cnt++;
                        hs[2][11]=1;
                    }
                }
                 if(k=='Q'){
                    if(hs[2][12]==0){
                        cnt++;
                        hs[2][12]=1;
                    }
                }
                 if(k=='K'){
                    if(hs[2][13]==0){
                        cnt++;
                        hs[2][13]=1;
                    }
                }

            }
        }else if(a[0]=='H'){
          if(k>='2'&&k<='9'){
                int sz=k-48;
                //cout<<sz<<endl;
                if(hs[3][k]==0){
                    cnt++;
                    hs[3][k]=1;
                }
            }else{
                if(k=='A'){
                    if(hs[3][1]==0){
                        cnt++;
                        hs[3][1]=1;
                    }
                }
                if(k=='T'){
                    if(hs[3][10]==0){
                        cnt++;
                        hs[3][10]=1;
                    }
                }
                 if(k=='J'){
                    if(hs[3][11]==0){
                        cnt++;
                        hs[3][11]=1;
                    }
                }
                 if(k=='Q'){
                    if(hs[3][12]==0){
                        cnt++;
                        hs[3][12]=1;
                    }
                }
                 if(k=='K'){
                    if(hs[3][13]==0){
                        cnt++;
                        hs[3][13]=1;
                    }
                }

            }

        }else if(a[0]=='S'){
         if(k>='2'&&k<='9'){
                int sz=k-48;
                //cout<<sz<<endl;
                if(hs[4][k]==0){
                    cnt++;
                    hs[4][k]=1;
                }
            }else{
                if(k=='A'){
                    if(hs[4][1]==0){
                        cnt++;
                        hs[4][1]=1;
                    }
                }
                if(k=='T'){
                    if(hs[4][10]==0){
                        cnt++;
                        hs[4][10]=1;
                    }
                }
                 if(k=='J'){
                    if(hs[4][11]==0){
                        cnt++;
                        hs[4][11]=1;
                    }
                }
                 if(k=='Q'){
                    if(hs[4][12]==0){
                        cnt++;
                        hs[4][12]=1;
                    }
                }
                 if(k=='K'){
                    if(hs[4][13]==0){
                        cnt++;
                        hs[4][13]=1;
                    }
                }

            }


        }
    }
    cout<<52-cnt<<endl;











    return 0;
}
