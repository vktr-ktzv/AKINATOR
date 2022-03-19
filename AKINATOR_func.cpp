#include "AKINATOR.h"

int TreeCtor (Node* root)
{
    root->data = "";

    /*root->left = (Node*)calloc(1, sizeof(Node));  
    root->right = (Node*)calloc(1, sizeof(Node));*/

    return 0; 
};

int TreeDctor (Node* root)
{

};

/*Node* find (Node* root, int value)
{
    Node* node = root;

    while (node)
    {
        if (node->data == value)
            return node;
        
        if (node->data < value)
            node = node->right;

        else node = node->left;
    }

    return nullptr;
};

Node* make_a_node_auto (Node* dad_node, int branch, const char* str)
{
    if (branch == ADD_RIGHT)
    {
        printf(">>> MAKING A RIGHT BRANCH<<<<\n\n");
        dad_node->left = (Node*)calloc(1, sizeof(Node));
        dad_node->left->data = value;

        return dad_node->left;
    } 

    if (branch == ADD_LEFT) 
    {
        printf(">>> MAKING A RIGHT BRANCH<<<<\n\n");
        dad_node->right = (Node*)calloc(1, sizeof(Node));
        dad_node->left->data = value;

        return dad_node->right;
    } 

    return nullptr; 

};*/

Node* make_a_node (const char* str)
{
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    new_node->data = (const char*)calloc(strlen(str), sizeof(const char));
    new_node->data = str;

    printf(">>> NEW_NODE PTR === %p\n\n", new_node);
    printf(">>> STR === %s <<<>>> new_node->data === %s\n\n", str, new_node->data);

    return new_node; 
};

int Print_node (Node* node, FILE* fp )
{
    assert (node);

    fprintf (fp, "{\n");

    fprintf (fp, "%s\n", node->data);

    if (node->left)
        Print_node (node->left, fp);
    
    if (node->right)
        Print_node (node->right, fp);

    fprintf(fp, "}\n");
}

int Reading_function (Node* node, FILE* fp)
{
    if (fgetc(fp) == '{')
    {
        printf("SMTH WENT WRONG\n\n");
    }

    fgetc(fp);

    if(fgetc(fp) == '{')
    {
        fgetc(fp);

         char str[30] = {0};
    
        fscanf(fp,"%s", &str);
        fgetc(fp);
        printf(">>>> STR_IN_READ === %s\n\n", str);
        node = make_a_node(str);
    }

    printf (">>>> NODE DATA ==== %s\n", node->data);

    if (node->left)
    {
        Reading_function(node->left, fp);
        printf (">>> LEFT DONE\n\n");
    } 

    if (node->right)
    {
        Reading_function(node->right, fp);
        printf (">>> RIGHT DONE\n\n");
    }

    return 0;
};