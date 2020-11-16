#include"BinTree.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');
		 // CreateBinTree(&T);			//Ê÷µÄ´´½¨
		  char* str = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);
		  DestroyBinTree(T.root);
		  return 0;
}