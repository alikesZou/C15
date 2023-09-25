#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//定义结点，其中为编号和密码 
typedef struct Lnode{
	ElemType code;
	int number;
	struct Lnode *next;
}Lnode,*LinkList;

//初始化链表
void init_Lnode(LinkList &L){
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
} 
//存入数据(只从第二个元素开始)
void save_Lnode(LinkList &L,int n){
	LinkList p = L;
	L->number = 1;
	scanf("%d",L->code);
	for(int i = 2;i <= n;i++){
		LinkList s;
		init_Lnode(s);
		scanf("%d",&s->code);
		s->number = i;
		p->next = s;
		p = p->next;
	}
	
	
//	printf("1"); 
} 
//将L链表构成循环
void cir_Lnode(LinkList &L){
	LinkList p = L;
	while(p->next) p = p->next;
	p->next = L;
//	printf("1");
} 
//删除p所指向的元素（结点）
void delete_Lnode(LinkList &L,LinkList &p){
	LinkList p1 = L;
	while(p1->next != p) p1 = p1->next;
	p1->next = p->next;
//	free(p);
	p = p->next;

} 
//在循环链表中指,输出，并删除所指元素 
int goal_Lnode(LinkList &L,LinkList &p,int goal){
	for(int i = 0;i < goal;i++){
		p = p->next;
	}
	printf("%d ",p->number);
	goal = p->code;
	delete_Lnode(L,p);
	return goal;
} 


int main(){
	int n = 0;
	int goal = 0;
	scanf("%d%d",&n,&goal);
	LinkList L;	init_Lnode(L);
	LinkList p;// init_Lnode(p);//此指针用来作为箭头 
	p = L;
	save_Lnode(L,n);
 
	cir_Lnode(L);//将链表循环化 
	
//	for(int i = 0;i < n;i++){
//		goal = goal_Lnode(L,p,goal);
//	}
//	goal = 2;
//	goal = goal_Lnode(L,p,goal);
//	printf("%d",goal);
	for(int i = 0;i < n;i++){
		printf("%d %d\n",p->code,p->number);
		p = p->next;
	}
}

