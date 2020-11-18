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

void PostOrderStack(BinTree T);			//后序遍历栈版本
void _PostOrderStack(BinNode* T);		//后序遍历栈版本子程序