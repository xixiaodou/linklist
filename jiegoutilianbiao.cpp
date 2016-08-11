
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
	printf("  *****[1]建立学生信息链表     [2]浏览信息******** \n");
	printf("  *****[3]查询学生信息         [4]添加学生信息**** \n");
	printf("  *****[5]删除学生信息          ****************** \n");
	printf("*********************************************************\n");
	printf("请选择选项->");
	scanf("%d,&select");
	switch(select)
	{      
	case 1:
		mylist=Create_L();break;
	case 2:
		View_L(mylist);break;
	case 3:
		printf("请输入学生的学号进行查询%16d:\n",i);
		scanf("%d",&i);
		Find_L(mylist ,i);break;
	case 4:
		Add_L(mylist);break;
    case 5:
		printf("请输入要删除的位置为第%d前面:\n",i);
		scanf("%d",&i);
		Delete_L(mylist ,i);break;
}
}



struct LNode *Create_L() // 输入n个学生信息，建立带头结点的单链表L 
{
	int i;
	elemtype e;
	LinkList s;
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	if(L==NULL){
	printf("error");
	}
	printf("请输入学生的个数%d:\n",i);
	scanf("%d",&i);
for(int i=0;i<n;i++) 
	{ 
		printf("第%d个学生的信息\n姓名\t学号\t年龄\t性别\n",i+1);
		s=(LinkList)malloc(sizeof(LNode)); // 生成新结点 
		scanf("%s%d%d %s ",e.name,&e.num,&e.age,e.sex); //输入学生信息 
		s->data.age=e.age;
		strcpy(s->data.sex,e.sex);
	    strcpy(s->data.name,e.name);
     	s->data.num=e.num ;
		s->next=L->next; 
		L->next=s; //插入到表头
	}
	return mylist;
}


void View_L(LinkList &L) // 遍历输出整个线性表
{
	LinkList s;
	s=L->next;
	printf("学生的信息\nn姓名\t学号\t年龄\t性别\n");
	while(s)
	{
		printf("%s%d%d %s ",s->data.name,&s->data.num,&s->data.age,s->data.sex); //输入学生信息 
		s=s->next;
	}
}


void Delete_L(LinkList &L,int i) // 在带头结点的单链表L中，删除第i个学生的信息,并输出删除的信息
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
			p->next=s->next; // 删除操作 
			free(s); 
		}
		p=s;
		s=s->next;
	}
//释放结点 
	printf("删除的信息为: 姓名%10S\t学号%16d\t,年龄%10d\t性别%10s\n",e.name,e.num,e.age,e.sex);

}

void Add_L(LinkList &L)//插入学生信息
{
	elemtype e;
	LinkList p,s;
	p=L;
	if(p->next!=NULL)
		p=p->next;
	else
		printf("学生的信息\n姓名\t学号\t年龄\t性别\n");	
	s=(LinkList)malloc(sizeof(LNode)); 
	scanf("%s%d%d %s ",e.name,&e.num,&e.age,e.sex); //输入学生信息
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
	printf("该学生的信息不存在\n");
 }











/*
struct LNode *Create_list()//建立一个带头节点的单链表//LinkList Create_list()
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
	printf("请输入创建数据的个数：");
	scanf("%d",&len);
	for(i=0;i<len;++i)
	{
	printf("第%d个数字为：",i+1);
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
