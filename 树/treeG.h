#ifndef _TREE_H_
#define _TREE_H_

typedef int TElemType;		//定义二叉树结点的数据元素类型
typedef struct BiTNode {	//定义二叉树的结点
	TElemType data;
	struct BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode, *BiTree;

typedef BiTree SElemType;
typedef BiTree QElemType;

//我定义的一些函数
Status CreateBiTreeG(BiTree &T); 
Status displayG(TElemType e);
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status add(int a,int b);

#endif
