#include<bits/stdc++.h>
#include<vector>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,c=0;
    vector<int> ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;c=0;
        cin>>a;
        if(a==1){cout<<-1<<endl;continue;}
        else if(a<=7){
            for(int j=1;j<10;j++){
                if(a==stick[j]){cout<<j<<endl;c=1;}
            }
        }
        else{

                int cnt=0,l,sumtemp=0;
                if(l%7==0){l=a/7;}
                else {l=a/7+1;}//没问题,l是位数

                for(int j=1;j<=l;j++){
                        if(j==l)
                            {
                          for(int jk=0;jk<=9;jk++){
                                     if(a==stick[jk]){ans.push_back(jk);break;}
            }//末位
            }

            else{
                    for(int k=0;k<=9;k++){
                        if(j==1&&k==0)continue;
                        else if(a-stick[k]<=(l-j)*7){a-=stick[k];ans.push_back(k);c=1;break;}
                    }

                }
                }
                 for(int j=0;j<l;j++){
                        cout<<ans[j];
                }cout<<endl;
                ans.clear();



            }
        }
        if(c==0)cout<<-1<<endl;


    fclose(stdin);
    fclose(stdout);



return 0;}
