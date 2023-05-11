# About The Project

We implemented a compiler based on C++ for given Imperative programming language. See [grammar](GRAMMAR.md) of this language.

## Usage
Prerequisites: bison, ILASM from .NET build tools.
There are three options to run compiler:
1. Compile to C# language and run. 
```c
make run file="your_file"
```
2. Compile to CIL and run.
```c
make run-cil file="your_file"
```
3. Run tests from `tests` forder.
```c
make test
```
## Authors of the project

Egor Shalagin, Vladislav Spigin, Maxim Latypov and Arseniy Rubtsov

