#pragma once
#include"BinTree.h"

#define ElemTypeQueue BinNode

typedef struct LinkNode       //链表
{
          ElemTypeQueue data;      //数据域
          struct LinkNode* next;  //指针域
}LinkNode;

typedef struct LinkQueue      //链式队列
{
          LinkNode* front;    //头指针
          LinkNode* rear;     //尾指针
}LinkQueue;

/*链式队列的初始化摧毁与清除功能*/
void InitLinkQueue(LinkQueue* Q);           //链式队列的初始化
void ClearLinkQueue(LinkQueue* Q);           //链式队列的清除
void DestroyLinkQueue(LinkQueue* Q);           //链式队列的摧毁

/*链式队列的显示输出*/
void DisplayLinkQueue(LinkQueue Q);         //链式队列的输出

/*判空以及判满操作*/
BOOL IsQueueEmpty(LinkQueue Q);              //链式队列的判空

/*入队以及出队操作*/
void EnQueue(LinkQueue* Q, ElemTypeQueue x);            //链式队列的入队操作
BOOL DeQueue(LinkQueue* Q, ElemTypeQueue* e);             //链式队列的出队操作

/*其他功能*/
ElemTypeQueue GetTop(LinkQueue Q);             //链式队列获取队头的值
int length(LinkQueue Q);                 //链式队列长度