#include<stdio.h>
#include <string.h>

void process(FILE*);

int main()
{
    float crReturn=1.0;
    float crPercent;
    float temp;
    float result=0;
    float crPeriod;
    char*tempString;
    char*resultString="\0";
    FILE*resultFile=fopen("result.txt","w");
    printf("\n------------------------------CompenDel\n");

    while(true)
    {
        printf("\nTo finish, when you request the refund, enter 0\n");
        printf("Enter the refund amount: ");
        scanf("%f",&crReturn);
        if(!crReturn)
        {
            break;
        }
        printf("Enter the percentage of the loan: ");
        scanf("%f",&crPercent);
        printf("Enter the period of delay: ");
        scanf("%f",&crPeriod);
        temp=crReturn/100*crPercent/30*crPeriod;
        result+=temp;
        fprintf(resultFile,"%.2f/100*%.2f/30*%.0f=%.2f\r\n",crReturn,crPercent,crPeriod,temp);
        if(result==temp)
        {
            sprintf(tempString,"%.2f\0",temp);
        }
        else
        {
            sprintf(tempString,"+%.2f\0",temp);
        }
        strncat(resultString,tempString,strlen(tempString));
    }
    if(result!=temp)
    {
        fprintf(resultFile,"\r\n%s",resultString);
        fprintf(resultFile,"=%.2f\r\n",result);
    }

    printf("\n------------------------------CompenDel\n");
    getchar();
    getchar();
    return 0;
}
