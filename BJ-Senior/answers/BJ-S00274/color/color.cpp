
#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,t;
long long d[100000],v[100010],a[1000100],p[100011];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	while(t--){
		int n,b[1000001],min=-1,maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int a=1;a<=2;a++){
			for(int b=1;b<=2;b++){
				for(int c=1;c<=2;c++){
					for(int d=1;d<=2;d++){
						for(int e=1;e<=2;e++){
							for(int f=1;f<=2;f++){
								for(int g=1;g<=2;g++){
									for(int h=1;h<=2;h++){
										for(int j=1;j<=2;j++){
											for(int k=1;k<=2;k++){
												for(int l=1;l<=2;l++){
													for(int m=1;m<=2;m++){
														for(int n=1;n<=2;n++){
															for(int o=1;o<=2;o++){
																for(int p=1;p<=2;p++){
																	int a[100001]=[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p];
																	for(int z=1;z<=n;z++){
																		for(int x=z+1;z<=n;x++){
																			if(a[z]==a[x]){
																				min+=a[z];
																			}
																		}
																	}
																	maxn=max(maxn,min);
																	min=-1
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
		cout<<maxn<<endl;
	}
	return 0;
}
