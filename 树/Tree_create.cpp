#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <sstream>
#include "type_def.h"
#include "tree.h"

using namespace std;
int level=0;

/*
�����������ʱ�򣬱Ƚ����ܣ���Ϊ�ǵݹ鷽ʽ������
������һ������ʱ�򣬻�����������������ĵݹ飬
���ԣ�����ͬʱ������������ͬʱ���ܶ���һ��
��������־�����������̲���ֹͣ�� 
*/
Status CreateBiTree(BiTree &T){
	cout<<"start......"<<endl;
	level++;
	cout<<level<<endl;
	char ch;
	scanf("%c",&ch);
	//��Ϊ��ѻس���ͬʱ���룬������ô�޸�,������Ƕ�����������
	//ch��int��scanf����%d���ж���ֹ������ ch == -1����ô�Ͳ���
	//�������䡣 
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
 * ��ӡһ��Ԫ��
 */
Status display(TElemType e)
{
	printf("%c ", e);
	return OK;
}



/**
 * �㷨6.1�������������������ÿ��Ԫ�ص��ú���viist
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

// �������� a  b  �ո�  �ո�  �ո�   ������ 
int main(){
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T, display);
	
	return 0;
}

