#include"Order.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char str[] = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);		  //Ê÷µÄ×Ö·û´®´´½¨

		  PreOrder(T);
		  printf("\n");
		  PreOrderStack(T);
		

		  DestroyBinTree(T.root);
		  return 0;
}