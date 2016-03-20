#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <sstream>
#include "my_headers.h"
/*
从文件中读取创建树 
*/
using namespace std;   

Status CreateBiTreeG(BiTree &T){
	
	int value;
	cin >> value;
	if(-1 == value)
		T = NULL;
	else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		if(!T)
			return ERROR;
		T->data = value;
		CreateBiTreeG(T->lchild);
		CreateBiTreeG(T->rchild);
	}
	return OK;
}
/*
打印元素 
*/
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

Status displayG(TElemType e)
{
	printf("%d ", e);
	return OK;
}

int main(){
	BiTree T;
	freopen("TreeInput.txt","r",stdin);
	CreateBiTreeG(T);
	PreOrderTraverse(T,displayG);
	
	return 0;
}

