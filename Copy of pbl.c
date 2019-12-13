#include<stdio.h>
#include<stdlib.h>
struct node
{	int coeff;
	int deg;
	struct node*next;
}*poly1,*poly2,*poly;
int create_node(int t)
{	int n,i;
	struct node*poly,*temp;
	poly=(struct node*)malloc(sizeof(struct node));	
	printf("Enter the highest degree for polynomial %d :",t);
	scanf("%d",&n);
	temp=poly;
	temp->next=NULL;
	printf("Enter the coefficient for degree 0 :");
	temp->deg=0;
	scanf("%d",&(temp->coeff));
	for(i=1;i<=n;i++)
	{	
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		temp->next=NULL;
		printf("Enter the coefficient for degree %d :",i);
		scanf("%d",&(temp->coeff));
		temp->deg=i;		
	}	
	return poly;
}
void print(struct node*temp)
{		printf("polynomial->>");
	while(temp!=NULL)
	{	if(temp->next==NULL)
		{	printf(" %dx^%d",(temp->coeff),(temp->deg));
			temp=temp->next;
		}
		else
		{
		printf(" %dx^%d +",(temp->coeff),(temp->deg));
		temp=temp->next;
		}
	}
	printf("\n");
}
int *add(struct node*temp1,struct node*temp2)
{	struct node*temp,*poly;
	poly=NULL;
	while(temp1!=NULL&&temp2!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=temp1->deg;
			temp->coeff=temp1->coeff+temp2->coeff;	
			temp1=temp1->next;
			temp2=temp2->next;
		
	}
	while(temp1!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=temp1->deg;
			temp->coeff=temp1->coeff;	
			temp1=temp1->next;
		
	}
	while(temp2!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=temp2->deg;
			temp->coeff=temp2->coeff;	
			temp2=temp2->next;
		
	}
	
	return(poly);			
}
int *sub(struct node*temp1,struct node*temp2)
{	struct node*temp,*poly;
	poly=NULL;
	while(temp1!=NULL&&temp2!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=temp1->deg;
			temp->coeff=temp1->coeff-temp2->coeff;	
			temp1=temp1->next;
			temp2=temp2->next;
		
	}
	while(temp1!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=temp1->deg;
			temp->coeff=temp1->coeff;	
			temp1=temp1->next;
		
	}
	while(temp2!=NULL)
	{		if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			temp->deg=0-temp2->deg;
			temp->coeff=temp2->coeff;	
			temp2=temp2->next;
		
	}
	
	return(poly);	
}
int *mult(struct node*temp1,struct node*temp2)
{	struct node*temp,*poly,*rec;
	poly=NULL;
	rec=temp2;
	while(temp1!=NULL)
	{	while(temp2!=NULL)
		{	if(poly==NULL)
			{	poly=temp=(struct node*)malloc(sizeof(struct node));
				temp->next=NULL;
			}
			else
			{	temp->next=(struct node*)malloc(sizeof(struct node));
				temp=temp->next;
				temp->next=NULL;
			}
			if(temp1->deg==0)
			{
				temp->deg=temp2->deg;
				temp->coeff=temp1->coeff*temp2->coeff;	
				temp2=temp2->next;
			 }
			else
			{	if(temp2->deg==0)
				{
				temp->deg=temp1->deg;
				temp->coeff=temp1->coeff*temp2->coeff;	
				temp2=temp2->next;
				}
				else
				{	temp->deg=temp1->deg+temp2->deg;
					temp->coeff=temp1->coeff*temp2->coeff;	
					temp2=temp2->next;
				}
			}	
			
		}
		temp1=temp1->next;
		temp2=rec;
	}
	
	return(poly);
}
int main()
{  int k;
	struct node*poly1,*poly2,*poly;
	do{
	printf("\n 1:CREATE POLYNOMIAL 1\n 2:PRINT POLYNOMIAL 1\n 3:CREATE POLYNOMIAL 2\n 4:PRINT POLYNOMIAL 2\n 5:ADD 2 POLYNOMIAL \n 6:SUBSTRACT 2 POLYNOMIAL\n 7:MULTIPLY 2 POLYNOMIAL\n 8:EXIT\n");
	scanf("%d",&k);
	switch(k)
	{	case 1:poly1=create_node(1);
		break;
		case 2:print(poly1);
		break;
		case 3:poly2=create_node(2);
		break;
		case 4:print(poly2);
		break;
		case 5:poly=add(poly1,poly2);
			   print(poly);
		break;
		case 6:poly=sub(poly1,poly2);
			   print(poly);
		break;
		case 7:poly=mult(poly1,poly2);
			   print(poly);
		break;
		case 8:
		break;
		default: printf("invalid choice");
	}
	  }while(k!=8);
}
