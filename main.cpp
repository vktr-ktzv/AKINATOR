#include "AKINATOR.h"

int main()
{
    //txSpeak ("\v Костя приезжай \n");
    Node root;
    TreeCtor(&root);

    root.data = "first";
    /*root.right->data = 20;*/
    //root.left->data = 5;

    root.right = make_a_node ("third");
    root.left  = make_a_node ("second");

    root.right->right = make_a_node ("fourth");

    FILE* fp = fopen("Print_node.txt", "w");
    Print_node (&root, fp);

    Node* root_2 = make_a_node("FiRsT");

    Reading_function (root_2, fp);

    fclose(fp);

    printf("pointer on right - %p\nright data - %s\n", root.right , root.right->data);

    //printf("root data - %d,\nleft data - %d,\nright data - %d \n", root.data, root.left->data, root.right->data);
    //printf("find - %p \nRight - %p\n", find(&root, 20), root.right);
    printf("ALL IS OK! \n");

    return 0;
}