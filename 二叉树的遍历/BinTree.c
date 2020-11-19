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

void CreateBinTreeByPreInOrder(BinTree* T, char* PreOrder, char* InOrder, int NodeSize)       //通过先序序列和中序序列和结点个数恢复一颗二叉树
{
		  _CreateBinTreeByPreInOrder(&(T->root), PreOrder, InOrder, NodeSize);
}

static void _CreateBinTreeByPreInOrder(BinNode** p, char* PreOrder, char* InOrder, int NodeSize)     //二叉树高级创建子函数
{
		  if (NodeSize == 0)			//结点数量为0
		  {
					*p = NULL;			//树为空
		  }
		  else
		  {
					char root_Pre = *PreOrder;		  //先序序列的根是首元素
					int pos = 0;	  //在中序序列中根结点的为止
					while (InOrder[pos] != '\0' && InOrder[pos++] != root_Pre);		//查找
					pos -= 1;			//pos会比之前多1
					*p = CreateBinNode(root_Pre);
					_CreateBinTreeByPreInOrder(&((*p)->lchild), PreOrder + 1, InOrder, pos);	  //左划分
					_CreateBinTreeByPreInOrder(&((*p)->rchild), PreOrder + pos + 1, InOrder + pos + 1, NodeSize - pos - 1); //右划分
		  }
}

void CreateBinTreeByPrePostOrder(BinTree* T, char* PreOrder, char* PostOrder, int NodeSize)     //通过先序序列和后序序列和结点个数恢复一颗二叉树
{
		  _CreateBinTreeByPrePostOrder(&(T->root), PreOrder, PostOrder, NodeSize);
}

static void _CreateBinTreeByPrePostOrder(BinNode** p, char* PreOrder, char* PostOrder, int NodeSize)    //二叉树高级创建子函数
{
		  if (!NodeSize)	  //结点数量为0
		  {
					 *p = NULL;			//树为空
		  }
		  else
		  {
					char root_Pre = *PreOrder;		  //去先序序列首元素为根节点
					int pos = 0;
					while (PostOrder[pos] != '\0' && PostOrder[pos++] != root_Pre);
					pos--;	  //弥补多加的下标
					*p = CreateBinNode(root_Pre);
					_CreateBinTreeByPrePostOrder(&((*p)->lchild), PreOrder + 1, PostOrder, pos);	   //左划分
					_CreateBinTreeByPrePostOrder(&((*p)->rchild), PreOrder + pos + 1, PostOrder + pos + 1, NodeSize - pos - 1);	   //右划分
		  }
}

void CreateBinTreeByInPostOrder(BinTree* T, char* InOrder, char* PostOrder, int NodeSize)     //通过中序序列和后序序列和结点个数恢复一颗二叉树
{
		  
		  _CreateBinTreeByInPostOrder(&(T->root), InOrder, PostOrder, NodeSize);
}

static void _CreateBinTreeByInPostOrder(BinNode** p, char* InOrder, char* PostOrder, int NodeSize)      //二叉树高级创建子函数
{
		  if (!NodeSize)	  //结点数量为0
		  {
					*p = NULL;			//树为空
		  }
		  else
		  {
					char root_Post = *(PostOrder + NodeSize - 1);		  //后序最后一个结点是根节点
					int pos = 0;
					while (InOrder[pos] != '\0' && InOrder[pos++] != root_Post);
					pos--;	  //弥补多加的下标
					*p = CreateBinNode(root_Post);
					_CreateBinTreeByInPostOrder(&((*p)->rchild), InOrder + pos + 1, PostOrder + pos, NodeSize - pos - 1);
					_CreateBinTreeByInPostOrder(&((*p)->lchild), InOrder, PostOrder, pos);
		  }
}
