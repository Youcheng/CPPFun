# Resources:
- http://thbecker.net/articles/rvalue_references/section_01.html

# Criteria of lvalueness and rvalueness of an expression
- if you can take the address of that expression, it is an lvalue
- if the type of the expression is lvalue reference(const T&, T&), it is an lvalue
- otherwise, it is an rvalue.

