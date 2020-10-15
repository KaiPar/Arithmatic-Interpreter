# Arithmatic-Interpreter
This is a simple arithmatic expression interpreter made in c++

To first run the interpreter, make sure you have MingW g++ installed and g++ is set in path

Syntax:
The program always starts with ```BEGIN``` keyword and ends with ```END``` keyword
The rules of the expression are:
1. There must always be a space between 2 consecutive terms
2. For now, the interpreter only supports +, -, * and / operations
3. There must be one expression between BEGIN and END keywords.
Examples:
1.
```
BEGIN
3 + 5 - 2 * 8
END
```
2.
```
BEGIN
69 + 56 - 120
END
```

To run your code, make sure, the file has:
1. ```.kai``` as the extension
2. In the interpreted code, change the file name in the main() to your filename
3. Enjoy...
