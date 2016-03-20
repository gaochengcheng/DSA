#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <sstream>
#include "type_def.h"
#include "tree.h"

using namespace std;
int level=0;

/*
这里在输入的时候，比较难受，因为是递归方式建树，
当输入一个量的时候，会产生左右两棵子树的递归，
所以，必须同时让这两棵子树同时都能读到一个
结束符标志，这个输入过程才能停止。 
*/
Status CreateBiTree(BiTree &T){
	cout<<"start......"<<endl;
	level++;
	cout<<level<<endl;
	char ch;
	scanf("%c",&ch);
	//因为会把回车符同时读入，所以这么修改,如果我们读入整数，即
	//ch是int，scanf中是%d，判断终止条件是 ch == -1，那么就不需
	//下面两句。 
	if(ch =='\n')
		scanf("%c",&ch);
//	cout<<"ch:"<<ch<<endl;
	if(' ' == ch)
		T = NULL;
	else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		if(!T)
			return ERROR;
		T->data = ch;
		CreateBiTree(T->lchild);
		cout<<"flag"<<endl;
		CreateBiTree(T->rchild);
	}
	return OK;
}



/**
 * 打印一个元素
 */
Status display(TElemType e)
{
	printf("%c ", e);
	return OK;
}



/**
 * 算法6.1，先序遍历二叉树，对每个元素调用函数viist
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if (T) {
		if (OK == visit(T->data))
			if (OK == PreOrderTraverse(T->lchild, visit))
				if (OK == PreOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	} else
		return OK;
}

// 可以输入 a  b  空格  空格  空格   来测试 
int main(){
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T, display);
	
	return 0;
}

