#include"BinTree.h"

BinNode* CreateBinNode(ElemType x)             //二叉树的结点创建函数
{
		  BinNode* s = (BinNode*)malloc(sizeof(BinNode));
		  assert(s != NULL);
		  s->data = x;
		  s->lchild = s->rchild = NULL;
		  return s;
}

void InitBinTree(BinTree* T, ElemType stopflag)        //二叉树的初始化
{
		  T->root = NULL;	  //初始化
		  T->stopflag = stopflag;				  //以stopflag作为程序的结束符号
}

void DestroyBinTree(BinNode* p)         //二叉树的销毁
{
		  if (p->lchild != NULL && p->rchild != NULL)
		  {
					BinNode* ptemp = p;
					DestroyBinTree(p->lchild);
					DestroyBinTree(p->rchild);
					free(ptemp);
		  }
}

void ClearBinTree(BinTree* T)                    //二叉树的清除操作
{

}

void CreateBinTreeByString(BinTree* T, char* str)          //根据字符串创建
{
		  CreateBiTNode(T, &(T->root), str);
}

void CreateBinTree(BinTree* T)          //二叉树的创建
{
		  printf("请输入二叉树创建的序列：>");
		  CreateBiTNode(T, &(T->root), NULL);
}

//二叉树创建的核心递归函数，修改指针必须传入二级指针
//当传入的str为NULL的时候采用手动输入，非NULL为自动2
static void CreateBiTNode(BinTree* T, BinNode** p,const char *str)      
{
		  ElemType data = 0;	  //输入的数据
		  if (str == NULL)	  //手动输入
		  {
					scanf("%c", &data);
					if (data != T->stopflag)
					{
							  *p = CreateBinNode(data);
							  CreateBiTNode(T, &((*p)->lchild), NULL);
							  CreateBiTNode(T, &((*p)->rchild), NULL);
					}
		  }
		  else
		  {
					static int counter = 0;
					data = str[counter++];	//到下一个字符
					if (data != T->stopflag && data != '\0')
					{
							  *p = CreateBinNode(data);
							  CreateBiTNode(T, &((*p)->lchild), str);
							  CreateBiTNode(T, &((*p)->rchild), str);
					}
		  }
}

int SizeBinTree(BinTree T)           //二叉树的结点个数
{
		  return _SizeBinTree(T.root);
}

int _SizeBinTree(BinNode* p)         //结点个数子程序
{
		  if (p==NULL)			//到达了一个不存在的空结点返回0
		  {
					return 0;
		  }
		  else
		  {
					return _SizeBinTree(p->lchild) + _SizeBinTree(p->rchild) + 1;
		  }
}

int HeightBinTree(BinTree T)           //二叉树的高度
{
		  return _HeightBinTree(T.root);
}

int _HeightBinTree(BinNode* T)          //二叉树的高度子函数
{
		  if (T == NULL)
		  {
					return 0;
		  }
		  else
		  {
					int leftheight = _HeightBinTree(T->lchild);					//左子树的高度
					int rightheight = _HeightBinTree(T->rchild);				//右子树的高度
					return (leftheight > rightheight ? leftheight : rightheight) + 1;	  //包含根
		  }
}

BOOL isBinTreeEmpty(BinTree* T)        //判断二叉树是否为空
{

}

BinNode* SearchNode(BinTree* T, ElemType key)    //在二叉树中查找某一个数据是否存在
{

}

BinNode* SearchParentNode(BinTree* T, BinNode* target)      //在二叉树中寻找某一个结点的父节点
{

}

BinNode* SearchLeftChild(BinNode* target)       //寻找结点的左子树
{

}

BinNode* SearchRightChild(BinNode* target)      //寻找结点的右子树
{

}

void CopyBinTree(BinTree* T_1, BinTree* T_2)     //二叉树的拷贝
{

}