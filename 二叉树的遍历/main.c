#include"Order.h"

int main()
{
		  BinTree T;
		  InitBinTree(&T, '#');

		  char str[] = "ABC##DE##F##G#H##";
		  CreateBinTreeByString(&T, str);		  //�����ַ�������

		  InOrder(T);
		  printf("\n");
		  InOrderStack(T);
		  printf("\n");

		  PreOrder(T);
		  printf("\n");
		  PreOrderStack(T);
		

		  DestroyBinTree(T.root);
		  return 0;
}