#include"LinkStack.h"

void InitLinkStack(LinkStack* lstack)	//初始化链式栈
{
		  (*lstack) = (LinkStack)malloc(sizeof(StackNode));	//头结点
		  assert((*lstack) != NULL);
		  (*lstack)->next = NULL;
}

void DestroyLinkStack(LinkStack* lstack)	//摧毁链式栈
{
		  free((*lstack));
		  (*lstack)->next = NULL;
}

BOOL isEmpty(LinkStack lstack)		// 判空操作
{
		  return lstack->next == NULL;			  //只有一个头结点
}

int Stacklength(LinkStack lstack)	//求栈的大小
{
		  StackNode* p = lstack->next;
		  int counter = 0;
		  while (p != NULL)
		  {
					counter++;
					p = p->next;
		  }
		  return counter;
}

ElemTypeStack GetStackTop(LinkStack lstack)//获得栈顶元素
{
		  return (lstack->next->data);
}

void Push_Stack(LinkStack* lstack, ElemTypeStack data)	//入栈
{
		  LinkStack s = (LinkStack)malloc(sizeof(StackNode));					//创建新的结点
		  assert(s != NULL);
		  s->data = data;
		  s->next = NULL;
		  if ((*lstack)->next == NULL)			  //只有一个头结点
		  {
					StackNode* head = (*lstack);
					head->next = s;
		  }
		  else
		  {
					StackNode* head = (*lstack);
					s->next = head->next;
					head->next = s;
		  }
}

void Pop_Stack(LinkStack* lstack, ElemTypeStack* x)	//出栈
{
		  if (!isEmpty(*lstack))				  //非空状态
		  {
					StackNode* temp = (*lstack)->next;		//出栈元素
					*x = temp->data;	//取出数据
					if (temp->next == NULL)		  //栈只有一个元素了
					{
							  (*lstack)->next = NULL;
					}
					else
					{
							  (*lstack)->next = temp->next; //跳过出栈元素
					}
					free(temp);
		  }
		  else
		  {
					return;
		  }
}