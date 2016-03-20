#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <stdlib.h>
extern "C"{
#include "my_headers.h"
} 



using namespace std;

int main(){
	BiTree T;
	freopen("TreeInput.txt","r",stdin);
	CreateBiTreeG(T);
	PreOrderTraverse(T,displayG);

	return 0;
}
