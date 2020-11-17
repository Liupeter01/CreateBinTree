#include"Order.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char str[] = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);		  //树的字符串创建

		  printf("Amount = %d\n", SizeBinTree(T));	//结点个数
		  printf("Height = %d", HeightBinTree(T));		  //树的高度

		  DestroyBinTree(T.root);
		  return 0;
}