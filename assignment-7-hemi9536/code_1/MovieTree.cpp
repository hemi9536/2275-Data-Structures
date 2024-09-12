#include "MovieTree.hpp"
#include <iostream>
#include <fstream>


using namespace std;
/* ------------------------Starter Code function---------- */
LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

void preorderTraversalHelper(TreeNode * root) {
	if (root == NULL) 
    {
		return;
	}
    cout << root->titleChar << " ";
    preorderTraversalHelper(root->leftChild);
    preorderTraversalHelper(root->rightChild);
}

void MovieTree::preorderTraversal() {
	preorderTraversalHelper(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* --------------------------Constructor---------------------------- */
MovieTree::MovieTree()
{
    root = NULL;
}

/* --------------------------Destructor---------------------------- */

void MovieTree:: rdelete(TreeNode *node)
{
	//TODO
    if (node == nullptr) {
        return;
    }
    rdelete(node->leftChild);
    rdelete(node->rightChild);
    LLMovieNode *temp = node->head;
    while(temp != nullptr) {
        temp = temp->next;
        delete node->head;
        node->head = temp;
    }
    delete node;
}

MovieTree::~MovieTree()
{
	//TODO
    rdelete(root);
}

/* -------------------------showMovieCollection----------------------------- */
void MovieTree::printMovieInventoryHelper(TreeNode* t)
{
	//TODO
    if (t->leftChild != nullptr) {
        printMovieInventoryHelper(t->leftChild);
    }
    if (t->head != nullptr) {

        LLMovieNode *m = t->head;
        cout << "Movies starting with letter: " << t->titleChar << endl;
        while (m != nullptr) {
            cout << " >> " << m->title << " " << m->rating << endl;
            m = m->next;
        }
    }
    if (t->rightChild != nullptr) {
        printMovieInventoryHelper(t->rightChild);
    }
}

void MovieTree::showMovieCollection()
{
	//TODO
    if (root != nullptr) {
        printMovieInventoryHelper(root);
    }
}

void addLinkedListNode(TreeNode *t, LLMovieNode *newNode) {
    if (t->head == nullptr) {
        t->head = newNode;
    } else {
        LLMovieNode *prev, *cur;
        for (prev = nullptr, cur = t->head; (cur != nullptr) && (newNode->title > cur->title); prev = cur, cur = cur->next) {
        }

        newNode->next = cur;
        if (prev == nullptr) {
            t->head = newNode;
        } else {
            prev->next = newNode;
        }
    }
}

/* --------------------------insertMovie---------------------------- */
TreeNode* MovieTree::addHelper(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating) {
    char titleChar = _title[0];

    if (root == nullptr) {
        root = new TreeNode;
        root->titleChar = titleChar;
        root->parent = parentpointer;
    } else if (titleChar < root->titleChar) {
        root->leftChild = addHelper(root->leftChild, root, _ranking, _title, _year, _rating);
        return root;
    } else if (titleChar > root->titleChar) {
        root->rightChild = addHelper(root->rightChild, root, _ranking, _title, _year, _rating);
        return root;
    }

    LLMovieNode *movieNode = new LLMovieNode;
    movieNode->ranking = _ranking;
    movieNode->title = _title;
    movieNode->year = _year;
    movieNode->rating = _rating;
    movieNode->next = nullptr;

    addLinkedListNode(root, movieNode);

    return root;
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
    root = addHelper(root, nullptr, ranking, title, year, rating);
}

/* ------------------------removeMovieRecord------------------------------ */
void MovieTree::removeMovieRecord(std::string title)
{
    //TODO
    if (root != nullptr) {
        TreeNode *t = root;
        while (t != nullptr) {
            if (t->titleChar > title[0]) {
                t = t->leftChild;
            } else if (t->titleChar < title[0]) {
                t = t->rightChild; 
            } else {
                LLMovieNode *crawler = t->head;
                LLMovieNode *prev = nullptr;
                while (crawler != nullptr && crawler->title != title) {
                    prev = crawler;
                    crawler = crawler->next;
                }
                if (crawler != nullptr) {
                    if (prev == nullptr) {
                        t->head = crawler->next;
                    } else {
                        prev->next = crawler->next;
                    }
                    delete crawler;
                    return;
                } else {
                    cout << "Movie not found."<< endl;
                    return;
                }
            }
        }
        if (t == nullptr) {
            cout << "Movie not found."<< endl;
        }
    } else {
        cout << "Movie not found."<< endl;
    }
}

/* ------------------------removeBSTNode------------------------------ */
void MovieTree::removeLLnodes(TreeNode* node){
    //TODO
    LLMovieNode *crawler = node->head;
    LLMovieNode *prev = nullptr;
    while (crawler != nullptr) {
        prev = crawler;
        crawler = crawler->next;
        delete prev;
    }
}

TreeNode* MovieTree::getSuccessor(TreeNode* node){
    //TODO
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
}

TreeNode* MovieTree::removeBSTNodeHelper(TreeNode* node, TreeNode* parent, char titleFirstLetter){
    //TODO
    if(node == nullptr)
    {   
        return nullptr;
    }

    //if (node->titleChar == )
    
    // Traverse the left and right
    else if(titleFirstLetter < node->titleChar)
    {
        node->leftChild = removeBSTNodeHelper(node->leftChild, parent, titleFirstLetter);
    }
    else if(titleFirstLetter > node->titleChar)
    {
        node->rightChild = removeBSTNodeHelper(node->rightChild, parent, titleFirstLetter);
    }
    
    // Found node
    else
    {
        // ===== Delete the Node!! =====
        
        // CASE 1: No children
        // TODO: deallocate it and return nullptr
        if (node->leftChild == nullptr && node->rightChild == nullptr) {
            removeLLnodes(node);
            delete node;
            return nullptr;
        }
        
        // CASE 2: 1 child - left child
        // TODO: deallocate it and return left child
        if (node->leftChild != nullptr && node->rightChild == nullptr) {
            TreeNode *left = node->leftChild;
            removeLLnodes(node);
            delete node;
            return left;
        }
        
        // CASE 3: 1 child - right child
        // TODO: deallocate it and return right child
        if (node->leftChild == nullptr && node->rightChild != nullptr) {
            TreeNode *right = node->rightChild;
            removeLLnodes(node);
            delete node;
            return right;
        }
        // CASE 4: 2 children
        // TODO: find replacement node (create helper)
        // TODO: change curr's key to the replacement's key
        // TODO: delete the replacement
        removeLLnodes(node);
        TreeNode *temp = getSuccessor(node->rightChild);
        node->head = temp->head;
        node->titleChar = temp->titleChar;
        temp->head = nullptr;
        node->rightChild = removeBSTNodeHelper(node->rightChild, parent, temp->titleChar);
    }
    
    // To keep the tree connected properly
    return node;
}

void MovieTree::removeBSTNode(char titleFirstLetter){
    //TODO
    root = removeBSTNodeHelper(root, nullptr, titleFirstLetter);
}


/* --------------------------rightRotation---------------------------- */
void MovieTree::rightRotation(TreeNode* curr)
{
	//TODO
    TreeNode *left = curr->leftChild;
    if (left != nullptr) {
        left->parent = curr->parent;
        curr->parent = left;
        curr->leftChild = left->rightChild;
        left->rightChild = curr;
        if (root == curr) {
            root = left;
        } else {
            if (curr->titleChar < left->parent->titleChar) {
                left->parent->leftChild = left;
            } else {
                left->parent->rightChild = left;
            }
        }
    }
}
