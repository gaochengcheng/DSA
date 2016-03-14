#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <sstream>
//https://github.com/shahidul2k9/problem-solution/blob/master/uva%20online%20judge/122%20-%20Trees%20on%20the%20level.cpp

using namespace std;
#define NOVALUE -1

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){
        this-> val = NOVALUE;
        this->left = NULL;
        this->right = NULL;
    }
};
bool specified;   //specified 为true的时候，表示输入正常，且可以正常输出。
Node* root;       //root 是全局的变量。
int nodes, inputNodes;//nodes是实际创建的结点的个数，每执行一次new node()，就会+1.inputNodes是输入的结点的个数。 
string path;      //path 记录了这个结点的路径。
void insert(Node* root,int &key, int pos){
    if(pos == path.size()){    //假如说 path="LLL",那么path.size()=3，只有当pos的值也为3的时候，才说明找到这个结点，然后才能赋值
        if(root->val != NOVALUE) specified = false;       //并没有什么作用 
        root->val = key;
    }

    else if( path[pos] == 'L'){
        if(root->left == NULL){
            nodes++;
            Node* node = new Node;
            root->left = node;
            insert(node, key, pos+1);
        }
        else insert(root->left, key, pos+1);
    }
    else {
        if(root->right == NULL){
            nodes++;
            Node* node = new Node;
            root->right = node;
            insert(node, key, pos+1);
        }
        else insert(root->right, key, pos+1);
    }

}
/*
clear函数的思路是这样的：递归，从叶子结点到根结点的delete过程。
	参数：  根节点
	如果根节点为空，那么直接返回。
	如果根节点不为空，递归clear左子树，递归clear右子树。
	然后delete根结点。
*/
void clear(Node* root){
    if(root == NULL)return;
    clear(root->left);
    clear(root->right);
    delete root;
}
/*
现在我已经构建好这棵树，怎么层次遍历。
需要一个队列和一个vector。创建queue和vector。
首先让根结点入队列（queue）
	写循环，判断队列是否为空，
		不空，根结点出队列。
		根结点的值入vector
		根结点的左后子树入队列。

最后，我们遍历输出vector中的元素即可 
*/
void bfs(){
    queue< Node* > q;
    vector < int > ans;
	q.push(root);
    Node* node;
    while(!q.empty()){
        node = q.front();q.pop();
        ans.push_back(node->val);
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
    //整个3行的功能就是输出vector中所有的元素。 
    for(int i = 0; i < (int)ans.size()-1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size()-1]);

}

/*

puts()函数用来向标准输出设备(屏幕)写字符串并换行, 其调用格式为: puts(s);

puts(s) 等效于printf("%s\n",s)，前提 ：s是C风格字符串，最后以'\0'结尾。

说明:
(1). puts()函数只能输出字符串, 不能输出数值或进行格式变换。 (2). 可以将字符串直接写入puts()函数中。如: puts("Hello, Turbo C2.0");
*/
void solve(){
    if( specified == false || inputNodes != nodes)puts("not complete");//C 语言的一个函数，把一个字符串追加到输出流中。 
    else bfs();

}

void init(){
    clear(root);
    root = new Node;
    nodes = 1;
    specified = true;
    inputNodes = 0;
}


int main(){
    freopen("input.txt", "r", stdin);
    string s;
    int val;

    init();
    while(cin >> s){
        if(s == "()"){
            solve();
            init();
        }
        else{
            inputNodes++;
            stringstream ss;
            for(int i = 0; i < s.size(); i++)
                if(s[i] == '(' || s[i] == ')'|| s[i] == ',') s[i] = ' ';
            ss << s;
            ss >> val;
            path = "";
            ss >> path;
            insert(root, val, 0);
        }
    }
    return 0;
}
