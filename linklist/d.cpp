#include<stdio.h>
#include<malloc.h>
typedef struct LNode
{
	int data;
    struct LNode *next;
}LNode,*LinkList;//��������
struct LNode *Create_list();
void View_list (LinkList head);
void Change_list(LinkList &head);
void Merger_list(LinkList &head,LinkList &Lb,LinkList &Lc);
void Merger_list2(LinkList &head,LinkList &Lb,LinkList &Lc);
int main()
{
	LinkList Lb,Lc,head;
	Lc=NULL;
	//�ȼ���struct LNode *head
	int i;
while (1){
	printf("*****1.��������           2.��������*******************************\n");
	printf("*****3.����               4.���������ǵݼ��������ϲ���һ���ǵݼ�������\n");
	printf("*****5.���������ǵ����������ϲ���һ���ǵ���������**************\n");

	printf("********************************************;\n");
	printf("������ѡ�����ţ�");
	scanf("%d",&i);
	switch (i){
		case 1:printf("��������");
			  head= Create_list();break;
			case 2:
                View_list(head);break;
			case 3:
				Change_list(head);break;
			case 4:
				printf("����ָʾ��������ǵݼ�������\n");
				head= Create_list();
			    Lb= Create_list();
				Merger_list(head,Lb,Lc);
                View_list(head);break;
            case 5:
				printf("����ָʾ��������ǵ݉�������\n");
				head= Create_list();
				Lb= Create_list();
				Merger_list2(head,Lb,Lc);
                View_list(head);break;

			}
		}

	return 0;

}



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
	return head;
}
void View_list(LinkList head){//��������
if (head==NULL)
printf("error");
	LinkList p;
	p=head->next;
	printf("����������Ϊ��\n");
   while (p)
	{
	   printf("%4d",p->data);
	   p=p->next;
	}
   printf("\n");
}
void Change_list(LinkList &head){//����
	LinkList p,s;
	p=head->next;
	head->next=NULL;
	while (p){
		s=p;
		p=p->next;
		s->next=head->next;
		head->next=s;
	}
	View_list(head);
}

void Merger_list(LinkList &head,LinkList &Lb,LinkList &Lc){
//�ϲ�
	LinkList Pa,Pb,Pc,s;
	Pa=head->next;
	Pb=Lb->next;
	Lc=Pc=head;
	while (Pa&&Pb){//����ǵݼ�
		if (Pa->data<Pb->data){
		s=Pa;
		Pa=Pa->next;
		}
		else{
		s=Pb;
		Pb=Pb->next;
		}
		s->next=Pc->next;
		Pc->next=s;
		Pc=Pc->next;
	}
	if (Pa)
		Pc->next=Pa;
	else
		Pc->next=Pb;
	free(Lb);

}

void Merger_list2(LinkList &head,LinkList &Lb,LinkList &Lc){
//�ϲ�
	LinkList Pa,Pb,Pc,s;
	Pa=head->next;
	Pb=Lb->next;
	Lc=Pc=head;
	while (Pa&&Pb){//����ǵ�
		if (Pa->data>=Pb->data)
		{
	    	s=Pa;
	    	Pa=Pa->next;
		}
		else
		{
		    s=Pb;
	    	Pb=Pb->next;
		}
		s->next=Pc->next;
		Pc->next=s;
		Pc=Pc->next;
	}
	if (Pa)
		Pc->next=Pa;
	else
		Pc->next=Pb;
	free(Lb);
}