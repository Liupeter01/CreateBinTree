#include"Order.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char str[] = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);		  //Ê÷µÄ×Ö·û´®´´½¨

		  LevelOrder(T);
		  printf("\n");

		  DestroyBinTree(T.root);
		  return 0;
}