#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
    //TODO
    root = nullptr;
}

void destructorHelper(MovieNode *currNode) {
    if (currNode->left != nullptr) {
        destructorHelper(currNode->left);
    }
    if (currNode->right != nullptr) {
        destructorHelper(currNode->right);
    }
    delete currNode;
}

MovieTree::~MovieTree() {
    //TODO
    if (root == nullptr) {
        return;
    }
    destructorHelper(root);
}

void printMovieInventoryHelper(MovieNode *currNode) {
    if (currNode->left != nullptr) {
        printMovieInventoryHelper(currNode->left);
    }
    cout << "Movie: " << currNode->title << " (" << currNode->rating << ")" << endl;
    if (currNode->right != nullptr) {
        printMovieInventoryHelper(currNode->right);
    }
}

void MovieTree::printMovieInventory() {
    //TODO
    if (root == nullptr) {
        cout << "Tree is Empty. Cannot print." << endl;
    } else {
        printMovieInventoryHelper(root);
    }
}

void addMovieNodeHelper(MovieNode *currNode, MovieNode *newNode) {
    if (newNode->title < currNode->title) {
        if (currNode->left == nullptr) {
            currNode->left = newNode;
            return;
        }
        addMovieNodeHelper(currNode->left, newNode);
    } else {
        if (currNode->right == nullptr) {
            currNode->right = newNode;
            return;
        }
        addMovieNodeHelper(currNode->right, newNode);
    }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
    //TODO
    MovieNode *temp = new MovieNode;
    temp->ranking = ranking;
    temp->title = title;
    temp->year = year;
    temp->rating = rating;
    temp->left = nullptr;
    temp->right = nullptr;
    if (root == nullptr) {
        root = temp;
    } else {
        addMovieNodeHelper(root, temp);
    }
}

void findMovieHelper(MovieNode *currNode, string title) {
    if (currNode == nullptr) {
        cout << "Movie not found." << endl;
        return;
    }
    if (title < currNode->title) {
        findMovieHelper(currNode->left, title);
    } else if (title > currNode->title) {
        findMovieHelper(currNode->right, title);
    } else {
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << currNode->ranking << endl;
        cout << "Title  :" << currNode->title << endl;
        cout << "Year   :" << currNode->year << endl;
        cout << "Rating :" << currNode->rating << endl;
    }
}

void MovieTree::findMovie(string title) {
    //TODO
    findMovieHelper(root, title);
}

void queryMoviesHelper(MovieNode *currNode, float rating, int year) {
    if (currNode != nullptr) {
        if ((currNode->rating >= rating) && (currNode->year > year)) {
            cout << currNode->title << " (" << currNode->year << ") " << currNode->rating << endl;
        }
        queryMoviesHelper(currNode->left, rating, year);
        queryMoviesHelper(currNode->right, rating, year);
    }
}

void MovieTree::queryMovies(float rating, int year) {
    //TODO
    if (root == nullptr) {
        cout << "Tree is Empty. Cannot query Movies." << endl;
    } else {
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        queryMoviesHelper(root, rating, year);
    }

}

double averageRatingHelper(MovieNode *currNode, float &sum, int &numNodes) {
    if (currNode == nullptr) {
        return 0.0;
    }
    averageRatingHelper(currNode->left, sum, numNodes);
    sum += currNode->rating;
    numNodes++;
    averageRatingHelper(currNode->right, sum, numNodes);
}

void MovieTree::averageRating() {
    //TODO
    if (root == nullptr) {
        cout << "Average rating:0.0" << endl;
    } else {
        float sum = 0;
        int numNodes = 0;
        averageRatingHelper(root, sum, numNodes);
        cout << "Average rating:" << (sum / numNodes) << endl;
    }
}

void printLevelNodesHelper(MovieNode *currNode, int level) {
    if (currNode == nullptr) {
        return;
    }
    if (level == 0) {
        cout << "Movie: " << currNode->title << " (" << currNode->rating << ")" << endl;
    } else if (level > 0) {
        printLevelNodesHelper(currNode->left, level - 1);
        printLevelNodesHelper(currNode->right, level - 1);
    }
}

void MovieTree::printLevelNodes(int level) {
    //TODO
        printLevelNodesHelper(root, level);

}
