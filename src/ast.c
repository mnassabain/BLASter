#include "../include/ast.h"

extern FILE* output_d;

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

    printf("nb_child = %d", nb_children);
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
    // fprintf(output_d, "%s\n", tree->name);
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

    // fprintf(output_d, "%s\n", tree->name);
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

    node->first_child = NULL;
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
        ptr = ptr->next;
    }

    ptr->next = child;
    child->prev = ptr;
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
        case AST_VOID:
            printf("TYPE VOID \n");
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
        case AST_FUNC:
            printf("FUNCTION \n");
            break;
        case AST_CALL:
            printf("CALL : %s\n", node->id);
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
        fprintf(output_d, "    ");
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
            fprintf(output_d, "int main() {\n");
            print_code(tree->first_child, indent+1);
            fprintf(output_d, "}\n");
            break;
        case AST_STAT:
            indent_code(indent);
            print_code(tree->first_child, indent);
            if (tree->first_child->type != AST_PRINTF )
                fprintf(output_d, ";\n");
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
                    if (tree->list_type != LIST_STAT && tree->list_type != LIST_FUNC)
                        fprintf(output_d, ", ");
                    print_code(ptr, indent);
                }
            }
            break;
        case AST_INT:
            fprintf(output_d, "int ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                fprintf(output_d, ", ");
                print_code(ptr, indent);
            }
            break;
        case AST_DOUBLE:
            fprintf(output_d, "double ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                fprintf(output_d, ", ");
                print_code(ptr, indent);
            }
            break;
        case AST_VOID:
            fprintf(output_d, "void ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                fprintf(output_d, ", ");
                print_code(ptr, indent);
            }
            break;
        case AST_INT_VAL:
            fprintf(output_d, "%d", tree->int_val);
            break;
        case AST_DOUBLE_VAL:
            fprintf(output_d, "%f", tree->double_val);
            break;
        case AST_ASSIGN:
            print_code(tree->first_child, 0);
            fprintf(output_d, " = ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_ADD:
        // Avant modif : pourquoi modif ?
            fprintf(output_d, "(");
            print_code(tree->first_child, 0);
            fprintf(output_d, " + ");
            print_code(tree->first_child->next, 0);
            fprintf(output_d, ")");
            break;
        case AST_MUL:
            print_code(tree->first_child, 0);
            fprintf(output_d, " * ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_DIV:
            print_code(tree->first_child, 0);
            fprintf(output_d, " / ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_MINUS:
            fprintf(output_d, "(");
            print_code(tree->first_child, 0);
            fprintf(output_d, " - ");
            print_code(tree->first_child->next, 0);
            fprintf(output_d, ")");
            break;
        case AST_AND_OP:
            fprintf(output_d, "(");
            print_code(tree->first_child, 0);
            fprintf(output_d, " && ");
            print_code(tree->first_child->next, 0);
            fprintf(output_d, ")");
            break;
        case AST_OR_OP:
            fprintf(output_d, "(");
            print_code(tree->first_child, 0);
            fprintf(output_d, " || ");
            print_code(tree->first_child->next, 0);
            fprintf(output_d, ")");
            break;
        case AST_GEQ_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " >= ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_LEQ_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " <= ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_GT_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " > ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_LT_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " < ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_NEQ_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " != ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_EQ_OP:
            print_code(tree->first_child, 0);
            fprintf(output_d, " == ");
            print_code(tree->first_child->next, 0);
            break;
        case AST_IF:
            fprintf(output_d, "if ( ");                            // if
            print_code(tree->first_child, indent);      // condition
            fprintf(output_d, " ) {\n");                           
            ast second_child = tree->first_child->next;
            print_code(second_child, indent+1);  // body
            if(second_child->next != NULL) {     // else body
                indent_code(indent);
                fprintf(output_d, "} else {\n");
                print_code(tree->first_child->next->next, indent+1);
            }
            indent_code(indent);
            fprintf(output_d, "}");
            break;
        case AST_WHILE:
            fprintf(output_d, "while ( ");
            print_code(tree->first_child, 0);
            fprintf(output_d, " ) {\n");
            print_code(tree->first_child->next, indent+1);
            indent_code(indent);
            fprintf(output_d, "}");
            break;
        case AST_FOR:
            fprintf(output_d, "for ( ");
            print_code(tree->first_child, 0);
            fprintf(output_d, "; ");
            ast condition = tree->first_child->next;
            print_code(condition, 0);
            fprintf(output_d, "; ");
            ast update = condition->next;
            print_code(update, 0);
            fprintf(output_d, " ) {\n");
            ast body = update->next;
            print_code(body, indent+1);
            indent_code(indent);
            fprintf(output_d, "}");
            break;
        case AST_TABLE:
            print_code(tree->first_child, 0);       // table ID
            print_code(tree->first_child->next, 0); // table DIMENSIONS
            break;
        case AST_DIM:
            // print all dimensions
            fprintf(output_d, "[");
            print_code(tree->first_child, indent);
            fprintf(output_d, "]");
            ast ptr = tree->first_child;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                fprintf(output_d, "[");
                print_code(ptr, indent);
                fprintf(output_d, "]");
            }
            break;
        case AST_INC:
            print_code(tree->first_child, 0);
            fprintf(output_d, "++");
            break;
        case AST_DEC:
            print_code(tree->first_child, 0);
            fprintf(output_d, "--");
            break;
        case AST_ID:
            fprintf(output_d, "%s", tree->id);
            break;  
        case AST_PRINTF:
            fprintf(output_d, "%s\n", tree->printf);
            break;
        case AST_UMINUS:
            fprintf(output_d, "-");
            print_code(tree->first_child, 0);
            break;
        case AST_RETURN:
            fprintf(output_d, "return ");
            print_code(tree->first_child, 0);
            break;
        case AST_ARRAY:
            fprintf(output_d, " { ");
            print_code(tree->first_child, indent);
            ptr = tree->first_child;
            while(ptr->next != NULL)
            {   
                ptr = ptr->next;
                if (ptr->type == AST_INT_VAL) {
                    fprintf(output_d, ", ");
                }
                print_code(ptr, indent);
            }
            fprintf(output_d, " } ");
            break;
        case AST_FUNC:
            if (count_child(tree) == 3) { // définition de fonction
                print_code(tree->first_child, 0);
                fprintf(output_d, " ( ");
                print_code(tree->first_child->next, 0);
                fprintf(output_d, " ) {\n");
                print_code(tree->first_child->next->next, indent+1);
                fprintf(output_d, "}\n");
            } else { // utilisation de fonction
                print_code(tree->first_child, 0); // nom
                fprintf(output_d, " ( ");
                print_code(tree->first_child->next, 0); // paramètres
                fprintf(output_d, " ) ");
            }
            break;
        case AST_CALL:
            fprintf(output_d, "%s(", tree->id);
            print_code(tree->first_child, 0);
            fprintf(output_d, ")");
            break;
        default:
            fprintf(output_d, "ERROR");
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
        case LIST_FUNC:
            printf("( FUNCTIONS )");
            break;
        case LIST_ARG:
            printf("( ARGS )");
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


void replace(ast tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->type == AST_ASSIGN)
    {
        // MULAC
        if (tree->first_child->type == AST_ID
         && tree->first_child->next->type == AST_ADD
         && tree->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->first_child->next->type == AST_MUL
         && tree->first_child->next->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->first_child->next->first_child->next->type == AST_ID
        )
        {
            ast arg_list = new_list(LIST_ARG);
            char * arg1_name = malloc(128);
            arg1_name[0] = '&';
            arg1_name[1] = '\0';
            ast arg1 = new_id(strcat(arg1_name, tree->first_child->id));
            ast arg2 = new_id(strdup(tree->first_child->next->first_child->id));
            ast arg3 = new_id(strdup(tree->first_child->next->first_child->next->first_child->id));
            ast arg4 = new_id(strdup(tree->first_child->next->first_child->next->first_child->next->id));
            
            delete_children(tree);
            
            add_child_node(arg_list, arg1);
            add_child_node(arg_list, arg2);
            add_child_node(arg_list, arg3);
            add_child_node(arg_list, arg4);

            tree->type = AST_CALL;
            tree->id = malloc(256);
            strcpy(tree->id, "mulac");
            add_child_node(tree, arg_list);
        }
    }
    else if (tree->type == AST_FOR) {
        // level 1
        if (tree->first_child->type == AST_LIST
         && tree->first_child->list_type == LIST_INIT
         && tree->first_child->first_child->type == AST_INT
         && tree->first_child->first_child->first_child->type == AST_ASSIGN
         && tree->first_child->first_child->first_child->first_child->type == AST_ID
         // && tree->first_child->first_child->first_child->first_child->next->type == AST_ID
         && tree->first_child->next->type == AST_LIST
         && tree->first_child->next->list_type == LIST_COND
         && tree->first_child->next->first_child->type == AST_LT_OP ///////////////////////////////////
         && tree->first_child->next->first_child->first_child->type == AST_ID
         && tree->first_child->next->first_child->first_child->next->type == AST_ID
         && tree->first_child->next->next->type == AST_LIST
         && tree->first_child->next->next->list_type == LIST_UPDATE
         && tree->first_child->next->next->first_child->type == AST_INC
         && tree->first_child->next->next->first_child->first_child->type == AST_ID
         && tree->first_child->next->next->next->type == AST_LIST
         && tree->first_child->next->next->next->list_type == LIST_STAT
         && tree->first_child->next->next->next->first_child->type == AST_STAT
         && tree->first_child->next->next->next->first_child->first_child->type == AST_ASSIGN
         && tree->first_child->next->next->next->first_child->first_child->first_child->type == AST_TABLE
         && tree->first_child->next->next->next->first_child->first_child->first_child->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->first_child->next->type == AST_DIM
         && tree->first_child->next->next->next->first_child->first_child->first_child->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->type == AST_ADD
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->type == AST_MUL
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->first_child->next->type == AST_TABLE
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->first_child->next->first_child->next->type == AST_DIM
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->first_child->next->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->next->type == AST_TABLE
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->next->first_child->type == AST_ID
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->next->first_child->next->type == AST_DIM
         && tree->first_child->next->next->next->first_child->first_child->first_child->next->first_child->next->first_child->next->first_child->type == AST_ID
        ) {
            tree->type = AST_ID;
            tree->id = malloc(128);
            strcpy(tree->id, "axpy(...)");
            delete_children(tree);
        }
    }
    else {
        ast ptr = tree->first_child;
        while(ptr != NULL)
        {
            replace(ptr);
            ptr = ptr->next;
        }
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

int compare_real(ast tree1, ast tree2)
{
    // printf("PRINTING ptr1\n");
    // print_ast(tree1);
    // printf("PRINTING ptr2\n");
    // print_ast(tree2);
    // printf("\n\n");
    int return_val = 1;

    if (tree1 == NULL)
    {
        return tree2 == NULL;
    }

    if (tree2 == NULL)
    {
        return tree1 == NULL;
    }

    if (tree1->type == AST_INT || tree1->type == AST_DOUBLE) {
        tree1 = tree1->first_child;
    }
    if (tree2->type == AST_INT || tree2->type == AST_DOUBLE) {
        tree2 = tree2->first_child;
    }
    // if (tree1->type == AST_ADD  || tree1->type == AST_ADD  || tree1->type == AST_DIV || tree1->type == AST_MUL) {
        
    // }
    // if (tree1->type == AST_ASSIGN && tree2->type == AST_ASSIGN)
    //     return 1;
    if (tree1->type == AST_ID && (tree2->type == AST_INT_VAL || tree2->type == AST_DOUBLE_VAL) ) {
        return 1;
    }
    if (tree2->type == AST_ID && (tree1->type == AST_INT_VAL || tree1->type == AST_DOUBLE_VAL) ) {
        return 1;
    }
    // if (tree1->type == AST_ID && (tree2->type == AST_ADD || tree2->type == AST_MUL || tree2->type == AST_DIV || tree2->type == AST_MINUS ) ) {
    //     return 1;
    // }
    // if (tree2->type == AST_ID && (tree1->type == AST_ADD || tree1->type == AST_MUL || tree1->type == AST_DIV || tree1->type == AST_MINUS ) ) {
    //     return 1;
    // }

    if (tree1->type == AST_LT_OP && tree2->type == AST_LT_OP)
        return 1;
    if (tree1->type == AST_GT_OP && tree2->type == AST_GT_OP)
        return 1;

    // après traitements
    if (tree1->type != tree2->type) {
        // printf("diff\n");
        // print_ast(tree1);
        // print_ast(tree2);
        return 0;
    }
    // printf("equal nodes\n");

    ast ptr1 = tree1->first_child;
    ast ptr2 = tree2->first_child;
    while(ptr1 != NULL && ptr2 != NULL)
    {   
        // compare childrens
        // printf("here\n");
        if ( compare_real(ptr1, ptr2) == 1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else {
            return 0;
        }
    }

    return return_val;
}

// searching branch in the tree
ast recursive_search(ast tree, ast branch) {

    if (tree == NULL)
        return NULL;

    if (compare_real (tree, branch))
        return tree;

    ast ptr = tree->first_child;
    ast found;
    while(ptr != NULL) {
        if ( (found = recursive_search(ptr, branch)) != NULL )
            return found;
        else
            ptr = ptr->next;
    }
    return NULL;
}

void replace_node(node* old_node, node* new_node) {

    if (old_node->parent != NULL) {
        new_node->parent = old_node->parent;
        old_node->parent->first_child = new_node;
        new_node->next = old_node->next;
        printf("first child\n");
    }

    if (old_node->prev != NULL) {
        old_node->prev->next = new_node;
        printf("brother\n");
    }

    delete_node(old_node);
}