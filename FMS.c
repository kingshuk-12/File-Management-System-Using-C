#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nd
{
	char name[50];
	struct nd *next,*under;
}node;
node *root=NULL,*ptr=NULL;
char sub2[100],r[25];
void ls()
{
	node *temp;
	temp=ptr;
	if(strcmp(temp->name,"\0")==0)
	temp=temp->next;
	if(temp==NULL)
	return;
	else
	{
		while(temp!=NULL)
		{       if(temp->next==NULL)
				printf("%s\n",temp->name);
			else
				printf("%s\t",temp->name);
			temp=temp->next;
		}
	}
}
void mkdir(char a[])
{
	node *new,*temp;
	temp=ptr;
	new=(node*)malloc(sizeof(node));
	new->next=new->under=NULL;
	strcpy(new->name,a);
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
}
void cd(char a[])
{
	int f=0;
	node *temp,*new;
	temp=ptr;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,a)==0)
		{
			if(temp->under!=NULL)
				ptr=temp->under;
			else
			{
				new=(node*)malloc(sizeof(node));
				new->next=new->under=NULL;
				strcpy(new->name,"\0");
				temp->under=new;
				ptr=new;
			}
			f=1;
			break;
		}
		temp=temp->next;
	}
	if(f!=1)
	{
		node *nm;
		new=(node*)malloc(sizeof(node));
		new->next=new->under=NULL;
		strcpy(new->name,a);
		temp=ptr;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
		nm=(node*)malloc(sizeof(node));
		strcpy(nm->name,"\0");
		nm->next=nm->under=NULL;
		new->under=nm;
		ptr=nm;
	}
	strcat(sub2,"/");
	strcat(sub2,a);
}
void touch(char a[])
{
	mkdir(a);
}
void tree(int f,node *temp,int b)
{
	int i;
	if(temp==NULL)
		return;
	else
	{
		if(b>0||f==0)
		{
			for(i=0;i<f;i++)
			printf("|  ");
			printf("|");
		}
		if(temp==root)
			temp=temp->next;
		if(b>0||f==0)
			printf("---%s\n",temp->name);
		b++;
		tree(f+1,temp->under,0);
		tree(f,temp->next,b);
	}
}
void main()
{
	char s[100],sub[50];
	int x,i,p;
	node *first;
	strcpy(sub2,"sem3dsl@b~/System/ROOT");
	strcpy(r,sub2);
	clrscr();
	first=(node*)malloc(sizeof(node));
	strcpy(first->name,"\0");
	first->next=first->under=NULL;
	root=ptr=first;
	while(1)
	{
		printf("%s $ ",sub2);
		for(i=0;i<50;i++)
		{
			scanf("%c",&s[i]);
			if(s[i]=='\n')
				break;
		}
		s[i]='\0';
		for(i=0;i<=5;i++)
		sub[i]=s[i];
		sub[i]='\0';
		if(strcmp(s,"cd..")==0)
		{
			ptr=root;
			strcpy(sub2,r);
			x=6;
		}
		else
		{
			if(strcmp(s,"ls")==0)
			x=1;
			else if(strstr(sub,"mkdir ")!=NULL)
			{
				x=2;
				p=0;
				for(i=6;s[i]!='\0';i++)
				sub[p++]=s[i];
				sub[p]='\0';
			}
			else if(strstr(sub,"cd ")!=NULL)
			{
				x=3;
				p=0;
				for(i=3;s[i]!='\0';i++)
				sub[p++]=s[i];
				sub[p]='\0';
			}
			else if(strstr(sub,"touch ")!=NULL && strstr(s,".")!=NULL)
			{
				x=4;
				p=0;
				for(i=6;s[i]!='\0';i++)
				sub[p++]=s[i];
				sub[p]='\0';
			}
			else if(strcmp(s,"exit")==0)
				x=5;
			else if(strcmp(s,"tree")==0)
				x=7;
			else
				x=0;
		}
		switch(x)
		{
			case 1:ls();
				break;
			case 2:mkdir(sub);
				break;
			case 3:cd(sub);
				break;
			case 4:touch(sub);
				break;
			case 5:exit(0);
			case 6:break;
			case 7:printf("ROOT\n");
				if(first->next==NULL && first->under==NULL)
					continue;
				else
					tree(0,first,0);
				break;
			default:printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n",s);

		}
	}
}
