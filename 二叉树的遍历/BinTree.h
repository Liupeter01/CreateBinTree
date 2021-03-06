#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<memory.h>
#include<assert.h>

#define ElemType char

typedef struct BinNode                  //结点定义
{
          ElemType data;				//数据域
          struct BinNode* lchild;       //指针域，左子树
          struct BinNode* rchild;       //指针域，右子树
}BinNode;

typedef struct BinTree
{
          BinNode* root;                   //根节点
          ElemType stopflag;            //停止标记
}BinTree;

BinNode* CreateBinNode(ElemType x);               //二叉树的结点创建函数

/*二叉树的基本操作*/
void InitBinTree(BinTree* T, ElemType stopflag);            //二叉树的初始化
void DestroyBinTree(BinNode* p);         //二叉树的销毁

/*二叉树的高级创建*/
void CreateBinTreeByPreInOrder(BinTree* T, char* PreOrder, char* InOrder, int NodeSize);       //通过先序序列和中序序列和结点个数恢复一颗二叉树
static void _CreateBinTreeByPreInOrder(BinNode** p, char* PreOrder, char* InOrder, int NodeSize);      //二叉树高级创建子函数

void CreateBinTreeByPrePostOrder(BinTree* T, char* PreOrder, char* PostOrder, int NodeSize);       //通过先序序列和后序序列和结点个数恢复一颗二叉树
static void _CreateBinTreeByPrePostOrder(BinNode** p, char* PreOrder, char* PostOrder, int NodeSize);      //二叉树高级创建子函数

void CreateBinTreeByInPostOrder(BinTree* T, char* InOrder, char* PostOrder, int NodeSize);       //通过中序序列和后序序列和结点个数恢复一颗二叉树
static void _CreateBinTreeByInPostOrder(BinNode** p, char* InOrder, char* PostOrder, int NodeSize);      //二叉树高级创建子函数

/*二叉树的创建*/
void CreateBinTreeByString(BinTree* T, char* str);          //根据字符串创建
void CreateBinTree(BinTree *T);          //二叉树的创建的外层函数
static void CreateBiTNode(BinTree* T, BinNode** p, const char* str);  //二叉树创建函数
/*当传入的str为NULL的时候采用手动输入，非NULL为自动*/
