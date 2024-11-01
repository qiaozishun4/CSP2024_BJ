#include <bits/stdc++.h>
using namespace std;
int n;
int mp[5][15];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(mp,0,sizeof(mp));
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        cin>>s;
        int t1=0,t2=0;
        if (s[0]=='D') t1=1;
        else if (s[0]=='C') t1=2;
        else if (s[0]=='H') t1=3;
        else t1=4;
        if (s[1]>='0' and s[1]<='9'){
            t2=s[1]-'0';
        }
        else{
            if (s[1]=='A') t2=1;
            else if (s[1]=='T') t2=10;
            else if (s[1]=='J') t2=11;
            else if (s[1]=='Q') t2=12;
            else if (s[1]=='K') t2=13;
        }
        mp[t1][t2]=1;
    }
    int ans=0;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=13;j++){
            if (mp[i][j]==0) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
                    /////////////////////////////////////         PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                  888888888888888888888888
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8   
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                   88888888888888888888888 
                                    ///                           P                                               8                       8 
                                    ///                           P                                              8                         8
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                           ///     ///                            P                                             8                           8
                            /////////                             P                                              888888888888888888888888888
*/