#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 200
main()
    {
    double x,y,u,r;
    double rands();
    int n[N][N];//����һ�������θ���
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
	for(l=0;l<=1000;l++)//�����ʼ����K=L/1000
	{
		r=(double)l/1000;
		for(i=0;i<N;i++)//��ʼ������
		{
			for(j=0;j<N;j++)
			{
				u=rands();
				if(u<r) n[i][j]=1;
				else n[i][j]=-1;
			}
		}
		for(k=0;k<2000;k++)//���岽��
		{
		    for(i=0;i<N;i++)
			{
			    for(j=i%2;j<N;j=j+2)//����jΪż��ѭ��һ��
				{
					if(i==0&&j==0) m=n[0][1]+n[1][0];//�������Ԫ���ھ�
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
			    for(j=1-i%2;j<N;j=j+2)//����jΪ�棬ѭ��һ��
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

			if(l==5)//��¼��ʼ����Ϊ0.005ʱ���������沽�����ݻ�
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

			if(l==400)//��¼��ʼ����Ϊ0.4ʱ���������沽�����ݻ�
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

			if(l==900)//��¼��ʼ����Ϊ0.9ʱ���������沽�����ݻ�
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


		x=0;//��¼ÿ����ʼ�ȵ��ݻ����
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
		
		
		if(l==900)//��¼��ʼ��Ϊ0.9�����վ���ľ���Ԫ
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



double rands()                    /* ��������� */
  {     
	static long int z,i=0;
        double x;
        if(i==0){
       time_t rawtime;                  /* ���ô˺���ʱ��Ҫ����ͷ�ļ�#include<time.h> */
        time(&rawtime);               /* ȡ��ǰʱ��Ϊ����ֵ */
       z=rawtime;
        i++;}    /* zΪstatic������ֻ�ڵ�һ�ε���ʱ��ʼ�� */
      z=16807*(z%127773)-2836*(z/127773);
      if(z<0) z=z+2147483647;
      x=(double)z/2147483647;
      return(x);

   }
