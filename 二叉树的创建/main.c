#include"BinTree.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char str[] = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);		  //树的字符串创建
		//   CreateBinTree(&T);			//树的手动创建
		  DestroyBinTree(T.root);
		  return 0;
}