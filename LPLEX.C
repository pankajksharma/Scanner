#include<stdio.h>
#include<conio.h>
#include<string.h>

char temp[200],key[4][100]={"int","float","char","double"},keyw[50][50]={"void","#include","conio.h","stdio.h","char","float","for","do","while","main","int","if","printf","getch","getch()"},sym[50]={' ','/','*','+','-','<','>',',','=','#',':',';','"','\'','{','}','(',')','&','!'};

int check(char c)
{
int j,flag;
flag=0;
for(j=0;sym[j]!='\0';j++)
	{
	if(c==sym[j])
		{
		flag=1;
		break;
		}
	}
return flag;
}

int check1()
{
int j,flag;
flag=0;
for(j=0;j<4;j++)
	{
	if(strcmp(temp,key[j])==0)
		{
		flag=1;
		//return flag;
		break;
		}
	if(flag==1)
	break;
	}
return flag;
}

void main()
{
int z,l,i,j,k,f,p,li,m,n,flag,x1,x2,x3,y1,y2,y3,x11;
char c,id[100][100],id1[100][100],str[100][100],com[100][100],num[100][100];
FILE *fp;
clrscr();
fp=fopen("code.c","r");
i=0;j=0;k=0;
while((c=fgetc(fp))!=EOF)
	{
	str[i][j++]=c;
	if(c=='\n')
		{
		str[i][j++]='\0';
		i++;
		j=0;
		}
	}
x1=0;x2=0;x3=0;y1=0;y2=0;y3=0;li=0;
for(l=0;l<i;l++)
{
for(m=0;str[l][m]!='\0';m++)
	{
	if(str[l][m]=='\n')
	li++;
	if(str[l][m]=='i' || str[l][m]=='f' || str[l][m]=='c' || str[l][m]=='d')
		{
		if(m==0)
			{
			k=0;
			while(str[l][m]!=' ')
			temp[k++]=str[l][m++];
			temp[k]='\0';
			}
		}
	if((n=check1())==1)
		{
		k=0;
		while(str[l][m]!=';')
		temp[k++]=str[l][m++];
		temp[k]='\0';
		}
	z=0;
	while(temp[z]!='\0')
		{
		if(temp[z]==',')
			{
			id[x1][y1]='\0';
			x1++;
			y1=0;
			z++;
			}
		if(temp[z]=='=' || temp[z]=='[')
			{
			id[x1][y1]='\0';
			x1++;y1=0;
			while(temp[z]!=',' || temp[z]!='\0')
				{
				z++;
				if(temp[z]=='\0')
				break;
				}
			}
		else
		{
		id[x1][y1++]=temp[z++];
		}
		}
	if(str[l][m]>='0' && str[l][m]<='9')
		{
		flag=0;
		while((n=check(str[l][m]))==0)
		{
		if(str[l][m]<='9' && str[l][m]>='0')
		num[x2][y2++]=str[l][m++];
		else
		{
		printf("Error in Line\t%d\n",li);
		while((n=check(str[l][m]))==0)
		m++;
		flag=1;
		break;
		}
		}
		num[x2][y2++]='\0';
		if(flag==0)
		x2++;
		y2=0;
		}
		//}
	if(str[l][m]=='/')
		{
		if(str[l][m+1]=='/')
			{
			while(str[l][m]!='\n')
			com[x3][y3++]=str[l][m++];
			com[x3][y3++]='\0';
			x3++;
			y3=0;
			}
		if(str[l][m+1]=='*')
			{
			while(str[l][m]=='*' && str[l][m+1]=='/')
			com[x3][y3++]=str[l][m++];
			com[x3][y3++]='\0';
			x3++;
			y3=0;
			}
		}
	}
}
printf("\nIdentifiers\n");
for(l=0;l<x1;l++)
printf("%s\t",id[l]);
printf("\nNumbers\n");
for(l=0;l<x2;l++)
printf("%s\t",num[l]);
printf("\nComments\n");
for(l=0;l<x3;l++)
printf("%s\t",com[l]);
getch();
}