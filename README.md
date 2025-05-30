# Push Swap

## Overview
Push Swap is a sorting algorithm project that implements a stack-based sorting mechanism. The program takes a list of integers as input and sorts them using a set of predefined operations on two stacks (A and B).

## Features
- **Stack Operations**: Implements various stack operations including push, swap, rotate, and reverse rotate
- **Multiple Sorting Algorithms**: 
  - Small sort algorithm for 3-5 numbers
  - Radix sort implementation for larger sets
- **Input Validation**: Robust parsing and validation of input arguments
- **Memory Management**: Proper handling of memory allocation and deallocation
- **Error Handling**: Comprehensive error checking and reporting

## Usage
1. Compile the project using the provided Makefile:
   ```
   make
   ```
2. Run the program with a list of integers as arguments:
   ```
   ./push_swap 3 1 4 2 5
   ```

## Available Operations
- `sa`: Swap the first two elements of stack A
- `sb`: Swap the first two elements of stack B
- `ss`: Swap the first two elements of both stacks
- `pa`: Push the first element from stack B to stack A
- `pb`: Push the first element from stack A to stack B
- `ra`: Rotate stack A (shift all elements up by 1)
- `rb`: Rotate stack B
- `rr`: Rotate both stacks
- `rra`: Reverse rotate stack A (shift all elements down by 1)
- `rrb`: Reverse rotate stack B
- `rrr`: Reverse rotate both stacks

## Project Structure
- `src/`: Contains all source files
  - `push_swap.c`: Main program entry point
  - `stack_ops.c`: Stack operation implementations
  - `small_sort.c`: Algorithm for sorting small sets
  - `radix_sort.c`: Radix sort implementation
  - Various parsing and utility files
- `includes/`: Header files
  - `push_swap.h`: Main header file with all declarations

## Requirements
- GCC compiler
- Make
- Standard C library
