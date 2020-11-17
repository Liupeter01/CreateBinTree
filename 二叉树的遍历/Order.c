#include"Order.h"

void PreOrder(BinTree T)      //先序遍历递归版本
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

void InOrder(BinTree T)                 //中序遍历递归版本
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

void PostOrder(BinTree T)               //后序遍历递归版本
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

void PreOrderStack(BinTree T)			//前序遍历栈版本
{
          _PreOrderStack(T.root);       //调用子函数
}

void _PreOrderStack(BinNode* T)		//前序遍历栈版本子程序
{
          if (T != NULL)         //T不为空
          {
                    BinNode* p = T;
                    LinkStack stack;
                    InitLinkStack(&stack);
                    Push_Stack(&stack, *p);       //将根节点入栈
                    while (!isEmpty(stack))
                    {
                              Pop_Stack(&stack, p);
                              printf("%c",p->data);
                              if (p->rchild != NULL)  //先入右孩子
                              {
                                        Push_Stack(&stack, *(p->rchild));
                              }
                              if (p->lchild != NULL)     //后入左孩子
                              {
                                        Push_Stack(&stack, *(p->lchild));
                              }
                    }
                    DestroyLinkStack(&stack);     // 销毁
          }
}

void InOrderStack(BinTree T)   //中序遍历栈版本
{
          _InOrderStack(T.root);        //调用子程序
}

void _InOrderStack(BinNode* T)   //中序遍历栈版本
{
          if (T != NULL)         //T不为空
          {
                    LinkStack stack;
                    InitLinkStack(&stack);        //模拟栈的初始化操作

                    BinNode* p = T;
                    while (p != NULL || !isEmpty(stack))
                    {
                              if (p != NULL)        //右子树不存在
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
}

void PostOrderStack(BinTree T)			//后序遍历栈版本
{
          _PostOrderStack(T.root);      //调用子函数
}

void _PostOrderStack(BinNode* T)		//后序遍历栈版本子程序
{
          if (T != NULL)         //T不为空
          {

          }
}

void LevelOrder(BinTree T)              //层次遍历
{
          _LevelOrder(T.root);          //调用子程序
}

void _LevelOrder(BinNode* T)			//层次遍历队列子程序
{
          if (T != NULL)         //树不可以为空，增加代码健壮性
          {
                    BinNode* p = T;
                    LinkQueue queue;
                    InitLinkQueue(&queue);        //队列的初始化
                    EnQueue(&queue, *p);          //先将顶点入队
                    while (!IsQueueEmpty(queue))            //判断队列是都为满
                    {
                              DeQueue(&queue, p);
                              printf("%c", p->data);
                              if (p->lchild != NULL)        //左子树不为空
                              {
                                        EnQueue(&queue, *(p->lchild));          //先将顶点入队
                              }
                              if (p->rchild != NULL)        //右子树不为空
                              {
                                        EnQueue(&queue, *(p->rchild));          //先将顶点入队
                              }
                    }
                    DestroyLinkQueue(&queue);
          }
}