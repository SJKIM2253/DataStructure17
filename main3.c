#include<stdio.h> 
#include<stdlib.h> 
#include <memory.h>

typedef struct treeNode {
	int key;                //데이터 필드
	struct treeNode* left;     //왼쪽 서브트리 링크 필드
	struct treeNode* right;    //오른쪽 서브트리 링크 필드
} treeNode; 

typedef int element;  //char을 이진 탐색 트리 element의 자료형으로 정의

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode)
{     //data를 루트 노드로 하여 왼쪽 서브트리와 오른쪽 서브트리를 연결하는 연산
 	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
 	root->key = data;
 	root->left = leftNode;
	root->right = rightNode;
 	return root;
}

treeNode* insertNode(treeNode *p, int x) 
{    //포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
 	  treeNode *newNode;	
	  if (p == NULL){ 
        	newNode = (treeNode*)malloc(sizeof(treeNode)); 
		newNode->key = x; 
		newNode->left = NULL; 
		newNode->right = NULL; 
		return newNode; 
	  } 
	  else if (x < p->key)  p->left = insertNode(p->left, x);        
	  else if (x > p->key)  p->right = insertNode(p->right, x); 
	  else  printf("\n 이미 같은 키가 있습니다! \n"); 

	  return p;	 
} 

void deleteNode(treeNode *root, element key)
{     //root 노드부터 탐색하여 key 값과 같은 노드를 찾아 삭제하는 연산
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent=NULL;
	p=root; 
	while((p != NULL) && (p->key != key)){  //삭제할 노드의 위치 탐색
		parent=p;
		if(key < p->key) p=p->left;
		else p=p->right;
 	}
	if(p == NULL){  //삭제할 노드가 없는 경우
		printf("\n 찾는 키가 이진트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말노드인 경우
	if((p->left == NULL) && (p->right == NULL)){
		if(parent != NULL){
			if(parent->left == p) parent->left=NULL;
			else parent->right=NULL;
		}
		else root=NULL;
	}

	// 삭제할 노드가 한 개의 자식노드를 가진 경우
	else if((p->left == NULL) || (p->right == NULL)){
		if(p->left != NULL) child=p->left;
		else child=p->right;

		if(parent != NULL){
			if(parent->left == p) parent->left=child;
			else parent->right=child;
		}
		else root=child;
	}

	// 삭제할 노드가 두 개의 자식노드를 가진 경우
	else{
		succ_parent=p;
		succ=p-> left;
		while(succ->right  != NULL){
			succ_parent=succ;
			succ=succ-> right;
		}
		if(succ_parent->left == succ)  succ_parent->left=succ-> left;
		else succ_parent->right=succ-> left;
		p->key=succ->key;
		p=succ;
	} 
	free(p);
}

treeNode* searchBST(treeNode* root, int x) 
{    //이진 탐색 트리에서 킷값이 x인 노드의 위치를 탐색하는 연산
 	 treeNode* p; 
	 p = root; 
	 while (p != NULL){ 
		if (x < p->key) p = p->left; 	
		else if (x == p->key) return p; 
		else p = p->right; 
	 } 
	printf("\n 찾는 키가 없습니다!");	 
	return p; 
} 


void preorder(treeNode* root)   //이진 트리에 대한 전위 순회 연산
{
 	if(root){
  	   printf("%d ", root->key);
 	   preorder(root->left);
 	   preorder(root->right);
 	}
}

void inorder(treeNode* root)    //이진 트리에 대한 중위 순회 연산
{
 	if(root){
 	   inorder(root->left);
 	   printf("%d ", root->key);
 	   inorder(root->right);
 	}
}

void postorder(treeNode* root)    //이진 트리에 대한 후위 순회 연산
{
 	if(root){
 	   postorder(root->left);
 	   postorder(root->right);
 	   printf("%d ", root->key);
 	}
}

int main() 
{	 
	treeNode* root = NULL;	  
	treeNode* foundedNode = NULL; 
	int key;
	
	int i, j, a=0;
	scanf("%d",&a); getchar();
	int num1=0, num2=0;
	for(i=0;i<a;i++){
		scanf("%d",&num1);
		root =insertNode(root, num1);
	}
/*
preorder(root);
printf("\n");
inorder(root);
printf("\n");
postorder(root);
*/
getchar();

	int k=0, m=0, p=0;
	scanf("%d",&k); getchar();
	
for(j=0;j<k;j++){
	scanf("%d %d",&p, &num2); getchar();

		
	if(p=0){
			preorder(root);
	deleteNode(root, num2);
	preorder(root);
	}
	else if(p=1){
		inorder(root);	
	deleteNode(root, num2);
	inorder(root);
	}
	else{
			postorder(root);
	deleteNode(root, num2);
	postorder(root);	
	};
	printf("\n");
}


}

