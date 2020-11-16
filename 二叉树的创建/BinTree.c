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
					free(p);
		  }
}

void CreateBinTreeByString(BinTree* T, const char* str)          //根据字符串创建
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
		  }
		  else
		  {
					data = *str;	//到下一个字符
		  }

		  //状态机设计模式，根据不同的输入切换不同的判断状态，具体效率未知
		  if ((str == NULL) ? (data != T->stopflag) : (data != T->stopflag && data != '\0'))				  
		  {
					*p = CreateBinNode(data);
					CreateBiTNode(T, &((*p)->lchild), ++str);
					CreateBiTNode(T, &((*p)->rchild), ++str);
		  }
}