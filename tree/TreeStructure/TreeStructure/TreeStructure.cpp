// TreeStructure.cpp : 定义控制台应用程序的入口点。
/*  Input：{1,#,2,3}
    Output：{}
    Interface :
    vector< int > preorderTraversal( TreeNode * root);
*/
# include <iostream>
# include<vector>
#include <stack>
#include <iterator>
# include <algorithm>

using namespace std;
//TreeNode defined.
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
 //TreeNode 构造函数
	TreeNode(int value) :val(value), left(nullptr), right(nullptr){}
};

class TreeSolution{
public:
	TreeNode *root;
	virtual vector< int > preorderTraversal() = 0;
	virtual vector< int > inorderTraversal() = 0;
	virtual vector< int > posterTraversal() = 0;
};

class ProcessByStack : public TreeSolution {
	public:
		virtual vector< int > preorderTraversal() override;
		virtual vector< int > inorderTraversal() override;
		virtual vector< int > posterTraversal() override;
};

// using stack to traverse the all tree by 先序
vector< int > ProcessByStack::preorderTraversal(){
	vector< int > result;
	TreeNode * p;
	stack <TreeNode*>s;

	p = root;
	if (p != nullptr) s.push(p);
	while (!s.empty()){
		p = s.top();
		s.pop();
		result.push_back(p->val);

		if (p->left != nullptr)  s.push(p->left);
		if (p->right != nullptr)  s.push(p->right);

	}
	return result;
}

// using stack to traverse the all tree by 后序
vector< int > ProcessByStack::posterTraversal(){
	vector <int> result;
	TreeNode *p, *q;
	stack <TreeNode*> s;

	p = root; // root of the tree
	do{
		while (p != nullptr){
			s.push(p);
			p = p->left;   //大步流星往左边走
		}

		q = nullptr;
		while (!s.empty()){
			p = s.top();
			s.pop();

			if (p->right == q){
				result.push_back(p->val);
				q = p;
			}
			else{
				s.push(p);
				p = p->right; //小心翼翼往右边一步一步走
				break;
			}
		}
		
	} while (!s.empty());


	return result;
}


// using stack to traverse the all tree by 后序
vector< int > ProcessByStack::inorderTraversal(){
	/*vector <int> result;

	TreeNode * p,*q; 
	stack<TreeNode *> s;

	p = root;
	q = root;

	while (q != nullptr){

		while (p != nullptr){
			s.push(p);
			p = p->left;
		}

		while (1){		
			p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr){
				p = p->right;
				break;
			}
			if (s.empty()){
				q = nullptr;
				break;
			}
		}
				
	};


	return result;*/

	vector<int> result;
	TreeNode * p;
	stack<TreeNode *> s;

	if (!root) return result;
	p = root;

	do{
		while (p != nullptr){
			s.push(p);
			p = p->left;
		}

		while (!s.empty()){

			p = s.top();
			s.pop();
			result.push_back(p->val);

			if (p->right != nullptr){
				s.push(p->right);  // carefull every once toRight
				p = p->right;
				p = p->left;
				break;
			}
		}

	} while (!s.empty());

	return result;

}

/*

// ok, here, the stack method is finished  

class Morris : public TreeSolution {
public:
	virtual vector< int > preorderTraversal() override;
	virtual vector< int > inorderTraversal() override;
	virtual vector< int > posterTraversal() override;

};

vector< int > Morris::preorderTraversal(){
	vector< int > result;
	TreeNode * cur;

	cur = root;
	while (cur != nullptr){
		if (cur->left == nullptr){
			result.push_back(cur->val);
			cur = cur->right;
		}
		else{
			TreeNode * node = cur->left;
			while (node->right != nullptr&& node->right!=cur){
				node = node->right;
			}

			if (node->right == nullptr){
				result.push_back(cur->val);
				node->right = cur;
				cur = cur->left;
			}
			else{
				node->right = nullptr;
				cur = cur->right;
			}
		}
	}
	return result;
}

*/
int main(){

	TreeNode * root = new TreeNode(1);
	TreeNode *right_1 = new TreeNode(2);
	TreeNode *left_1 = new TreeNode(7);

	TreeNode  *left_2 = new TreeNode(3);
	root->right = right_1;
	root->left = left_1;
	right_1->left = left_2;

	ProcessByStack solution1;
	//Morris solution2;
	solution1.root = root;
	//solution2.root = root;
	vector<int > result = solution1.inorderTraversal();
	//vector<int > result = solution2.preorderTraversal();

	copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
	return 0;

}
