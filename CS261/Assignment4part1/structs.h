/* You can modify the structure to store whatever you'd like in your BST */


//use compare1 with this
struct data {
	int number;
	char * name;
};

//use compare2 with this
struct data2 {
	float number;
};

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};