#include "../include/ast.h"


ast new_node(ast_type type) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = type;
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast new_int(int val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_INT_VAL;
    new_node->int_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast new_double(double val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_DOUBLE_VAL;
    new_node->double_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast new_id(char* id) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_ID;
    new_node->id = id; /// NEEDS TO BE FREED, COMES FROM STRDUP
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast new_printf(char* printf) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_PRINTF;
    new_node->printf = printf; /// NEEDS TO BE FREED, COMES FROM STRDUP
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast new_list(list_type list_type) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_LIST;
    new_node->list_type = list_type;
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ast* get_children(ast node)
{
    if (node == NULL)
    {
        return NULL;
    }

    ast ptr = node->first_child;
    if (ptr == NULL)
    {
        return NULL;
    }

    ast tmp = ptr;
    int nb_children = 0;
    while(ptr != NULL)
    {
        nb_children++;
        ptr = ptr->next;
    }

    ast* children = (ast*)malloc(nb_children * sizeof(ast));
    ptr = tmp;

    int i = 0;
    while(ptr != NULL)
    {
        children[i] = ptr;
        ptr = ptr->next;
        i++;
    }

    return children;
}


void print_ast_aux(ast tree, int depth)
{
    if (tree == NULL)
    {
        return;
    }

    int i;
    for(i = 0; i < depth; i++)
    {
        printf("    ");
    }
    // printf("%s\n", tree->name);
    print_node(tree);

    ast ptr = tree->first_child;
    while(ptr != NULL)
    {
        print_ast_aux(ptr, depth + 1);
        ptr = ptr->next;
    }
}

void print_ast(ast tree)
{
    if (tree == NULL)
    {
        return;
    }

    // printf("%s\n", tree->name);
    print_node(tree);

    ast ptr = tree->first_child;
    while(ptr != NULL)
    {
        print_ast_aux(ptr, 1);
        ptr = ptr->next;
    }
}

/**
 * @brief Fonction interne - libère la mémoire d'un ast
 * 
 * @param tree arbre à libérer
 */
void free_ast(ast tree)
{
    if (tree == NULL)
    {
        return;
    }

    // free children
    ast ptr = tree->first_child;
    while (ptr != NULL)
    {
        ast next_ptr = ptr->next;
        free_ast(ptr);
        ptr = next_ptr;
    }

    // free self
    if (tree->type == AST_ID)
        free(tree->id);
    if (tree->type == AST_PRINTF)
        free(tree->printf);
    free(tree);
}

ast delete_node(ast node)
{
    free_ast(node);
    return NULL;
}

ast delete_children(ast node)
{
    if (node == NULL)
    {
        return node;
    }

    ast ptr = node->first_child;
    while(ptr != NULL)
    {
        ast next = ptr->next;
        delete_node(ptr);
        ptr = next;
    }

    return node;
}

ast add_child_node(node* n, node* child)
{
    if (n == NULL)
    {
        return child;
    }

    if (n->first_child == NULL)
    {
        n->first_child = child;
        child->parent = n;
        return n;
    }

    ast ptr = n->first_child;
    while(ptr->next != NULL)
    {
        printf("seeing next\n");
        ptr = ptr->next;
    }

    ptr->next = child;
    child->prev = ptr;
    printf("child added\n");
    return n;
}

ast add_brother_node(node* n, node* brother) {
    if (n == NULL)
    {
        return brother;
    }

    if (n->next == NULL) {
        n->next = brother;
        return n;
    }

    ast ptr = n->next;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = brother;
    brother->parent = NULL;
    brother->prev = ptr;

    return n;
}

void print_node(ast node) {

    if (node == NULL)
        return;

    switch (node->type) {
        case AST_ID:
            printf("ID (%s)\n", node->id);
            break;  
        case AST_INT:
            printf("TYPE INT\n");
            break;
        case AST_DOUBLE:
            printf("TYPE DOUBLE\n");
            break;
        case AST_INT_VAL:
            printf("INT (%d)\n", node->int_val);
            break;
        case AST_DOUBLE_VAL:
            printf("DOUBLE (%f)\n", node->double_val);
            break;
        case AST_ADD:
            printf("OPERATOR (+)\n");
            break;
        case AST_MUL:
            printf("OPERATOR (*)\n");
            break;
        case AST_DIV:
            printf("OPERATOR (/)\n");
            break;
        case AST_MINUS:
            printf("BINARY (-)\n");
            break;
        case AST_UMINUS:
            printf("UNARY (-)\n");
            break;
        case AST_ASSIGN:
            printf("ASSIGN\n");
            break;
        case AST_WHILE:
            printf("WHILE\n");
            break;
        case AST_IF:
            printf("IF\n");
            break;
        case AST_MAIN:
            printf("MAIN\n");
            break;
        case AST_INC:
            printf("++\n");
            break;
        case AST_DEC:
            printf("--\n");
            break;
        case AST_RETURN:
            printf("RETURN\n");
            break;
        case AST_FOR:
            printf("FOR\n");
            break;
        case AST_AND_OP:
            printf("OPERATOR (&&)\n");
            break;
        case AST_OR_OP:
            printf("OPERATOR (||)\n");
            break;
        case AST_GEQ_OP:
            printf("OPERATOR (>=)\n");
            break;
        case AST_LEQ_OP:
            printf("OPERATOR (<=)\n");
            break;
        case AST_GT_OP:
            printf("OPERATOR (>)\n");
            break;
        case AST_LT_OP:
            printf("OPERATOR (<)\n");
            break;
        case AST_NEQ_OP:
            printf("OPERATOR (!=)\n");
            break;
        case AST_EQ_OP:
            printf("OPERATOR (==)\n");
            break;
        case AST_STAT:
            printf("STATEMENT\n");
            break;
        case AST_TABLE:
            printf("TABLE\n");
            break;
        case AST_DIM:
            printf("DIMENSIONS\n");
            break;
        case AST_ARRAY:
            printf("ARRAY\n");
            break;
        case AST_PRINTF:
            printf("PRINTF : %s \n", node->printf);
            break;
        case AST_LIST:
            print_list(node->list_type);
            break;
        default:
            printf("UNDEFINED %d\n", node->type);
            break;
    }
}


void indent_code(int indent) {
    int i;
    for(i = 0; i < indent; i++)
    {
        printf("    ");
    }
}


void print_code(ast tree, int indent)
{
    ast ptr;
    if (tree == NULL)
    {
        return;
    }

    switch (tree->type) {
        case AST_MAIN:
            printf("int main() {\n");
            print_code(tree->first_child, indent+1);
            printf("}\n");
            break;
        case AST_STAT:
            indent_code(indent);
            print_code(tree->first_child, indent);
            if (tree->first_child->type != AST_PRINTF )
                printf(";\n");
            break;
        case AST_LIST:
            // afficher tous les fils de la liste
            if (tree->first_child != NULL) {
                print_code(tree->first_child, indent);
                ptr = tree->first_child;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                    // TODO : RAJOUTER IF POUR SWITCH SEPARATEUR EN FONCTION DU TYPE 
                    // DE LA LISTE
                    if (tree->list_type != LIST_STAT)
                        printf(", ");
                    print_code(ptr, indent);
                }
            }
            break;
        case AST_INT:
            printf("int ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                printf(", ");
                print_code(ptr, indent);
            }
            break;
        case AST_DOUBLE:
            printf("double ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                printf(", ");
                print_code(ptr, indent);
            }
            break;
        case AST_INT_VAL:
            printf("%d", tree->int_val);
            break;
        case AST_DOUBLE_VAL:
            printf("%f", tree->double_val);
            break;
        case AST_ASSIGN:
            print_code(tree->first_child, 0);
            printf(" = ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_ADD:
        // Avant modif : pourquoi modif ?
            printf("(");
            print_code(tree->first_child, 0);
            printf(" + ");
            print_code(tree->first_child->next, 0);
            printf(")");
            break;
        case AST_MUL:
            print_code(tree->first_child, 0);
            printf(" * ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_DIV:
            print_code(tree->first_child, 0);
            printf(" / ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_MINUS:
            printf("(");
            print_code(tree->first_child, 0);
            printf(" - ");
            print_code(tree->first_child->next, 0);
            printf(")");
            break;
        case AST_AND_OP:
            printf("(");
            print_code(tree->first_child, 0);
            printf(" && ");
            print_code(tree->first_child->next, 0);
            printf(")");
            break;
        case AST_OR_OP:
            printf("(");
            print_code(tree->first_child, 0);
            printf(" || ");
            print_code(tree->first_child->next, 0);
            printf(")");
            break;
        case AST_GEQ_OP:
            print_code(tree->first_child, 0);
            printf(" >= ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_LEQ_OP:
            print_code(tree->first_child, 0);
            printf(" <= ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_GT_OP:
            print_code(tree->first_child, 0);
            printf(" > ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_LT_OP:
            print_code(tree->first_child, 0);
            printf(" < ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_NEQ_OP:
            print_code(tree->first_child, 0);
            printf(" != ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_EQ_OP:
            print_code(tree->first_child, 0);
            printf(" == ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_IF:
            printf("if ( ");                            // if
            print_code(tree->first_child, indent);      // condition
            printf(" ) {\n");                           
            ast second_child = tree->first_child->next;
            print_code(second_child, indent+1);  // body
            if(second_child->next != NULL) {     // else body
                indent_code(indent);
                printf("} else {\n");
                print_code(tree->first_child->next->next, indent+1);
            }
            indent_code(indent);
            printf("}");
            break;
        case AST_WHILE:
            printf("while ( ");
            print_code(tree->first_child, 0);
            printf(" ) {\n");
            print_code(tree->first_child->next, indent+1);
            indent_code(indent);
            printf("}");
            break;
        case AST_FOR:
            printf("for ( ");
            print_code(tree->first_child, 0);
            printf("; ");
            ast condition = tree->first_child->next;
            print_code(condition, 0);
            printf("; ");
            ast update = condition->next;
            print_code(update, 0);
            printf(" ) {\n");
            ast body = update->next;
            print_code(body, indent+1);
            indent_code(indent);
            printf("}");
            break;
        case AST_TABLE:
            print_code(tree->first_child, 0);       // table ID
            print_code(tree->first_child->next, 0); // table DIMENSIONS
            break;
        case AST_DIM:
            // print all dimensions
            printf("[");
            print_code(tree->first_child, indent);
            printf("]");
            ast ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                printf("[");
                print_code(ptr, indent);
                printf("]");
            }
            break;
        case AST_INC:
            print_code(tree->first_child, 0);
            printf("++");
            break;
        case AST_DEC:
            print_code(tree->first_child, 0);
            printf("--");
            break;
        case AST_ID:
            printf("%s", tree->id);
            break;  
        case AST_PRINTF:
            printf("%s\n", tree->printf);
            break;
        case AST_UMINUS:
            printf("-");
            print_code(tree->first_child, 0);
            break;
        case AST_RETURN:
            printf("return ");
            print_code(tree->first_child, 0);
            break;
        case AST_ARRAY:
            printf(" { ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {   
                ptr = ptr->next;
                if (ptr->type == AST_INT_VAL) {
                    printf(", ");
                }
                print_code(ptr, indent);
            }
            printf(" } ");
            break;
        default:
            printf("ERROR");
    }

    return;
}

int count_child(ast node) {
    int count = 0;

    if (node == NULL) {
        return count;
    }

    if (node->first_child == NULL)
    {
        return count;
    }
    count++;

    ast ptr = node->first_child;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    return count;
}

void print_list(list_type list) {
    printf("LIST ");
    switch (list) {
        case LIST_COND:
            printf("( CONDITIONS )");
            break;
        case LIST_STAT:
            printf("( STATEMENTS )");
            break;
        case LIST_INIT:
            printf("( INITIALISATIONS )");
            break;
        case LIST_UPDATE:
            printf("( UPDATES )");
            break;
        default:
            printf("UNDEFINED");
    }
    printf("\n");
}

void swap_nodes(node* n1, node* n2) {
    node *parent = NULL;
    node *tmp_next;
    node *tmp_prev;

    if (n1 == NULL || n2 == NULL)
        return;

    // si n1 est le premier fils
    if (n1->parent != NULL) {
        parent = n1->parent;
        parent->first_child = n2; // n2 devient le premier fils
    }

    // si n2 est le premier fils
    if (n2->parent != NULL) {
        parent = n2->parent;
        parent->first_child = n1; // n1 devient le premier fils
    }

    if (n1->next == n2) { // si consécutifs
        n1->next = n2->next;
        n2->prev = n1->prev;

        if (n1->next != NULL)
            n1->next->prev = n1;

        if (n2->prev != NULL)
            n2->prev->next = n2;


        n2->next = n1;
        n1->prev = n2;
    } else {
        if (n1->next != NULL)
            n1->next->prev = n2;
        if (n1->prev != NULL)
            n1->prev->next = n2;

        if (n2->next != NULL)
            n2->next->prev = n1;
        if (n2->prev != NULL)
            n2->prev->next = n1;

        tmp_next = n2->next;
        tmp_prev = n2->prev;

        n2->prev = n1->prev;
        n2->next = n1->next;

        n1->prev = tmp_prev;
        n1->next = tmp_next;
    }
}


int compare(ast tree1, ast tree2)
{
    if (tree1 == NULL)
    {
        return tree2 == NULL;
    }

    if (tree2 == NULL)
    {
        return tree1 == NULL;
    }

    if (tree1->type == tree2->type)
    {
        ast ptr1 = tree1->first_child;
        ast ptr2 = tree2->first_child;

        while(ptr1 != NULL && ptr2 != NULL)
        {
            if (compare(ptr1, ptr2) != 0)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else
            {
                return 0;
            }
        }

        if (ptr1 != ptr2)
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}