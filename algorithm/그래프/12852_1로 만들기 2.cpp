#include <iostream>
using namespace std;

int dp[1000001]; //연산 횟수 저장
int before[1000001]; //이전 숫자 저장

int main(void) {
	int target;
	cin >> target;
	
	dp[1] = 0;
	for (int i = 1; i <= target; i++) {
		if (i * 3 <= target) {
			if (!dp[i * 3] || dp[i] + 1 < dp[i * 3]) {
				dp[i * 3] = dp[i] + 1;
				before[i * 3] = i;
			}	
		}
		if (i * 2 <= target) {
			if (!dp[i * 2] || dp[i] + 1 < dp[i * 2]) {
				dp[i * 2] = dp[i] + 1;
				before[i * 2] = i;
			}
		}
		if (i + 1 <= target) {
			if (!dp[i + 1] || dp[i] + 1 < dp[i + 1]) {
				dp[i + 1] = dp[i] + 1;
				before[i + 1] = i;
			}	
		}
	}
	
	cout << dp[target] << endl;
	cout << target << " ";
	while (target != 1) {
		cout << before[target] << " ";
		target = before[target];
	}

	return 0;
}

/*
트리 탐색 방식

#include <vector>
#include <queue>
class node {
public:
	int num;
	node* case1, * case2, * case3, * parent;
};

class tree {
public:
	node* root;
	tree() { 
		root = new node();
		root->num = 1;
	}
	~tree() {}
};

void print(node*);

int main(void) {
	int target;
	cin >> target;

	tree* t = new tree();
	queue<node*> q;
	q.push(t->root);

	while (1) {
		node* newnode = q.front();
		q.pop();
		newnode->case1 = new node();
		newnode->case1->num = newnode->num * 3;
		newnode->case1->parent = newnode;
		q.push(newnode->case1);
		if (newnode->case1->num == target) {
			print(newnode->case1);
			break;
		}
		newnode->case2 = new node();
		newnode->case2->num = newnode->num * 2;
		newnode->case2->parent = newnode;
		q.push(newnode->case2);
		if (newnode->case2->num == target) {
			print(newnode->case2);
			break;
		}
		newnode->case3 = new node();
		newnode->case3->num = newnode->num + 1;
		newnode->case3->parent = newnode;
		q.push(newnode->case3);
		if (newnode->case3->num == target) {
			print(newnode->case3);
			break;
		}
	}
	while (!q.empty()) {
		q.pop();
	}

	return 0;
}

void print(node* _node) {
	node* cur = _node;
	int height = -1;
	vector<int> v;
	while (cur) {
		height++;
		v.push_back(cur->num);
		cur = cur->parent;
	}
	cout << height << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";
	}
}*/
