#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

int main(int argc, const char *argv[])
{
	FILE *fp1;
	fp1 = fopen("data.txt","r");
	if(fp1==NULL)
	{
		printf("\n\nCan't find the file, you should input a correct file name!\n\n\n");
		exit(1);
	}
	typedef struct{
		char subnet[20];
		int ipUsed;
		int ipFree;
		int ipPending;
		float percentage;
	} Scope;
	char token,temp[101];
	char systemCommand[101];
	int skipedLine=0, i=0, j=0, numberOfScope=0;
	float totalPercentage;
	for(;;)//skip the line before number of scope
	{
		token = fgetc(fp1);
		if (token == '\n')
		{
			skipedLine++;
		}
		if (skipedLine == 11)break;
	}
	for(;;)//get the number of scope
	{
		token = fgetc(fp1);
		if (((int)token >= 48)&((int)token <= 57))
		{
			temp[i] = token;
			i++;
		}
		if (token == '\n')
		{
			temp[i] = '\0';
			numberOfScope = atoi(temp);		
			break;
		}
	}
	Scope scope[numberOfScope+1];
	skipedLine = 0;
 	for(;;)//skip the line before first scope
	{
		token = fgetc(fp1);
		if (token == '\n')
		{
			skipedLine++;
		}
		if (skipedLine == 1)break;
	}
	for(i = 0; i < numberOfScope; i++)
	{
		for(j=0;;)//get the subnet of this scope
		{
			token = fgetc(fp1);
			if ((((int)token >= 48)&((int)token <= 57))|((int)token == 46))//read number and "."
			{
				temp[j] = token;
				j++;
			}
			if (token == '\n')
			{
				temp[j] = '\0';
				break;
			}
		}
		strcpy(scope[i].subnet,temp);
		for(j=0;;)//get the number of ip in use
		{
			token = fgetc(fp1);
			if (((int)token >= 48)&((int)token <= 57))//read number only
			{
				temp[j] = token;
				j++;
			}
			if (token == '\n')
			{
				temp[j] = '\0';		
				break;
			}
		}
		scope[i].ipUsed = atoi(temp);
		for(j=0;;)//get the number of ip free
		{
			token = fgetc(fp1);
			if (((int)token >= 48)&((int)token <= 57))//read number only
			{
				temp[j] = token;
				j++;
			}
			if (token == '\n')
			{
				temp[j] = '\0';		
				break;
			}
		}
		scope[i].ipFree = atoi(temp);
		for(j=0;;)//get the number of ip pending
		{
			token = fgetc(fp1);
			if (((int)token >= 48)&((int)token <= 57))//read number only
			{
				temp[j] = token;
				j++;
			}
			if (token == '\n')
			{
				temp[j] = '\0';		
				break;
			}
		}
		scope[i].ipPending = atoi(temp);
		scope[i].percentage =((float)(scope[i].ipUsed+scope[i].ipPending)/(scope[i].ipUsed+scope[i].ipFree+scope[i].ipPending));
	}
	printf("*************************************************************\n");
	for(i=0;i<numberOfScope;i++)
	{
		printf("");
		printf("Subnet scope: %s \n",scope[i].subnet);
		printf("	IP used : %d\n",scope[i].ipUsed);
		printf("	IP Free : %d\n",scope[i].ipFree);
		printf("	IP Pending : %d\n", scope[i].ipPending);
		printf("	%f of ip pool have been used.\n",scope[i].percentage);
		itoa(i+1,(temp),10);
		if (scope[i].percentage >= 0.9){
			strcat(temp,".9.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);		
		}
		else if(scope[i].percentage >= 0.8){
			strcat(temp,".8.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.7){
			strcat(temp,".7.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.6){
			strcat(temp,".6.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.5){
			strcat(temp,".5.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.4){
			strcat(temp,".4.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.3){
			strcat(temp,".3.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.2){
			strcat(temp,".2.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		else if(scope[i].percentage >= 0.1){
			strcat(temp,".1.bat");
			strcpy(systemCommand,".\\Action\\");
			strcat(systemCommand,temp);
			system(systemCommand);
		}
		printf("=============================================================\n");
	}
	return 0;
}
