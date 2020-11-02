#include<stdio.h>
void judge(char a,char b)
{
    if(a=="Rock")
    {
        if(b=="Rock")
            printf("Tie");
        else if(b=="Scissors")
            printf("Player1");
        else if(b=="Paper")
            printf("Player2");
    }
    if(a=="Scissors")
    {
        if(b=="Rock")
            printf("Player2");
        else if(b=="Scissors")
            printf("Tie");
        else if(b=="Paper")
            printf("Player1");
    }
    if(a=="Paper")
    {
        if(b=="Rock")
            printf("Player1");
        else if(b=="Scissors")
            printf("Player2");
        else if(b=="Paper")
            printf("Tie");
    }
}
int main(void)
{
    int n;
    void judge(char a,char b);
    judge("Rock","Scissors");
    return 0;
}