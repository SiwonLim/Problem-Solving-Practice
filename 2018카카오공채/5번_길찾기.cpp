#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int id, x, y;
	Node *left, *right;
};

bool cmp(Node& a, Node& b){
	if (a.y == b.y) return a.x < a.y;
	return a.y > b.y;
}

void addNode(Node *parent, Node *child){
	if (child->x < parent->x){
		if (parent->left == NULL) parent->left = child;
		else addNode(parent->left, child);
	}
	else{
		if (parent->right == NULL) parent->right = child;
		else addNode(parent->right, child);
	}
}

void preorder(vector<int>& answer, Node *node){
	if (node == NULL) return;
	else{
		answer.push_back(node->id);
		preorder(answer, node->left);
		preorder(answer, node->right);
	}
}

void postorder(vector<int>& answer, Node *node){
	if (node == NULL) return;
	else {
		postorder(answer, node->left);
		postorder(answer, node->right);
		answer.push_back(node->id);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int size = nodeinfo.size();
	vector<Node> tree;
	for (int i = 0; i < size ; i++)
		tree.push_back({i+1,nodeinfo[i][0], nodeinfo[i][1]});
	//y큰 순 - x작은순 정렬
	sort(tree.begin(), tree.end(), cmp);
	Node* root = &tree[0];
	for (int i = 1; i < size; i++) addNode(root, &root[i]);

	vector<vector<int>> answer = { {},{} };
	preorder(answer[0], root);
	postorder(answer[1], root);
	return answer;
}