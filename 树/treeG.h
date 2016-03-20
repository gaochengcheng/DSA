#ifndef _TREE_H_
#define _TREE_H_

typedef int TElemType;		//�����������������Ԫ������
typedef struct BiTNode {	//����������Ľ��
	TElemType data;
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode, *BiTree;

typedef BiTree SElemType;
typedef BiTree QElemType;

//�Ҷ����һЩ����
Status CreateBiTreeG(BiTree &T); 
Status displayG(TElemType e);
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status add(int a,int b);

#endif
