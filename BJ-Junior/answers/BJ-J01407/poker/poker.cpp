#include<bits/stdc++.h>

using namespace std;

int s[4][13]={};

int main (){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n,hua,dian;

    string x;

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>x;
        if(x[0]=='D'){

            hua=0;
        }
        else if(x[0]=='C'){

            hua=1;
        }

        else if(x[0]=='H'){

            hua=2;
        }

        else if(x[0]=='S'){

            hua=3;
        }
        if(x[1]=='A'){

            dian=0;
        }

        else if(x[1]=='2'){

            dian=1;
        }
        else if(x[1]=='3'){

            dian=2;
        }
        else if(x[1]=='4'){

            dian=3;
        }
        else if(x[1]=='5'){

            dian=4;
        }
        else if(x[1]=='6'){

            dian=5;
        }
        else if(x[1]=='7'){

            dian=6;
        }
        else if(x[1]=='8'){

            dian=7;
        }
        else if(x[1]=='9'){

            dian=8;
        }
        else if(x[1]=='T'){

            dian=9;
        }
        else if(x[1]=='J'){

            dian=10;
        }
        else if(x[1]=='Q'){

            dian=11;
        }
        else if(x[1]=='K'){

            dian=12;
        }
        s[hua][dian]++;
    }
    int ans=0;
    for(int i=0;i<4;i++){

        for(int j=0;j<13;j++){

            if(s[i][j]==0){

                ans++;
            }
        }
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
