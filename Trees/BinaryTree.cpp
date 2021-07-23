#include <bits/stdc++.h>
#define pb push_back
#define nl cout<<endl;
using namespace std;

class node{

	public:
	
	int data;
	node* left;
	node* right;
	
	node(int data){

		this->data = data;
		this->left = NULL;
		this->right = NULL;
	};
	
};


// Create a new node in heap
node* newNode(int data){
	
	node* newNode = new	node(data);
	return newNode;
};



//Inserting a node in the tree
node* insert(node* &root, int data){
		
		//Tree maybe empty
		if(root == NULL){
			root = newNode(data);
		}
		else if(data <= root->data){
			root->left = insert(root->left,data);
			
		}
		else{
			root->right = insert(root->right,data);
		}
		
		return root;
};




node* search(node* &root, int data){
	 if(root == NULL){
		return root;
	 }
	 else if(root->data == data) return root;
	 else if(data <= root->data) return search(root->left, data);
	 else return search(root->right, data);
}

node* findMax(node* &root){

	
	if(root == NULL || root->right == NULL){
		return root;
	}
	else{
		return findMax(root->right);
	}
};

int findMinAlt(node* root){
	
	
	if(root == NULL){
		cout <<"Empty tree"<<endl;
		return -1;
	}
	
	// Traversing the tree till we find a leaf node on the left	
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;	
	
}

int findMaxNodes(node* root){

		
	// Base case 
	if(root == NULL){
		return 0;
	}
	
	int left = findMaxNodes(root->left);
	int right = findMaxNodes(root->right);
	
	return max(left,right) + 1;	
}

int findHeight(node* root){
	
	// Base case 
	if(root == NULL){
		return -1;
	}
	
	int left = findHeight(root->left);
	int right = findHeight(root->right);
	
	return max(left,right) + 1;
}
 
node* findMin(node* root){
	
	
	if(root == NULL || root->left == NULL){
		return root;
	}
	else{
		return findMin(root->left);
	}
}

node* create(node* root){
	
	int value;
	cout << "Enter elements to be inserted in tree (-1 to exit): ";
	cin >> value;
	
	while(value != -1){
		
		root = insert(root,value);
		cout << "Enter elements to be inserted in tree (-1 to exit): ";
		cin >> value;
		
	}
	return root;
}

void deleteTree(node* &root){
	if(root != NULL){
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
	
};

void bfs(node* root){
	
	// Time Complexity O(n)
	// Space best: O(1) , avg/worst: O(n)
	
	if(root == NULL){
		return;	
	}
	
	// Queuing the address of visited node and its children
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		node* curr = q.front();
		cout << curr->data << " ";
		
		if(curr->left != NULL) q.push(curr->left);
		if(curr->right != NULL) q.push(curr->right);
		q.pop();	
	}
	
	
};

void in(node* root){
	 if(root == NULL) return;
	 
	 in(root->left);			// in(15) -> in(4) -> in(3) -> in(1) 
	 cout << root->data << " "; // 1 3 4 
	 in(root->right);	// 6 
};

void post(node* root){
	if(root == NULL) return;
	
	post(root->left);
	post(root->right);
	cout << root->data << " ";
} 

void pre(node* root){
	// Base case 
	if(root == NULL) return;
	cout << root->data << " ";
	pre(root->left);
	pre(root->right);
	
};

bool isBst(node* root, int minv, int maxv){
	
	if(root == NULL){
		return true;
	}
	
	if( root->data > minv && root->data < maxv &&
	isBst(root->left,minv,root->data) &&
	isBst(root->right, root->data, maxv)){
		return true;
	}
	else{
		return false;
	}
	
}

void bstQUtil(node* root, vector<int> &vec){
	
	if(root == NULL) {
		return;
	}
	
	bstQUtil(root->left, vec);
	vec.pb(root->data);
	bstQUtil(root->right,vec);
	
}

vector<int> bstQ(node* root){
	vector<int> vec;
	bstQUtil(root,vec);
	return vec;
}

node* deleteNode(node* &root, int data){
	
	if(root == NULL){
		return root;
	}
	else if(data < root->data){
		root->left = deleteNode(root->left,data);
	}
	else if(data > root->data){
		root->right = deleteNode(root->right, data);
	}
	else{
		
		
		// Case 1: When the node has no child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
			
		}		
		
		// Case 2: When it has 1 child
		// Left Child
		else if(root->left == NULL){
			node* temp = root;
			root = root->right;
			delete temp;
			
		}
		// Right child
		else if(root->right == NULL){
			node* temp = root;
			root = root->left;
			delete temp;
		}
		
		// Case 3: Has 2 children 
		else{
			// Find the min val of right subtree
			node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			
		}
	
		return root;	
	}
	
	
	 
	
}

int main(){
	
	// Pointer to the root node
	node* root = NULL;
	root = create(root);
	
	/*
	int num;
	cout << "Enter data you want to search: ";
	cin >> num;
	
	if(search(root,num)){
		cout <<"Found"<<endl;
	}
	else{
		cout << "Not Found"<<endl;
	}
	
	int h = findHeight(root);
	cout << "Height: "<<h <<endl;
	
	int n= findMaxNodes(root);
	cout << "Nodes: "<<n<<endl;
		
	cout << "BFS: ";
	bfs(root); 
	nl;
	
	cout << "Preorder: ";
	pre(root);
	nl;
	
	cout << "InOrder: ";
	in(root);
	nl;
	
	cout << "PostOrder: ";
	post(root);
	nl;
	
	if(isBst(root,INT_MIN, INT_MAX)){
		cout << "Yes"<< endl;	
	}
	else{
		cout << "No" << endl;
	}
	
	vector<int> val = bstQ(root);	
	cout << "Vector Elements: "<<endl;
	
	for(auto el: val){
		cout << el << " ";
	}
	
	if(is_sorted(val.begin(), val.end())){
		cout << "Binary Search Tree"<<endl;
	}
	*/
	// Pointer to traverse nodes
	//node* ptr = search(root, 150);
	//cout << ptr->data << endl;
	
	in(root);
	int num;
	cout << "Delete: ";
	cin >> num;
	root = deleteNode(root, num);
	in(root);
	
}
