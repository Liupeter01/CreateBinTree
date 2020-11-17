#include"Order.h"

void PreOrder(BinTree T)      //先序遍历
{
          _PreOrder(T.root);  //调用子模块
}

void _PreOrder(BinNode* T)     //先序遍历子模块
{
          if (T != NULL)
          {
                    printf("%c", T->data);        //先输出双亲节点的值
                    _PreOrder(T->lchild);          //先去左子树
                    _PreOrder(T->rchild);          //再去右子树
          }
}

void InOrder(BinTree T)                 //中序遍历
{
          _InOrder(T.root);    //调用子模块
}

void _InOrder(BinNode* T)                 //中序遍历子模块
{
          if (T != NULL)
          {
                    _InOrder(T->lchild);          //先去左子树
                    printf("%c", T->data);        //先输出节点的值
                    _InOrder(T->rchild);          //再去右子树
          }
}

void PostOrder(BinTree T)               //后序遍历
{
          _PostOrder(T.root);  //调用子模块7
}

void _PostOrder(BinNode* T)             //后序遍历子模块
{
          if (T != NULL)
          {
                    _PostOrder(T->lchild);          //先去左子树
                    _PostOrder(T->rchild);          //再去右子树
                    printf("%c", T->data);        //先输出节点的值
          }
}

void InOrderStack(BinTree T)   //中序遍历栈版本
{
          _InOrderStack(T.root);        //调用子程序
}

void _InOrderStack(BinNode* T)   //中序遍历栈版本
{
          LinkStack stack;
          InitLinkStack(&stack);        //模拟栈的初始化操作

          BinNode* p = T;
          while (p!=NULL || !isEmpty(stack))      
          {
                    if (p!=NULL)        //右子树不存在
                    {
                              Push_Stack(&stack, *p);
                              p = p->lchild;
                    }
                    else
                    {
                              BinNode temp;
                              Pop_Stack(&stack, &temp); //开始出栈
                              printf("%c", temp.data);
                              BinNode* pointer = &temp;
                              p = pointer->rchild;    //访问右子树
                    }
          }
          DestroyLinkStack(&stack);     //模拟栈的摧毁
}


///*层次遍历*/
//void LevelOrder(BiTree T)
//{
//          LinkQueue queue;
//          BiTree P = T;
//          EnQueue(&queue, *P);  //先将根节点入队
//          while (!IsQueueEmpty(queue))   //链式队列不为空
//          {
//                    DeQueue(&queue, P);                //将节点出队
//                    printf("%d", P->data);
//                    if (P->lchild != NULL)         //将左节点入队 
//                    {
//                              EnQueue(&queue, *(P->lchild));
//                    }
//                    if (P->rchild != NULL)        //将右节点入队 
//                    {
//                              EnQueue(&queue, (*P->rchild));
//                    }
//          }
//}