#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    char a[100000];
    getchar();
    for(int i=0;i<n;i++)
    {
        // getchar();
        gets(a);
        int len=strlen(a);
        int k=0;
        for(int j=0;j<=len;j++)
        {
            if(a[j]>='0' && a[j]<='9') {
                k++;
            }
            
        }
        printf("%d\n",k);
    }
    system("pause");
    return 0;
}