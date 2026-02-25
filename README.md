# Crafting Interpreters

Hi! I'm using this README to record my answers to the end of section/chapter questions.

## 2.4 Our Journey
1. Downloaded CPython source... identified files lexer.c and parser.c which suggests they were hand-written.
  - lexer was around 1.5k lines, so not insane but by no means simple.
  - parser was around 32k lines with ~1k of them used for defining macros/globals/etc.
2. A few drawbacks first come to mind concerning JIT over other compilation methods.
  - There needs to be another structure utilized to detect and keep track of under-optimized code, which could be an issue in memory-constrained environments.
    - Do we persist this in memory? If so, how do we remember what to optimize when the program exits? If we store in LTS, when do you know when to delete it and what structure keeps track of that? 
  - It takes time before the program is fully optimized, which could cause load issues early on in its lifecycle.
3. From what I researched (via wikipedia), the eval function in LISP is primarily for string processing, but, alternatively (and likely more importantly), is able to evaluate expressions as code. So it acts as an interpreter within itself, which is pretty cool. I'm sure this is used both as a compiler/interpreter external of the code as well as a tool for executing lambda-esque statements within it, and is even capable of modifying itself as it's running. It's easy to see how this built the foundation of early AI research.

## 4.6.2 Number Literals
- Defining early on how to parse the decimal in floating point affects not only what literals are considered "legal" i.e. 431.23 or 431. or .431, but also if/how we can call methods on those literals i.e. 123.abs();

## 4.7 Reserved Words & Identifiers
1. A good example of a regular language is the lexical grammar handled by our scanner. A scanner operates like a finite automaton: it processes input linearly and has only finite memory. It recognizes tokens based on fixed patterns and does not need to remember arbitrarily deep structure. Regular languages cannot handle recursive constructs such as nested parentheses or nested scopes, because recognizing those requires unbounded memory. Such constructs belong to context-free languages, which are recognized by pushdown automata that use a stack. Most programming languages, including Python and Haskell, have lexical grammars that are regular but syntactic grammars that are context-free. Their execution semantics go even further — they are Turing-complete, meaning they can simulate a Turing machine and operate with effectively unbounded memory. (Thanks, AI!)
2. In C, macro definitions begin immediately after the first whitespace character present after the macro name i.e. #define SUM(a) (a + a), where SUM is the macro name and (a + a) is the macro definition. Following this rule, the macro definition #define SUM (a) (a + a) is distinct from the previous definition due to the space between SUM and (a) and result in an attempt to cast (a + a) as type 'a' rather than return the sum of a and a.
3. It could be useful to scan comments if you would like them to be available when viewed through decompilers or other tools, such as technical docs or licensing details. 
4. Supporting nested comments is already supported as part of block comments, as any nested comments can be considered part of the parent block comment.
