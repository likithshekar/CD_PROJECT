lex ast.l
yacc -d ast.y
gcc lex.yy.c y.tab.c -ll -ly -o AST
lex icg.l
yacc -d icg.y
gcc lex.yy.c y.tab.c -ll -ly -o ICG
clear
echo "Simple C Compiler Project"
echo "Supported constructs : For loop, Ternary Operators and Structures"

echo "./AST < filename for AST. Output in Output/ast.txt"
echo "./ICG < filename for ICG. Output in Output/icg.txt and quad.txt"
echo "python optimize.py filename for Code Optimization"
echo "python generate.py filename for Assembly Code. Output in Assembly.s"
