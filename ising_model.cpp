#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 200
main()
    {
    double x,y,u,r;
    double rands();
    int n[N][N];//定义一个正方形格子
    long int i,j,l,m,k;
    FILE *p;
    p=fopen("18.dat","w");
	FILE *p1;
	p1=fopen("18.1.dat","w");
	FILE *p2;
	p2=fopen("18.2.dat","w");
	FILE *p3;
	p3=fopen("18.3.dat","w");
	FILE *p4;
	p4=fopen("18.4.dat","w");
	for(l=0;l<=1000;l++)//定义初始比例K=L/1000
	{
		r=(double)l/1000;
		for(i=0;i<N;i++)//初始化矩阵
		{
			for(j=0;j<N;j++)
			{
				u=rands();
				if(u<r) n[i][j]=1;
				else n[i][j]=-1;
			}
		}
		for(k=0;k<2000;k++)//定义步数
		{
		    for(i=0;i<N;i++)
			{
			    for(j=i%2;j<N;j=j+2)//对于j为偶，循环一次
				{
					if(i==0&&j==0) m=n[0][1]+n[1][0];//定义矩阵元的邻居
					if(j!=0&&j!=N-1&&i==0) m=n[0][j-1]+n[0][j+1]+n[1][j];
					if(j==N-1&&i==0) m=n[0][N-2]+n[1][N-1];
					if(j==N-1&&i!=0&&i!=N-1) m=n[i-1][j]+n[i+1][j]+n[i][N-2];
					if(j==N-1&&i==N-1) m=n[N-1][N-2]+n[N-2][N-1];
					if(i==N-1&&j!=0&&j!=N-1) m=n[N-2][j]+n[N-1][j-1]+n[N-1][j+1];
					if(i==N-1&&j==0) m=n[N-2][0]+n[N-1][1];
					if(i!=0&&i!=1&&j==0) m=n[i+1][0]+n[i-1][0]+n[i][1];
					if(i!=0&&i!=N-1&&j!=0&&j!=N-1) m=n[i][j+1]+n[i][j-1]+n[i-1][j]+n[i+1][j];
					if(m==0) n[i][j]=-n[i][j];
				}
			}

			for(i=0;i<N;i++)
			{
			    for(j=1-i%2;j<N;j=j+2)//对于j为奇，循环一次
				{
					if(i==0&&j==0) m=n[0][1]+n[1][0];
					if(j!=0&&j!=N-1&&i==0) m=n[0][j-1]+n[0][j+1]+n[1][j];
					if(j==N-1&&i==0) m=n[0][N-2]+n[1][N-1];
					if(j==N-1&&i!=0&&i!=N-1) m=n[i-1][j]+n[i+1][j]+n[i][N-2];
					if(j==N-1&&i==N-1) m=n[N-1][N-2]+n[N-2][N-1];
					if(i==N-1&&j!=0&&j!=N-1) m=n[N-2][j]+n[N-1][j-1]+n[N-1][j+1];
					if(i==N-1&&j==0) m=n[N-2][0]+n[N-1][1];
					if(i!=0&&i!=1&&j==0) m=n[i+1][0]+n[i-1][0]+n[i][1];
					if(i!=0&&i!=N-1&&j!=0&&j!=N-1) m=n[i][j+1]+n[i][j-1]+n[i-1][j]+n[i+1][j];
					if(m==0) n[i][j]=0-n[i][j];
				}
			}

			if(l==5)//记录初始比例为0.005时，自旋比随步数的演化
			{
			x=0;
		    for(i=0;i<N;i++)
			{
			    for(j=0;j<N;j++)
				{
				    if(n[i][j]==1) x++;
				}
			}
		    x=x/(N-1)/(N-1);
		    printf("%f\t%f\n",(double)k,x);
		    fprintf(p2,"%f\t%f\n",(double)k,x);
			}

			if(l==400)//记录初始比例为0.4时，自旋比随步数的演化
			{
			x=0;
		    for(i=0;i<N;i++)
			{
			    for(j=0;j<N;j++)
				{
				    if(n[i][j]==1) x++;
				}
			}
		    x=x/(N-1)/(N-1);
		    printf("%f\t%f\n",(double)k,x);
		    fprintf(p3,"%f\t%f\n",(double)k,x);
			}

			if(l==900)//记录初始比例为0.9时，自旋比随步数的演化
			{
			x=0;
		    for(i=0;i<N;i++)
			{
			    for(j=0;j<N;j++)
				{
				    if(n[i][j]==1) x++;
				}
			}
		    x=x/(N-1)/(N-1);
		    printf("%f\t%f\n",(double)k,x);
		    fprintf(p4,"%f\t%f\n",(double)k,x);
			}
		}


		x=0;//记录每个初始比的演化结果
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(n[i][j]==1) x++;
			}
		}
		x=x/(N-1)/(N-1);
		printf("%f\t%f\n",r,x);
		fprintf(p,"%f\t%f\n",r,x);
		
		
		if(l==900)//记录初始比为0.9的最终矩阵的矩阵元
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
					printf("%d\t",n[i][j]);
					fprintf(p1,"%d\t",n[i][j]);
				}
				printf("\n");
				fprintf(p1,"\n");
			}
		}
		
	}
	fclose(p);
	fclose(p1);
	fclose(p2);
	fclose(p3);
	fclose(p4);
}



double rands()                    /* 产生随机数 */
  {     
	static long int z,i=0;
        double x;
        if(i==0){
       time_t rawtime;                  /* 调用此函数时需要加上头文件#include<time.h> */
        time(&rawtime);               /* 取当前时间为种子值 */
       z=rawtime;
        i++;}    /* z为static变量，只在第一次调用时初始化 */
      z=16807*(z%127773)-2836*(z/127773);
      if(z<0) z=z+2147483647;
      x=(double)z/2147483647;
      return(x);

   }
