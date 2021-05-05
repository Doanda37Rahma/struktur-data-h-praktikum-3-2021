#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_ARR 10000

using namespace std;
 
 
struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height;
};
struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

	int rightSum[MAX_ARR],
		leftSum[MAX_ARR],
		rightDistance,
		leftDistance;
 
    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
 
    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }
    
    
    int _getHeight(AVLNode* node) {
        if (node==NULL)
            return 0; 
        return node->height;
    }
 
    int _max(int a,int b) {
        return (a > b)? a : b;
    }
 
    AVLNode* _rightRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;
 
        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }
 
    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;
 
        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }
 
    AVLNode* _leftCaseRotate(AVLNode* node) {
        return _rightRotate(node);
    }
 
    AVLNode* _rightCaseRotate(AVLNode* node) {
        return _leftRotate(node);
    }
 
    AVLNode* _leftRightCaseRotate(AVLNode* node) {
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }
 
    AVLNode* _rightLeftCaseRotate(AVLNode* node) {
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }
 
    int _getBalanceFactor(AVLNode* node) {
        if (node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }
 
    AVLNode* _insert_AVL(AVLNode* node,int value) {
        
        if (node==NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left,value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
 
        int balanceFactor=_getBalanceFactor(node);
        
        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }
 
    int _findLeftDistance(AVLNode* node)
    {
        int ld=0;
        while (node && node->left) {
            node = node->left;
            ld++;
        }
        return ld;
    }
 
    int _findRightDistance(AVLNode* node) {
        int rd=0;
        while (node && node->right) {
            node = node->right;
            rd++;
        }
        return rd;
    }

   void _updateSum(AVLNode *node, int index)
    {
        if (node != NULL) {
            if (index>=0) {
                rightSum[index]+=node->data;
            }
            else if (index<0) {
                if (index*-1>leftDistance) 
                    leftDistance++;
                leftSum[index*-1]+=node->data;
            }
            _updateSum(node->left, index-1);
            _updateSum(node->right, index+1);
        }
    }
 
public:
    void init() {
        _root = NULL;
        _size = 0U;
    }
 
    bool isEmpty() {
        return _root == NULL;
    }
 
    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }
 
    void insert(int value) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }
 
    void printVerticalSum() {
        leftDistance = _findLeftDistance(_root);
        rightDistance = _findRightDistance(_root);
        for (int i=0; i<MAX_ARR; i++) {
        	leftSum[i] = rightSum[i] = 0;
		}
        _updateSum(_root, 0);
        for (int i=leftDistance; i>0 ;i--) {
            cout << leftSum[i] << " ";
        }
        for (int i=0 ; i<=rightDistance ; i++) {
            cout << rightSum[i] << " ";
        }
        cout << endl;
	}
 };
 
int main()
{
    AVL tree;
    tree.init();

    int t;
    char s[101];

    cin >> t;
    for (int i=0; i<t; i++) {
	    scanf("%s", s);
	    string cmd = s;
	        if (cmd == "insert") {
	            int x;
	            scanf("%d",&x);
	            tree.insert(x);
	        } else if (cmd == "print") {
	            if (!tree.isEmpty()) 
		            tree.printVerticalSum();
	        }
    }
    return 0;
}

