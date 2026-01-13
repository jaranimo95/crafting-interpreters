# Crafting Interpreters

## 2.4 Our Journey
1. Downloaded CPython source, found lexer.c and parser.c which suggests they were hand-written.
  - lexer was around 1.5k lines, so not insane, but by no means simple.
  - parser was around 32k lines with ~1k of them used for defining macros/globals/etc.
2. A few drawbacks first come to mind concerning JIT over other compilation methods.
  - There needs to be another structure utilized to detect and keep track of under-optimized code, which could be an issue in memory-constrained environments.
    - Do we persist this in memory? If so, how do we remember what to optimize when the program exits? If we store in LTS, when do you know when to delete it and what structure keeps track of that? 
  - It takes time before the program is fully optimized, which could cause load issues early on in its lifecycle.
3. From what I researched (via wikipedia), the eval function in LISP is primarily for string processing, but, alternatively (an likely more importantly), is able to evaluate expressions as code. So it acts as an interpreter within itself, which is pretty cool. I'm sure this is used both as a compiler/interpreter external of the code as well as a tool for executing lambda-esque statements within it, and is even capable of modifying itself as it's running. It's easy to see how this built the foundation of early AI research.

## 
