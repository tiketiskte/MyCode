#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int M,N;
    scanf("%d %d",&M,&N);
    int on[M];
    for(int i=0;i<M;i++)
        on[i]=0;
    for(int i=2;i<=M;i++)
    {
        for(int j=i;j<=N;j++)
        {
            if(j%i==0)
            {
                if(on[j-1]==0)
                    on[j-1]=1;
                else 
                    on[j-1]=0;
            }
        }
    }
    int flag = 1;
    for(int i=0;i<M;i++)
    {
        if(on[i]==0) {
                if(flag) {
                printf("%d",i+1);
                flag = 0;
            } else {
                printf(",%d,",i+1);
            }
        }
        
    }
    system("pause");
    return 0;
}