#include "../include/ast.h"


ast new_node(ast_type type) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = type;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_int(int val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_INT_VAL;
    new_node->int_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_double(double val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_DOUBLE_VAL;
    new_node->double_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_id(char* id) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_ID;
    new_node->id = id; /// NEEDS TO BE FREED, COMES FROM STRDUP
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_printf(char* printf) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_PRINTF;
    new_node->printf = printf; /// NEEDS TO BE FREED, COMES FROM STRDUP
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_list(list_type list_type) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_LIST;
    new_node->list_type = list_type;
    new_node->first_child = NULL;
    new_node->next = NULL;

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
        return n;
    }

    ast ptr = n->first_child;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = child;

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
        case AST_ELSE:
            printf("ELSE\n");
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


/**
 * @brief Fonction auxiliaire utilisée par print_code
 * 
 * @param node noeud à afficher en code
 */
void print_code_node(ast node)
{
    if (node == NULL)
        return;

    switch (node->type) {
        case AST_ID:
            printf("%s", node->id);
            break;  
        case AST_INT:
            printf("int ");
            break;
        case AST_DOUBLE:
            printf("double ");
            break;
        case AST_INT_VAL:
            printf("%d", node->int_val);
            break;
        case AST_DOUBLE_VAL:
            printf("%f", node->double_val);
            break;
        case AST_ADD:
            printf("+");
            break;
        case AST_MUL:
            printf("*");
            break;
        case AST_DIV:
            printf("/");
            break;
        case AST_MINUS:
            printf("-");
            break;
        case AST_UMINUS:
            printf("-");
            break;
        case AST_ASSIGN:
            // printf("=");
            break;
        case AST_WHILE:
            printf("while");
            break;
        case AST_ELSE:
            printf("else");
            break;
        case AST_INC:
            printf("++");
            break;
        case AST_DEC:
            printf("--");
            break;
        case AST_RETURN:
            printf("return");
            break;
        case AST_FOR:
            printf("for");
            break;
        case AST_AND_OP:
            printf("&&");
            break;
        case AST_OR_OP:
            printf("||");
            break;
        case AST_GEQ_OP:
            printf(">=");
            break;
        case AST_LEQ_OP:
            printf("<=");
            break;
        case AST_GT_OP:
            printf(">");
            break;
        case AST_LT_OP:
            printf("<");
            break;
        case AST_NEQ_OP:
            printf("!=");
            break;
        case AST_EQ_OP:
            printf("==");
            break;
        case AST_TABLE:
            // printf("TABLE");
            break;
        case AST_DIM:
            // printf("DIMENSIONS");
            break;
        case AST_ARRAY:
            // printf("ARRAY");
            break;
        case AST_PRINTF:
            printf("%s\n", node->printf);
            break;
        case AST_LIST:
            // printf();
            break;
        default:
            printf("UNDEFINED %d", node->type);
            break;
    }
    // printf("\n");
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

            break;
        default:
            print_code_node(tree);
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
