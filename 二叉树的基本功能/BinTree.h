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

/*二叉树的初始化与释放操作*/
void InitBinTree(BinTree* T, ElemType stopflag);            //二叉树的初始化
void DestroyBinTree(BinNode* p);         //二叉树的销毁
void ClearBinTree(BinTree* T);                    //二叉树的清除操作

/*二叉树的创建*/
void CreateBinTreeByString(BinTree* T, char* str);          //根据字符串创建
void CreateBinTree(BinTree* T);          //二叉树的创建的外层函数
static void CreateBiTNode(BinTree* T, BinNode** p, const char* str);  //二叉树创建函数
/*当传入的str为NULL的时候采用手动输入，非NULL为自动*/

/*二叉树的基本操作*/
int SizeBinTree(BinTree T);            //二叉树的结点个数
int _SizeBinTree(BinNode* p);           //结点个数子程序

int HeightBinTree(BinTree T);           //二叉树的高度
int _HeightBinTree(BinNode* T);           //二叉树的高度子函数

BOOL isBinTreeEmpty(BinTree* T);        //判断二叉树是否为空
BinNode* SearchNode(BinTree T, ElemType key);    //在二叉树中查找某一个数据是否存在
BinNode* _SearchNode(BinNode* T, ElemType key);    //在二叉树中查找某一个数据是否存在子函数

BinNode* SearchParentNode(BinTree T, BinNode* target);      //在二叉树中寻找某一个结点的父节点
BinNode* _SearchParentNode(BinNode* T, BinNode* target);      //在二叉树中寻找某一个结点的父节点子函数

BinNode* SearchLeftChild(BinNode* target);        //寻找结点的左子树
BinNode* SearchRightChild(BinNode* target);       //寻找结点的右子树
void CopyBinTree(BinTree* T_1, BinTree* T_2);     //二叉树的拷贝
