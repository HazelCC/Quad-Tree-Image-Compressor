
/**
 *
 * quadtree (pa3)
 * quadtree.cpp
 * This file will be used for grading.
 *
 */

#include "quadtree.h"
using namespace std;

// Node constructor, given.
quadtree::Node::Node(pair<int, int> ul, int d, RGBAPixel a, double v)
    : upLeft(ul), dim(d), avg(a), var(v), NW(nullptr), NE(nullptr), SE(nullptr), SW(nullptr) {}

// quadtree destructor, given.
quadtree::~quadtree() {
    clear();
}
// quadtree copy constructor, given.
quadtree::quadtree(const quadtree& other) {
    copy(other);
}
// quadtree assignment operator, given.
quadtree& quadtree::operator=(const quadtree& rhs) {
    if (this != &rhs) {
        clear();
        copy(rhs);
    }
    return *this;
}

quadtree::quadtree(PNG& imIn) {
    int dim = 0;
    int h = imIn.height();
    // calculate the dim
    while (h > 1){
        dim++;
        h /=2;
    }
    stats stat = stats(imIn);
    root = buildTree(stat, make_pair(0,0), dim);
}

quadtree::Node* quadtree::buildTree(stats& s, pair<int, int> ul, int dim) {

    Node* node =  new Node (ul, dim, s.getAvg(ul,dim), s.getVar(ul,dim));
    if(dim == 0) {
        return node;
    } else {
        pair<int,int> NW_ul = ul;
        pair<int, int> NE_ul = make_pair(ul.first + pow(2, (dim -1)), ul.second);
        pair<int,int> SW_ul = make_pair(ul.first, pow(2, (dim - 1)) + ul.second);
        pair<int,int> SE_ul = make_pair(ul.first + pow(2, (dim -1)), ul.second + pow(2, dim - 1));
        node->NW = buildTree(s, ul, dim - 1);
        node->NE = buildTree(s, NE_ul, dim - 1);
        node->SE = buildTree(s, SE_ul, dim - 1);
        node->SW = buildTree(s, SW_ul, dim - 1);     
        return node;
    }
}

PNG quadtree::render() const {
    int wh = pow(2, root->dim);
    PNG png(wh, wh);

    stats s = stats(png);
    if (root->NW == nullptr && root->NE == nullptr && root->SW == nullptr && root->SE == nullptr) {
        RGBAPixel px = RGBAPixel(s.getSum('r', root->upLeft, 0), s.getSum('g', root->upLeft, 0), s.getSum('b', root->upLeft, 0));
        *png.getPixel(root->upLeft.first, root->upLeft.second) = px;
    }
    return png;
}


int quadtree::idealPrune(const int leaves) const {
    /* Your code here! */
    return 0;
}

int quadtree::pruneSize(const int tol) const {
    /* Your code here! */
    return 0;
}

void quadtree::prune(const int tol) {
    /* Your code here! */
}

// DONE
void quadtree::clear() {
    clear(root);
}

// clear helper
void quadtree::clear(Node* root){
    if (root->NW != nullptr){
        clear(root->NW);
    }
     if (root->NE != nullptr){
        clear(root->NE);
    }
     if (root->SW != nullptr){
        clear(root->SW);
    } 
    if (root->SE != nullptr){
        clear(root->SE);
    }
    delete(root);
    root = nullptr;
}

// DONE
void quadtree::copy(const quadtree& orig) {
    root = copy(root);
}

// copy helper
quadtree::Node* quadtree::copy(Node* root){
    Node* curr = new Node(root->upLeft,root->dim, root->avg,root->var);
    if (root->NW != nullptr){
        curr->NW = copy(root->NW);
    }
     if (root->NE != nullptr){
        curr->NE = copy(root->NE);
    }
     if (root->SW != nullptr){
        curr->SW = copy(root->SW);
    } 
    if (root->SE != nullptr){
        curr->SE = copy(root->SE);
    }
    return curr;
}

