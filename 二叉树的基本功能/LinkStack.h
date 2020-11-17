#pragma once
#include"BinTree.h"

#define ElemTypeStack BinNode

typedef struct StackNode
{
		  ElemTypeStack data;						  //数据域
		  struct StackNode* next;		//指针域
}StackNode,*LinkStack;

void InitLinkStack(LinkStack* lstack);	//初始化链式栈
void DestroyLinkStack(LinkStack* lstack);	//摧毁链式栈
BOOL isEmpty(LinkStack lstack);		// 判空操作
int Stacklength(LinkStack lstack);	//求栈的大小
ElemTypeStack GetStackTop(LinkStack lstack);//获得栈顶元素

/*出栈入栈操作*/
void Push_Stack(LinkStack*lstack, ElemTypeStack data);	//入栈
void Pop_Stack(LinkStack* lstack, ElemTypeStack*x);	//出栈