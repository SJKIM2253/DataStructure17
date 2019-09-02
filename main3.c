#include<stdio.h> 
#include<stdlib.h> 
#include <memory.h>

typedef struct treeNode {
	int key;                //������ �ʵ�
	struct treeNode* left;     //���� ����Ʈ�� ��ũ �ʵ�
	struct treeNode* right;    //������ ����Ʈ�� ��ũ �ʵ�
} treeNode; 

typedef int element;  //char�� ���� Ž�� Ʈ�� element�� �ڷ������� ����

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode)
{     //data�� ��Ʈ ���� �Ͽ� ���� ����Ʈ���� ������ ����Ʈ���� �����ϴ� ����
 	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
 	root->key = data;
 	root->left = leftNode;
	root->right = rightNode;
 	return root;
}

treeNode* insertNode(treeNode *p, int x) 
{    //������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
	  else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n"); 

	  return p;	 
} 

void deleteNode(treeNode *root, element key)
{     //root ������ Ž���Ͽ� key ���� ���� ��带 ã�� �����ϴ� ����
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent=NULL;
	p=root; 
	while((p != NULL) && (p->key != key)){  //������ ����� ��ġ Ž��
		parent=p;
		if(key < p->key) p=p->left;
		else p=p->right;
 	}
	if(p == NULL){  //������ ��尡 ���� ���
		printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�!!");
		return;
	}

	// ������ ��尡 �ܸ������ ���
	if((p->left == NULL) && (p->right == NULL)){
		if(parent != NULL){
			if(parent->left == p) parent->left=NULL;
			else parent->right=NULL;
		}
		else root=NULL;
	}

	// ������ ��尡 �� ���� �ڽĳ�带 ���� ���
	else if((p->left == NULL) || (p->right == NULL)){
		if(p->left != NULL) child=p->left;
		else child=p->right;

		if(parent != NULL){
			if(parent->left == p) parent->left=child;
			else parent->right=child;
		}
		else root=child;
	}

	// ������ ��尡 �� ���� �ڽĳ�带 ���� ���
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
{    //���� Ž�� Ʈ������ Ŷ���� x�� ����� ��ġ�� Ž���ϴ� ����
 	 treeNode* p; 
	 p = root; 
	 while (p != NULL){ 
		if (x < p->key) p = p->left; 	
		else if (x == p->key) return p; 
		else p = p->right; 
	 } 
	printf("\n ã�� Ű�� �����ϴ�!");	 
	return p; 
} 


void preorder(treeNode* root)   //���� Ʈ���� ���� ���� ��ȸ ����
{
 	if(root){
  	   printf("%d ", root->key);
 	   preorder(root->left);
 	   preorder(root->right);
 	}
}

void inorder(treeNode* root)    //���� Ʈ���� ���� ���� ��ȸ ����
{
 	if(root){
 	   inorder(root->left);
 	   printf("%d ", root->key);
 	   inorder(root->right);
 	}
}

void postorder(treeNode* root)    //���� Ʈ���� ���� ���� ��ȸ ����
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

