#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","r",stdout);
	int T,n,s,p;
	cin>>T;
	int v[T];
	for(int g=0;g<T;g++)
	{
		cin>>n;
		int a[n],c[n],color[n];
		for(int j=0;j<n;)
		{
			cin>>a[j];
		}
		if(n==3)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int i=0;i<3;i++){
							if(i==0 && color[i]!=color[i-1])
								c[i]=0;
							else if(color[i]==color[i-1] && a[i]==a[i-1])
								c[i]=a[i];
						}
						s=0;
						p=0;
						for(int i=0;i<3;i++)
							p+=c[i];
						if(p>s) s=p;
					}
				}
			}
			v[g]=s;
		}
		else if(n==4)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int dd=0;dd<=1;dd++){
							color[3]=dd;
							for(int i=0;i<4;i++){
								if(i==0 && color[i]!=color[i-1])
									c[i]=0;
								else if(color[i]==color[i-1] && a[i]==a[i-1])
									c[i]=a[i];
							}
							s=0;
							p=0;
							for(int i=0;i<4;i++)
								p+=c[i];
							if(p>s) s=p;
						}
					}
				}
			}
			v[g]=s;
		}
		else if(n==5)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int dd=0;dd<=1;dd++){
							color[3]=dd;
							for(int ee=0;ee<=1;ee++){
								color[4]=ee;
								for(int i=0;i<5;i++){
									if(i==0 && color[i]!=color[i-1])
										c[i]=0;
									else if(color[i]==color[i-1] && a[i]==a[i-1])
										c[i]=a[i];
								}
								s=0;
								p=0;
								for(int i=0;i<5;i++)
									p+=c[i];
								if(p>s) s=p;
							}
						}
					}
				}
			}
			v[g]=s;
		}
		else if(n==6)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int dd=0;dd<=1;dd++){
							color[3]=dd;
							for(int ee=0;ee<=1;ee++){
								color[4]=ee;
								for(int ff=0;ff<=1;ff++){
									color[5]=ff;
									for(int i=0;i<6;i++){
										if(i==0 && color[i]!=color[i-1])
											c[i]=0;
										else if(color[i]==color[i-1] && a[i]==a[i-1])
											c[i]=a[i];
									}
									s=0;
									p=0;
									for(int i=0;i<6;i++)
										p+=c[i];
									if(p>s) s=p;
								}
							}
						}
					}
				}
			}
			v[g]=s;
		}
		else if(n==7)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int dd=0;dd<=1;dd++){
							color[3]=dd;
							for(int ee=0;ee<=1;ee++){
								color[4]=ee;
								for(int ff=0;ff<=1;ff++){
									color[5]=ff;
									for(int gg=0;gg<=1;gg++){
										color[6]=gg;
										for(int i=0;i<7;i++){
											if(i==0 && color[i]!=color[i-1])
												c[i]=0;
											else if(color[i]==color[i-1] && a[i]==a[i-1])
												c[i]=a[i];
										}
										s=0;
										p=0;
										for(int i=0;i<7;i++)
										p+=c[i];
										if(p>s) s=p;
									}
								}
							}
						}
					}
				}
			}
			v[g]=s;
		}
		else if(n==8)
		{
			for(int aa=0;aa<=1;aa++)
			{
				color[0]=aa;
				for(int bb=0;bb<=1;bb++)
				{
					color[1]=bb;
					for(int cc=0;cc<=1;cc++)
					{
						color[2]=cc;
						for(int dd=0;dd<=1;dd++){
							color[3]=dd;
							for(int ee=0;ee<=1;ee++){
								color[4]=ee;
								for(int ff=0;ff<=1;ff++){
									color[5]=ff;
									for(int gg=0;gg<=1;gg++){
										color[6]=gg;
										for(int hh=0;hh<=1;hh++){
											color[7]=hh;
                                            for(int i=0;i<8;i++){
                                                if(i==0 && color[i]!=color[i-1])
                                                    c[i]=0;
                                                else if(color[i]==color[i-1] && a[i]==a[i-1])
                                                    c[i]=a[i];
                                            }
                                            s=0;
                                            p=0;
                                            for(int i=0;i<8;i++)
                                                p+=c[i];
                                            if(p>s) s=p;
                                        }
                                    }
								}
							}
						}
					}
				}
			}
            	}
		v[g]=s;
	}

    for(int ii=0;ii<T;ii++)
		cout<<v[ii]<<endl;

    return 0;
}
