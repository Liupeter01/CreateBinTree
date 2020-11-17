/*
* Copyright (c) 2020,
* All rights reserved.
* 文件名称：Order.h
* 作者：刘沛恒
* 完成日期：2020年11月17日
* 版本号：V1.0
*
* 文件描述：用于处理二叉树的遍历操作

* 输入描述： 根据要求输入
* 输出描述： 输出相应的结果
*/

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