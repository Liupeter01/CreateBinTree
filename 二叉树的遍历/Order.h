#pragma once
#include"LinkStack.h"		  //模拟栈
#include"LinkQueue.h"		  //模拟队列


void PreOrder(BinTree T);      //先序遍历
void InOrder(BinTree T);                 //中序遍历
void PostOrder(BinTree T);               //后序遍历

/*SUBMODULE以上模块的子模块*/
void _PreOrder(BinNode* T);      //先序遍历子模块
void _InOrder(BinNode* T);                 //中序遍历子模块
void _PostOrder(BinNode* T);               //后序遍历子模块

void InOrderStack(BinTree T);  //中序遍历栈版本
void _InOrderStack(BinNode* T);  //中序遍历栈版本子程序

void LevelOrder(BinTree T);              //层次遍历
void _LevelOrder(BinNode* T);			//层次遍历队列子程序