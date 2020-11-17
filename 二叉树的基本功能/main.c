#include"Order.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char* str[] = \
		  { 
					"ABC##DE##F##G#H##" ,
					"ABC##D##G#H##"		
		  };
		  CreateBinTreeByString(&T, str[1]);		  //树的字符串创建

		  printf("Node Amount = %d\n", SizeBinTree(T));	//结点个数
		  printf("BinTree Height = %d\n", HeightBinTree(T));		  //树的高度

		  DestroyBinTree(T.root);
		  return 0;
}