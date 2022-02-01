#include <editline/readline.h>
#include <stdio.h>
#include <stdlib.h>

#include "mpc.h"

int main(int argc, char **argv) {

  mpc_parser_t *Number = mpc_new("number");
  mpc_parser_t *Operator = mpc_new("operator");
  mpc_parser_t *Expr = mpc_new("expr");
  mpc_parser_t *List_p = mpc_new("list_p");

  mpca_lang(MPCA_LANG_DEFAULT, "                                            \
                               number: /-?[0-9]+/ ;											\
                               operator: '+' | '-' | '*' | '/' ;				\
                               expr : <number> | '(' <operator> <expr>+ ')'; \
                               list_p : /^/<operator> <expr>+ /$/ ;			\
  ",
            Number, Operator, Expr, List_p);

  printf("List_P version 0.0.1\n");
  printf("Press Ctrl+c to Exit\n");

  while (1) {
    char *input = readline("list_p > ");
    add_history(input);

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, List_p, &r)) {
      /* On success Print and Delete the AST */
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }
	/* Undefine and delete our parsers */
	mpc_cleanup(4, Number, Operator, Expr, List_p);
  return 0;
}
