#include"Order.h"

void PostOrderStack(BinTree T)			//后序遍历栈版本
{
          _PostOrderStack(T.root);      //调用子函数
}

void _PostOrderStack(BinNode* T)		//后序遍历栈版本子程序
{
          if (T != NULL)         //T不为空
          {
                    LinkStack stack;
                    InitLinkStack(&stack);        //模拟栈的初始化操作
                    SpecialNode sn;     //新建结点
                    sn.node = T;
                    while (!isEmpty(stack) || sn.node != NULL)
                    {
                              if (sn.node != NULL)
                              {
                                        sn.tag = L;
                                        Push_Stack(&stack, sn);
                                        sn.node = sn.node->lchild;      //左子树
                              }
                              else
                              {
                                        Pop_Stack(&stack, &sn);       //获取栈顶元素
                                        if (sn.tag == L && sn.node->rchild != NULL)//左子树，还需要继续访问右子树且结点右子树不为空
                                        {
                                                  sn.node = sn.node->rchild;                    //寻找右子树
                                                  sn.tag = R;         //修改状态标识
                                                  Push_Stack(&stack, sn);       //将父节点再次入栈
                                        }
                                        else
                                        {
                                                  printf("%c", sn.node->data);
                                        }
                              }
                    }
                    DestroyLinkStack(&stack);
          }
}