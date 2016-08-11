
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define Len  15
typedef struct{
char name[Len];
int num;
int age;
char sex[5];
}elemtype;
typedef struct LNode{
	elemtype data;
	struct LNode *next;
}LNode,*LinkList;
struct LNode *Create_L();
void View_L(LinkList L);
void Find_L(LinkList &L,int i);
void Add_L(LinkList &L);
void Delete_L(LinkList &L,int i);

void main()
{
	int i,select;
	LinkList mylist;
while(1)
{
	printf("*********************************************************\n");
	printf("  *****[1]����ѧ����Ϣ����     [2]�����Ϣ******** \n");
	printf("  *****[3]��ѯѧ����Ϣ         [4]���ѧ����Ϣ**** \n");
	printf("  *****[5]ɾ��ѧ����Ϣ          ****************** \n");
	printf("*********************************************************\n");
	printf("��ѡ��ѡ��->");
	scanf("%d,&select");
	switch(select)
	{      
	case 1:
		mylist=Create_L();break;
	case 2:
		View_L(mylist);break;
	case 3:
		printf("������ѧ����ѧ�Ž��в�ѯ%16d:\n",i);
		scanf("%d",&i);
		Find_L(mylist ,i);break;
	case 4:
		Add_L(mylist);break;
    case 5:
		printf("������Ҫɾ����λ��Ϊ��%dǰ��:\n",i);
		scanf("%d",&i);
		Delete_L(mylist ,i);break;
}
}



struct LNode *Create_L() // ����n��ѧ����Ϣ��������ͷ���ĵ�����L 
{
	int i;
	elemtype e;
	LinkList s;
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	if(L==NULL){
	printf("error");
	}
	printf("������ѧ���ĸ���%d:\n",i);
	scanf("%d",&i);
for(int i=0;i<n;i++) 
	{ 
		printf("��%d��ѧ������Ϣ\n����\tѧ��\t����\t�Ա�\n",i+1);
		s=(LinkList)malloc(sizeof(LNode)); // �����½�� 
		scanf("%s%d%d %s ",e.name,&e.num,&e.age,e.sex); //����ѧ����Ϣ 
		s->data.age=e.age;
		strcpy(s->data.sex,e.sex);
	    strcpy(s->data.name,e.name);
     	s->data.num=e.num ;
		s->next=L->next; 
		L->next=s; //���뵽��ͷ
	}
	return mylist;
}


void View_L(LinkList &L) // ��������������Ա�
{
	LinkList s;
	s=L->next;
	printf("ѧ������Ϣ\nn����\tѧ��\t����\t�Ա�\n");
	while(s)
	{
		printf("%s%d%d %s ",s->data.name,&s->data.num,&s->data.age,s->data.sex); //����ѧ����Ϣ 
		s=s->next;
	}
}


void Delete_L(LinkList &L,int i) // �ڴ�ͷ���ĵ�����L�У�ɾ����i��ѧ������Ϣ,�����ɾ������Ϣ
{
	elemtype e;
	LinkList p,s;
	p=L;
	s=L->next;
	while(s) 
	{
		if(s->data.num==i) 
		{
			e.age=s->data.age;
			strcpy(e.sex,s->data.sex);
			strcpy(e.name,s->data.name);
			e.num=s->data.num;
			p->next=s->next; // ɾ������ 
			free(s); 
		}
		p=s;
		s=s->next;
	}
//�ͷŽ�� 
	printf("ɾ������ϢΪ: ����%10S\tѧ��%16d\t,����%10d\t�Ա�%10s\n",e.name,e.num,e.age,e.sex);

}

void Add_L(LinkList &L)//����ѧ����Ϣ
{
	elemtype e;
	LinkList p,s;
	p=L;
	if(p->next!=NULL)
		p=p->next;
	else
		printf("ѧ������Ϣ\n����\tѧ��\t����\t�Ա�\n");	
	s=(LinkList)malloc(sizeof(LNode)); 
	scanf("%s%d%d %s ",e.name,&e.num,&e.age,e.sex); //����ѧ����Ϣ
	s->next=p;p->next=NULL;
	strcpy(s->data.name,e.name);
	strcpy(s->data.sex,e.sex);
	s->data.num=e.num;
	s->data.age=e.age;
	
}

void Find_L(LinkList &L,int i)
 {
	elemtype e;
	LinkList s;
	s=L->next;
	while(s){
		if(s->data.num==i)
		{
			e.num=s->data.num;
			e.age=s->data.age;
			strcpy(e.sex,s->data.sex);
			strcpy(e.name,s->data.name);
			printf("%s%d%d %s ",e.name,&e.num,&e.age,e.sex);
		}
		else s=s->next;
	}
	printf("��ѧ������Ϣ������\n");
 }











/*
struct LNode *Create_list()//����һ����ͷ�ڵ�ĵ�����//LinkList Create_list()
{
	int len,i,vai;
	LinkList p;
	LinkList head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	p=head;
	if(head==NULL)
	{
	printf("error");
	}
	printf("�����봴�����ݵĸ�����");
	scanf("%d",&len);
	for(i=0;i<len;++i)
	{
	printf("��%d������Ϊ��",i+1);
	scanf("%d",&vai);
	LinkList s=(LinkList)malloc(sizeof(LNode));
    if(s==NULL)
	{
      	printf("error");
	}
	 s->data=vai;
	 s->next=p->next;
     p->next=s;
	 p=p->next;
	}
	return head;}*/
