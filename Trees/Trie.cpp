#include <bits/stdc++.h>
using namespace std;

// Trie datastructure with TrieNode 
 
class TrieNode{
	public:
	char data;
	int wc;
	TrieNode* child[26];
};

TrieNode nodepool[100000]; // Pool of 100K Nodes
TrieNode* root; // Root node 
int poolcount; // Count of nodes in nodepool 

// Initialize the Trie
void init(){
	
	poolcount = 0;
	root = &nodepool[poolcount++];
	root->data = '/';
	
	for(int i=0; i<26; i++){
		root->child[i] = NULL;
	}
}

// Constructing a new node whenever getNode is called
TrieNode* getNode(char c){
	
	TrieNode* node = &nodepool[poolcount++];
	node->data = c;
	
	for(int i=0; i<26; i++){
		node->child[i] = NULL;
	}
	node->wc = 0;
	
	return node;
}

// Insert a node (characters of a string) into the Trie
void insert(char* s){
	
	TrieNode* curr = root;
	int index;
	
	for(int i=0; s[i] != '\0'; i++){
		
		// Calculating relative index of characters
		index = s[i] - 'a';
		
		// We reach a leaf node
		if(curr->child[index] == NULL){
			curr->child[index] = getNode(s[i]);
		}
		
		// If we find the char again we increase wc 
		// This helps in calculating prefix string 
		
		curr->child[index]->wc += 1;
		curr = curr->child[index];
	}
		
}

bool search(char* s){
	
	TrieNode* curr = root;
	int index;
	
	for(int i=0; s[i] != '\0'; i++){
		
		index = s[i] - 'a';	
		if(curr->child[index] == NULL || curr->child[index]->wc == 0){
			return false;
		}
		
		curr = curr->child[index];
	}
	return true;
}


bool TrieDelete(char* s){
	
	if(search(s)){
		TrieNode* curr = root;
		int index; 
	
		for(int i=0; s[i] != '\0'; i++){
		
			index = s[i] - 'a';
			curr->child[index]->wc -= 1;
			curr = curr->child[index];
		}		
	}

}


int countPrefix(string s){
	TrieNode* curr = root;
	int index;
	
	for(int i=0; s[i] != '\0'; i++){
		
		index = s[i] - 'a';
		if(curr->child[index] == NULL || curr->child[index]->wc == 0){
			return 0;
		}
		
		curr = curr->child[index];
	}
	
	return curr->wc;
}
 


int main(){
	
	    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    TrieDelete(a);
    TrieDelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}


