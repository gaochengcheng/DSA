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
bool specified;   //specified Ϊtrue��ʱ�򣬱�ʾ�����������ҿ������������
Node* root;       //root ��ȫ�ֵı�����
int nodes, inputNodes;//nodes��ʵ�ʴ����Ľ��ĸ�����ÿִ��һ��new node()���ͻ�+1.inputNodes������Ľ��ĸ����� 
string path;      //path ��¼���������·����
void insert(Node* root,int &key, int pos){
    if(pos == path.size()){    //����˵ path="LLL",��ôpath.size()=3��ֻ�е�pos��ֵҲΪ3��ʱ�򣬲�˵���ҵ������㣬Ȼ����ܸ�ֵ
        if(root->val != NOVALUE) specified = false;       //��û��ʲô���� 
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
clear������˼·�������ģ��ݹ飬��Ҷ�ӽ�㵽������delete���̡�
	������  ���ڵ�
	������ڵ�Ϊ�գ���ôֱ�ӷ��ء�
	������ڵ㲻Ϊ�գ��ݹ�clear���������ݹ�clear��������
	Ȼ��delete����㡣
*/
void clear(Node* root){
    if(root == NULL)return;
    clear(root->left);
    clear(root->right);
    delete root;
}
/*
�������Ѿ����������������ô��α�����
��Ҫһ�����к�һ��vector������queue��vector��
�����ø��������У�queue��
	дѭ�����ж϶����Ƿ�Ϊ�գ�
		���գ����������С�
		������ֵ��vector
		�����������������С�

������Ǳ������vector�е�Ԫ�ؼ��� 
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
    //����3�еĹ��ܾ������vector�����е�Ԫ�ء� 
    for(int i = 0; i < (int)ans.size()-1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size()-1]);

}

/*

puts()�����������׼����豸(��Ļ)д�ַ���������, ����ø�ʽΪ: puts(s);

puts(s) ��Ч��printf("%s\n",s)��ǰ�� ��s��C����ַ����������'\0'��β��

˵��:
(1). puts()����ֻ������ַ���, ���������ֵ����и�ʽ�任�� (2). ���Խ��ַ���ֱ��д��puts()�����С���: puts("Hello, Turbo C2.0");
*/
void solve(){
    if( specified == false || inputNodes != nodes)puts("not complete");//C ���Ե�һ����������һ���ַ���׷�ӵ�������С� 
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
