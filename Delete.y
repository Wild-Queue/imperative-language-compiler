

// Возможно, прикреплять детей к родительскому ноду
Expression : Relation                       {$$ = $1;}
            | Relation T_AND Expression     {$$ = createNode($1, $3, T_AND, "and");}
            | Relation T_OR  Expression     {$$ = createNode($1, $3, T_OR, "or");}
            | Relation T_XOR Expression     {$$ = createNode($1, $3, T_XOR, "xor");}
            ;

// Relation Relations         {$$ = createNode($1, $2, "Expression", "Expression");}
// Zero or more
//Relations : /*empty*/                   {}
//          | Relations T_AND Relation    {}
//          | Relations T_OR  Relation    {}
//          | Relations T_XOR Relation    {}
//          ;


Relation : Simple                           {$$ = $1;}
          | Simple T_LESS Simple            {$$ = createNode($1, $3, T_LESS, "<");}
          | Simple T_LESSOREQU Simple       {$$ = createNode($1, $3, T_LESSOREQU, "<=");}
          | Simple T_GREAT Simple           {$$ = createNode($1, $3, T_GREAT, ">");}
          | Simple T_GREATOREQU Simple      {$$ = createNode($1, $3, T_GREATOREQU, ">=");}
          | Simple T_EQU Simple             {$$ = createNode($1, $3, T_EQU, "=");}
          | Simple T_NOTEQU Simple          {$$ = createNode($1, $3, T_NOTEQU, "/=");}
          ;

// Simple : Factor { ( * | / | % ) Factor }
Simple : Factor                     {$$ = $1;}
        | Factor T_MULTOP Simple   {$$ = createNode($1, $3, T_MULTOP, "*");}
        | Factor T_DIVOP Simple    {$$ = createNode($1, $3, T_DIVOP, "/");}
        | Factor T_MODOP Simple    {$$ = createNode($1, $3, T_MODOP, "%");}
        ;


//Factor : Summand { ( + | - ) Summand }
Factor : Summand                        {$$ = $1;}
        | Summand T_ADDOP Factor      {$$ = createNode($1, $3, T_ADDOP, "+");}
        | Summand T_SUBTROP Factor    {$$ = createNode($1, $3, T_SUBTROP, "-");}
        ;

Summand : Primary                       {$$ = $1;}
        | T_LPAREN Expression T_LPAREN  {$$ = $2;}
        ;

Primary : T_ICONST                      {$$ = createNode(T_ICONST, to_string($1));}
        | T_CCONST                      {$$ = createNode(T_CCONST, $1);}
        | T_RCONST                      {$$ = createNode(T_RCONST, to_string($1));}
        | T_TRUE                        {$$ = createNode(T_TRUE, "true");}
        | T_FALSE                       {$$ = createNode(T_FALSE, "false");}
        | ModifiablePrimary             {$$ = $1;}
        ;


ModifiablePrimary : ID_ARRAY                                        {$$ = $1;}
                | ID_ARRAY T_DOT ModifiablePrimary                  {$$ = createNode($1, $3,T_DOT, ".");}
                ;

ID_ARRAY  : T_ID                                                {$$ = createNode(T_ID, $1);}
          | T_ID T_LBRACK Expression T_RBRACK                   {$$ = createNode(new Node(Token(T_ID, $1)), $3, T_BRACKS, "[]");}
          | T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY {$$ = createNode(new Node(Token(T_ID, $1)), $3, $5, T_BRACKS, "[]");}
          ;

Identifiers_ARRAY : T_LBRACK Expression T_RBRACK                    {$$ = createNode($2, T_BRACKS, "[]");}
                  | T_LBRACK Expression T_RBRACK Identifiers_ARRAY  {$$ = createNode($2, $4, T_BRACKS, "[]");}
                  ;

