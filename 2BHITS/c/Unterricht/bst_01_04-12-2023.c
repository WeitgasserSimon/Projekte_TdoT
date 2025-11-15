/**
 * @brief Binary search tree
 * @author Simon Weitgasser
 * @date 2023-12-04
 */
#include <stdio.h>
#include <stdlib.h>
 
//Datenstruktur für einen Knoten (root, node, leaf)
typedef struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
} treenode_t;
 
// Datenstruktur für den Baum
typedef struct tree {
    int element;
    treenode_t* root;
} tree_t;
//Funktionsprototype
tree_t* createTree();
treenode_t* createTreeNode(int data);
void insertTreeNode(tree_t* tree, int data);
void traverseInOrder(treenode_t* treenode);
void generateDotFile(struct treenode* root);
void generateDot(struct treenode* root, int* nullcount, FILE* dotFile);
void printTree(tree_t* tree);
 
int main () {
    //Einen leeren Baum erzeugen
    tree_t* tree = createTree();
    //Knoten einfügen
    insertTreeNode(tree, 55);
    insertTreeNode(tree, 31);
    insertTreeNode(tree, 69);
    insertTreeNode(tree, 99);
    insertTreeNode(tree, 12);
    insertTreeNode(tree, 41);
    printTree(tree);
    return EXIT_SUCCESS;
}
tree_t* createTree(){
    tree_t* tree = malloc(sizeof(tree_t));
    if(NULL == tree){
        printf("Could not create tree!\n");
        exit(EXIT_FAILURE);
    }
    tree->element = 0;
    tree->root = NULL;
    return tree;
}
 
treenode_t* createTreeNode(int data){
    treenode_t* treenode = malloc(sizeof(treenode_t));
    if(NULL == treenode){
        printf("Could not create Treenode %i\n",data);
    }
    treenode->data = data;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}
void insertTreeNode(tree_t* tree, int data){
    treenode_t* treenode = createTreeNode(data);
    if(NULL == treenode){
        printf("Could not insert treenode %i\n", data);
        return;
    }
    if(tree->root == NULL){
        tree->root = treenode;
        //tree->element++;
    }else{
        treenode_t* current = tree->root;
        while (1) {
            if(data <= current->data){
                if(current->left == NULL){
                    current->left = treenode;
                    //tree->element++;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if(current->right == NULL){
                    current->right = treenode;
                    //tree->element++;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    tree->element++;
}
 
void traverseInOrder(treenode_t* treenode){
    if(treenode != NULL){
        traverseInOrder(treenode->left);
        printf("%i ", treenode->data);
        traverseInOrder(treenode->right);
    }
   
}
void printTree(tree_t* tree) {
    printf("Ausgabe des baums mit %i Elementen: \n", tree->element);
    traverseInOrder(tree->root);
    printf("\n");
}
 
void generateDotFile(struct treenode* root) {
 
    // Open a DOT file for writing
    FILE* dotFile = fopen("bst.dot", "w");
    if (NULL == dotFile) {
        perror("Unable to create DOT file");
        return;
    }
 
    // Write the DOT header
    fprintf(dotFile, "digraph BST {\n");
    fprintf(dotFile, "node [shape=circle];\n");
 
    // Generate the DOT representation of the BST
    int nullcount = 0;
    generateDot(root, &nullcount, dotFile);
 
    // Close the DOT file
    fprintf(dotFile, "}\n");
    fclose(dotFile);
 
    // Use Graphviz to generate the graphical representation
    system("dot -Tpng bst.dot -o bst.png");
 
    return;
}
 
void generateDot(struct treenode* root, int* nullcount, FILE* dotFile) {
    if (root == NULL) {
        return;
    }
 
    fprintf(dotFile, "%d;\n", root->data);
 
    if (root->left != NULL) {
        fprintf(dotFile, "%d -> %d;\n", root->data, root->left->data);
        generateDot(root->left, nullcount, dotFile);
    } else {
        fprintf(dotFile, "n%d [label=\"\",style=invis];\n", *nullcount);
        fprintf(dotFile, "%d -> n%d [style=invis];\n", root->data, (*nullcount)++);
    }
 
    if (root->right != NULL) {
        fprintf(dotFile, "%d -> %d;\n", root->data, root->right->data);
        generateDot(root->right, nullcount++, dotFile);
    } else {
        fprintf(dotFile, "n%d [label=\"\",style=invis];\n", *nullcount);
        fprintf(dotFile, "%d -> n%d [style=invis];\n", root->data, (*nullcount)++);
    }
}