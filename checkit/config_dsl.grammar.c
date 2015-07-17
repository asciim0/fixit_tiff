/* A recursive-descent parser generated by peg 0.1.15 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 24
#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy_Value(yycontext *yy); /* 24 */
YY_RULE(int) yy_ValueList(yycontext *yy); /* 23 */
YY_RULE(int) yy_Digit(yycontext *yy); /* 22 */
YY_RULE(int) yy_Colon(yycontext *yy); /* 21 */
YY_RULE(int) yy_Only(yycontext *yy); /* 20 */
YY_RULE(int) yy_Any(yycontext *yy); /* 19 */
YY_RULE(int) yy_LogicalOr(yycontext *yy); /* 18 */
YY_RULE(int) yy_Range(yycontext *yy); /* 17 */
YY_RULE(int) yy_ValueReference(yycontext *yy); /* 16 */
YY_RULE(int) yy_OptionalDepends(yycontext *yy); /* 15 */
YY_RULE(int) yy_Space(yycontext *yy); /* 14 */
YY_RULE(int) yy_TagReference(yycontext *yy); /* 13 */
YY_RULE(int) yy_Number(yycontext *yy); /* 12 */
YY_RULE(int) yy_Values(yycontext *yy); /* 11 */
YY_RULE(int) yy_Requirements(yycontext *yy); /* 10 */
YY_RULE(int) yy_Semicolon(yycontext *yy); /* 9 */
YY_RULE(int) yy_Tag(yycontext *yy); /* 8 */
YY_RULE(int) yy_EndOfLine(yycontext *yy); /* 7 */
YY_RULE(int) yy_SpaceLine(yycontext *yy); /* 6 */
YY_RULE(int) yy_Comment(yycontext *yy); /* 5 */
YY_RULE(int) yy_Tagline(yycontext *yy); /* 4 */
YY_RULE(int) yy_EndOfFile(yycontext *yy); /* 3 */
YY_RULE(int) yy_Line(yycontext *yy); /* 2 */
YY_RULE(int) yy_start(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_EndOfLine(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_EndOfLine\n"));
  {
   printf ("EOL found\n"); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Any(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Any\n"));
  {
   set_any(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Only(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Only\n"));
  {
   set_only(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Value(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Value\n"));
  {
   incr_values(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_LogicalOr(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_LogicalOr\n"));
  {
   set_logical_or(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Number(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Number\n"));
  {
  i_push(atoi(yytext) );;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Range(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Range\n"));
  {
   set_range();;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_Requirements(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Requirements\n"));
  {
   set_optional(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_Requirements(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Requirements\n"));
  {
   set_ifdepends(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Requirements(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Requirements\n"));
  {
   set_mandatory(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Tag(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Tag\n"));
  {
   
                        int tag = atoi(yytext);
                        /* rule_tagorder_in_dsl( tag ); */
                        settag( tag );
                ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Tagline(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Tagline\n"));
  {
   rule_addtag_config(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_4_Line(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_4_Line\n"));
  {
   rule_should_not_occure(yytext[0]); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_Line(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Line\n"));
  {
   incrlineno(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_Line(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Line\n"));
  {
   incrlineno(); commentline(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Line(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Line\n"));
  {
   incrlineno(); tagline(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_Value(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Value"));  if (!yy_Number(yy)) goto l1;  yyDo(yy, yy_1_Value, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Value", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Value", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ValueList(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ValueList"));  if (!yy_Value(yy)) goto l2;
  l3:;	
  {  int yypos4= yy->__pos, yythunkpos4= yy->__thunkpos;  if (!yy_Colon(yy)) goto l4;  if (!yy_Value(yy)) goto l4;  goto l3;
  l4:;	  yy->__pos= yypos4; yy->__thunkpos= yythunkpos4;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "ValueList", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ValueList", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Digit(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Digit"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l5;
  yyprintf((stderr, "  ok   %s @ %s\n", "Digit", yy->__buf+yy->__pos));
  return 1;
  l5:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Digit", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Colon(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Colon"));  if (!yymatchChar(yy, ',')) goto l6;
  l7:;	
  {  int yypos8= yy->__pos, yythunkpos8= yy->__thunkpos;  if (!yy_Space(yy)) goto l8;  goto l7;
  l8:;	  yy->__pos= yypos8; yy->__thunkpos= yythunkpos8;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "Colon", yy->__buf+yy->__pos));
  return 1;
  l6:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Colon", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Only(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Only"));  if (!yymatchString(yy, "only(")) goto l9;  if (!yy_Value(yy)) goto l9;  if (!yymatchChar(yy, ')')) goto l9;  yyDo(yy, yy_1_Only, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Only", yy->__buf+yy->__pos));
  return 1;
  l9:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Only", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Any(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Any"));  if (!yymatchString(yy, "any")) goto l10;  yyDo(yy, yy_1_Any, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Any", yy->__buf+yy->__pos));
  return 1;
  l10:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Any", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_LogicalOr(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "LogicalOr"));  if (!yymatchString(yy, "logical_or(")) goto l11;  if (!yy_ValueList(yy)) goto l11;  if (!yymatchChar(yy, ')')) goto l11;  yyDo(yy, yy_1_LogicalOr, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "LogicalOr", yy->__buf+yy->__pos));
  return 1;
  l11:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "LogicalOr", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Range(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Range"));  if (!yymatchString(yy, "range(")) goto l12;  if (!yy_Number(yy)) goto l12;  if (!yy_Colon(yy)) goto l12;  if (!yy_Number(yy)) goto l12;  if (!yymatchChar(yy, ')')) goto l12;  yyDo(yy, yy_1_Range, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Range", yy->__buf+yy->__pos));
  return 1;
  l12:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Range", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ValueReference(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ValueReference"));  if (!yy_Number(yy)) goto l13;
  yyprintf((stderr, "  ok   %s @ %s\n", "ValueReference", yy->__buf+yy->__pos));
  return 1;
  l13:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ValueReference", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_OptionalDepends(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "OptionalDepends"));  if (!yymatchString(yy, "depends(")) goto l14;  if (!yy_TagReference(yy)) goto l14;  if (!yymatchChar(yy, '.')) goto l14;  if (!yy_ValueReference(yy)) goto l14;  if (!yymatchChar(yy, ')')) goto l14;
  yyprintf((stderr, "  ok   %s @ %s\n", "OptionalDepends", yy->__buf+yy->__pos));
  return 1;
  l14:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "OptionalDepends", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Space(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Space"));
  {  int yypos16= yy->__pos, yythunkpos16= yy->__thunkpos;  if (!yymatchChar(yy, ' ')) goto l17;  goto l16;
  l17:;	  yy->__pos= yypos16; yy->__thunkpos= yythunkpos16;  if (!yymatchChar(yy, '\t')) goto l15;
  }
  l16:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Space", yy->__buf+yy->__pos));
  return 1;
  l15:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Space", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_TagReference(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "TagReference"));  if (!yy_Number(yy)) goto l18;
  yyprintf((stderr, "  ok   %s @ %s\n", "TagReference", yy->__buf+yy->__pos));
  return 1;
  l18:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "TagReference", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Number(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Number"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l19;
#undef yytext
#undef yyleng
  }  if (!yy_Digit(yy)) goto l19;
  l20:;	
  {  int yypos21= yy->__pos, yythunkpos21= yy->__thunkpos;  if (!yy_Digit(yy)) goto l21;  goto l20;
  l21:;	  yy->__pos= yypos21; yy->__thunkpos= yythunkpos21;
  }  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l19;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_Number, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Number", yy->__buf+yy->__pos));
  return 1;
  l19:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Number", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Values(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Values"));
  {  int yypos23= yy->__pos, yythunkpos23= yy->__thunkpos;  if (!yy_Range(yy)) goto l24;  goto l23;
  l24:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;  if (!yy_LogicalOr(yy)) goto l25;  goto l23;
  l25:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;  if (!yy_Any(yy)) goto l26;  goto l23;
  l26:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;  if (!yy_Only(yy)) goto l22;
  }
  l23:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Values", yy->__buf+yy->__pos));
  return 1;
  l22:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Values", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Requirements(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Requirements"));
  {  int yypos28= yy->__pos, yythunkpos28= yy->__thunkpos;  if (!yymatchString(yy, "mandatory")) goto l29;  yyDo(yy, yy_1_Requirements, yy->__begin, yy->__end);  goto l28;
  l29:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;  if (!yy_OptionalDepends(yy)) goto l30;  yyDo(yy, yy_2_Requirements, yy->__begin, yy->__end);  goto l28;
  l30:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;  if (!yymatchString(yy, "optional")) goto l27;  yyDo(yy, yy_3_Requirements, yy->__begin, yy->__end);
  }
  l28:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Requirements", yy->__buf+yy->__pos));
  return 1;
  l27:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Requirements", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Semicolon(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Semicolon"));  if (!yymatchChar(yy, ';')) goto l31;
  l32:;	
  {  int yypos33= yy->__pos, yythunkpos33= yy->__thunkpos;  if (!yy_Space(yy)) goto l33;  goto l32;
  l33:;	  yy->__pos= yypos33; yy->__thunkpos= yythunkpos33;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "Semicolon", yy->__buf+yy->__pos));
  return 1;
  l31:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Semicolon", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Tag(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Tag"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l34;
#undef yytext
#undef yyleng
  }  if (!yy_Number(yy)) goto l34;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l34;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_Tag, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Tag", yy->__buf+yy->__pos));
  return 1;
  l34:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Tag", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EndOfLine(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EndOfLine"));
  {  int yypos36= yy->__pos, yythunkpos36= yy->__thunkpos;  if (!yymatchString(yy, "\r\n")) goto l37;  goto l36;
  l37:;	  yy->__pos= yypos36; yy->__thunkpos= yythunkpos36;  if (!yymatchChar(yy, '\n')) goto l38;  goto l36;
  l38:;	  yy->__pos= yypos36; yy->__thunkpos= yythunkpos36;  if (!yymatchChar(yy, '\r')) goto l35;  yyDo(yy, yy_1_EndOfLine, yy->__begin, yy->__end);
  }
  l36:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "EndOfLine", yy->__buf+yy->__pos));
  return 1;
  l35:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EndOfLine", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_SpaceLine(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "SpaceLine"));
  {  int yypos40= yy->__pos, yythunkpos40= yy->__thunkpos;  if (!yy_Space(yy)) goto l40;  goto l41;
  l40:;	  yy->__pos= yypos40; yy->__thunkpos= yythunkpos40;
  }
  l41:;	  if (!yy_EndOfLine(yy)) goto l39;
  yyprintf((stderr, "  ok   %s @ %s\n", "SpaceLine", yy->__buf+yy->__pos));
  return 1;
  l39:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "SpaceLine", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Comment"));  if (!yymatchChar(yy, '#')) goto l42;
  l43:;	
  {  int yypos44= yy->__pos, yythunkpos44= yy->__thunkpos;
  {  int yypos45= yy->__pos, yythunkpos45= yy->__thunkpos;  if (!yy_EndOfLine(yy)) goto l45;  goto l44;
  l45:;	  yy->__pos= yypos45; yy->__thunkpos= yythunkpos45;
  }  if (!yymatchDot(yy)) goto l44;  goto l43;
  l44:;	  yy->__pos= yypos44; yy->__thunkpos= yythunkpos44;
  }  if (!yy_EndOfLine(yy)) goto l42;
  yyprintf((stderr, "  ok   %s @ %s\n", "Comment", yy->__buf+yy->__pos));
  return 1;
  l42:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Tagline(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Tagline"));  if (!yy_Tag(yy)) goto l46;  if (!yy_Semicolon(yy)) goto l46;  if (!yy_Requirements(yy)) goto l46;  if (!yy_Semicolon(yy)) goto l46;  if (!yy_Values(yy)) goto l46;  if (!yy_EndOfLine(yy)) goto l46;  yyDo(yy, yy_1_Tagline, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Tagline", yy->__buf+yy->__pos));
  return 1;
  l46:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Tagline", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EndOfFile(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EndOfFile"));
  {  int yypos48= yy->__pos, yythunkpos48= yy->__thunkpos;  if (!yymatchDot(yy)) goto l48;  goto l47;
  l48:;	  yy->__pos= yypos48; yy->__thunkpos= yythunkpos48;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "EndOfFile", yy->__buf+yy->__pos));
  return 1;
  l47:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EndOfFile", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Line(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Line"));
  {  int yypos50= yy->__pos, yythunkpos50= yy->__thunkpos;  if (!yy_Tagline(yy)) goto l51;  yyDo(yy, yy_1_Line, yy->__begin, yy->__end);  goto l50;
  l51:;	  yy->__pos= yypos50; yy->__thunkpos= yythunkpos50;  if (!yy_Comment(yy)) goto l52;  yyDo(yy, yy_2_Line, yy->__begin, yy->__end);  goto l50;
  l52:;	  yy->__pos= yypos50; yy->__thunkpos= yythunkpos50;  if (!yy_SpaceLine(yy)) goto l53;  yyDo(yy, yy_3_Line, yy->__begin, yy->__end);  goto l50;
  l53:;	  yy->__pos= yypos50; yy->__thunkpos= yythunkpos50;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l49;
#undef yytext
#undef yyleng
  }  if (!yymatchDot(yy)) goto l49;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l49;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_4_Line, yy->__begin, yy->__end);
  }
  l50:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Line", yy->__buf+yy->__pos));
  return 1;
  l49:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Line", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_start(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "start"));  if (!yy_Line(yy)) goto l54;
  l55:;	
  {  int yypos56= yy->__pos, yythunkpos56= yy->__thunkpos;  if (!yy_Line(yy)) goto l56;  goto l55;
  l56:;	  yy->__pos= yypos56; yy->__thunkpos= yythunkpos56;
  }  if (!yy_EndOfFile(yy)) goto l54;
  yyprintf((stderr, "  ok   %s @ %s\n", "start", yy->__buf+yy->__pos));
  return 1;
  l54:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "start", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_start);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif
