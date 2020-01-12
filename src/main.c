#include <stdio.h>
#include <getopt.h>
#include "ast.h"
#include "y.tab.h"
#include "specParser.h"

int DEBUG_LEX = 0;
int opt_print_ast = 0;
int opt_print_symbol_table = 0;

extern FILE* yyin;
extern FILE* zzin;
extern ast arbre;
extern ast specTree;
extern void lex_zzfree();   // lexer spec
extern void lex_yyfree();   // lexer file

char * output_file = NULL;
FILE* output_d;

int options(int argc, char** argv);

int main (int argc, char** argv) {

    int idx = options(argc, argv);

    if (output_file != NULL) {
        output_d = fopen(output_file, "w");
        if (output_d == NULL) {
            fprintf(stderr, "Unable to open file %s", output_file);
        return 1;
    }
    } else {
        output_d = stdout;
    }
    
    char* input_source = argv[idx];
    char* specif_source = argv[idx+1];

    FILE* input = fopen (input_source, "r");
    // FILE* f = fopen ("exemple.c", "r");
    if (input == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = input;
    yyparse(); // parse source code

    // Affichage de l'arbre 
    // print_ast(arbre);
    print_code(arbre, 0);

    replace(arbre);

    print_code(arbre, 0);

    ////////////////////////////////////////////////////////////////////////////


    // FILE* spec = fopen ("spec.c", "r");
    // FILE* f = fopen ("exemple.c", "r");
    FILE* spec = fopen(specif_source, "r");
    if (spec == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    zzin = spec;

    // zzparse();

    // print_ast(specTree);
    // print_code(specTree, 0);
    
    
    // Clean
    delete_node(arbre);
    delete_node(specTree);
    lex_zzfree();
    lex_yyfree();
    fclose(input);
    fclose(spec);

    return 0;
}

int options (int argc, char** argv) {
    printf("\n888888b.   888             d8888  .d8888b.  888\n");                    
    printf("888  \"88b  888            d88888 d88P  Y88b 888\n");                    
    printf("888  .88P  888           d88P888 Y88b.      888\n");                    
    printf("8888888K.  888          d88P 888  \"Y888b.   888888 .d88b.  888d888\n");  
    printf("888  \"Y88b 888         d88P  888     \"Y88b. 888   d8P  Y8b 888P\"\n");    
    printf("888    888 888        d88P   888       \"888 888   88888888 888\n");      
    printf("888   d88P 888       d8888888888 Y88b  d88P Y88b. Y8b.     888\n");      
    printf("8888888P\"  88888888 d88P     888  \"Y8888P\"   \"Y888 \"Y8888  888\n");
    printf("\n888888888888888888888888888888888888888888888888888888888888888888\n\n");

    int opt, optindex = 0;
    struct option options[] = {
        {"version", no_argument, 0, 'v' },
        {"tos", no_argument, 0, 't' },
        {"ast", no_argument, 0, 'a' },
        {"output", no_argument, 0, 'o' }
    };

    while((opt = getopt_long(argc, argv, "vtao:", options, &optindex)) != -1)
    {   
        printf("%d", optindex);
        switch(opt)
        {
            case 'v':
                printf("Membres du projet:\n");
                printf(" * CHRISTOFFEL Quentin\n");
                printf(" * WENDLING Nicolas\n");
                printf(" * NASSABAIN Marco\n");
                break;
            case 't':
                // printf("option tos\n");
                opt_print_symbol_table = 1;
                break;
            case 'a':
                // printf("option ast\n");
                opt_print_ast = 1;
                break;
            case 'o':
                printf("option output with arg: %s\n", optarg);
                output_file = optarg;
                break;
            case '?':
                break;
            default:
                // printf("option non gérée\n");
                abort();
        }
    }
    

    if (argc - optind != 2) {
        fprintf(stderr, "Error: needs 2 arguments : input_file spec_file\n");
        exit(1);
    }

    return optind;
}