# Data Structures and Algorithms in C

This repository is a collection of C implementations and small driver programs
for studying fundamental data structures and algorithms. Each numbered folder
contains a header, implementation, and `main.c` demonstration unless noted
otherwise. The examples use assertions and console output to illustrate the
operations.

The complexity descriptions below use:

- `n`: number of stored elements
- `V`: number of graph vertices
- `E`: number of graph edges
- `h`: height of a binary search tree
- `alpha = n / m`: hash-table load factor for `m` buckets
- `L`: length of a string key

The asymptotic analysis follows the standard RAM-model conventions and the
divide-and-conquer, sorting, hashing, tree, heap, and graph discussions in
*Introduction to Algorithms* by Cormen, Leiserson, Rivest, and Stein (CLRS).
See the [referenced textbook](https://www.cs.mcgill.ca/~akroit/math/compsci/Cormen%20Introduction%20to%20Algorithms.pdf).

## Repository layout

| Path | Topic | What is demonstrated |
|---|---|---|
| [`01-lab-basics/`](./01-lab-basics/) | C and recursion basics | Factorial, shifts, random sums, greatest-of-three, and Tower of Hanoi |
| [`02-stack-and-queue/`](./02-stack-and-queue/) | Basic ADTs | Early stack and queue exercises |
| [`03-stack-array/`](./03-stack-array/) | Array stack | Bounded LIFO stack of floating-point values |
| [`04-stack-linked-list/`](./04-stack-linked-list/) | Linked stack | Bounded LIFO stack backed by dynamically allocated nodes |
| [`05-queue-array/`](./05-queue-array/) | Circular array queue | Bounded FIFO queue with head/tail indices |
| [`06-queue-linked-list/`](./06-queue-linked-list/) | Linked queue | Bounded FIFO queue with head and tail pointers |
| [`07-singly-linked-list/`](./07-singly-linked-list/) | Singly linked list | Insertion, deletion, lookup, reversal, duplicate removal, cycle detection, union, and intersection |
| [`08-doubly-linked-list/`](./08-doubly-linked-list/) | Doubly linked list | Bidirectional links, list updates, reversal, duplicate removal, set operations, and cycle detection |
| [`09-sorting/`](./09-sorting/) | Comparison sorting | Bubble, selection, insertion, merge, and quick sort |
| [`10-searching/`](./10-searching/) | Searching | Linear search and iterative/recursive binary search |
| [`11-binary-search-tree/`](./11-binary-search-tree/) | Binary search tree | Insertion, lookup, deletion, height, and traversals |
| [`12-hashing/`](./12-hashing/) | Hash table | String keys with separate chaining |
| [`13-heap/`](./13-heap/) | Max-heap | Build, insert, maximum lookup, extraction, and heap sort |
| [`14-graph/`](./14-graph/) | Graph | Adjacency-list construction, complete-graph construction, validation, display, and DFS |
| [`applications/01-student-list/`](./applications/01-student-list/) | Application | Student records stored in a singly linked list |
| [`assignments/`](./assignments/) | Coursework | Additional stack, queue, linked-list, BST, employee, and merge-sort exercises |

## Data structures

### Stacks

A stack is a LIFO (last-in, first-out) structure. The array implementation in
[`03-stack-array/stack.c`](./03-stack-array/stack.c) stores up to `MAX_DEPTH`
values in a fixed array. The linked implementation in
[`04-stack-linked-list/stack_list.c`](./04-stack-linked-list/stack_list.c)
stores nodes dynamically but still enforces a configured maximum size.

| Operation | Array stack | Linked stack |
|---|---:|---:|
| `push` | `O(1)` | `O(1)` |
| `pop` | `O(1)` | `O(1)` |
| `peek` | `O(1)` | `O(1)` |
| `is_empty` / `is_full` | `O(1)` | `O(1)` |
| Space | `O(C)` fixed capacity | `O(n)` allocated nodes |

Typical applications include expression evaluation, undo histories, function
call management, and depth-first traversal.

### Queues

A queue is a FIFO (first-in, first-out) structure. The array version is a
circular buffer in [`05-queue-array/queue.c`](./05-queue-array/queue.c). The
linked version maintains `head` and `tail` pointers in
[`06-queue-linked-list/queue_list.c`](./06-queue-linked-list/queue_list.c).

| Operation | Array queue | Linked queue |
|---|---:|---:|
| `enqueue` | `O(1)` | `O(1)` |
| `dequeue` | `O(1)` | `O(1)` |
| `peek` | `O(1)` | `O(1)` |
| `is_empty` / `is_full` | `O(1)` | `O(1)` |
| Space | `O(C)` fixed capacity | `O(n)` allocated nodes |

Queues are useful for scheduling, buffering, breadth-first search, and
producer-consumer workflows.

### Singly and doubly linked lists

The list implementations are in
[`07-singly-linked-list/singly_linked_list.c`](./07-singly-linked-list/singly_linked_list.c)
and [`08-doubly-linked-list/double_linked_list.c`](./08-doubly-linked-list/double_linked_list.c).
Both maintain head, tail, and length metadata. A doubly linked node additionally
stores a `prev` pointer, allowing traversal in both directions.

| Operation | Singly linked | Doubly linked |
|---|---:|---:|
| Add at head/tail | `O(1)` / `O(1)` | `O(1)` / `O(1)` |
| Lookup by value | `O(n)` | `O(n)` |
| Delete head/tail | `O(1)` / `O(n)` | `O(1)` / `O(n)` |
| Insert/delete after finding a node | `O(1)` | `O(1)` |
| Reverse | `O(n)` | `O(n)` |
| Cycle detection | `O(n)` time, `O(1)` space | `O(n)` time, `O(1)` space |
| Duplicate removal | `O(n^2)` | `O(n^2)` |
| Union/intersection in these implementations | `O((n+m)^2)` worst case | `O((n+m)^2)` worst case |
| Space | `O(n)` | `O(n)` |

The linked-list assignment in
[`assignments/assignment_2/linked_list/`](./assignments/assignment_2/linked_list/)
also demonstrates top-down merge sort and merging two lists.

### Binary search tree

[`11-binary-search-tree/bst.c`](./11-binary-search-tree/bst.c) implements an
unbalanced BST with unique integer keys. In a BST, the left subtree contains
smaller keys and the right subtree contains larger keys.

| Operation | Average case | Worst case |
|---|---:|---:|
| Insert, find, delete | `O(log n)` | `O(n)` |
| Height | `O(n)` | `O(n)` |
| Any full traversal | `O(n)` | `O(n)` |
| Extra recursion/stack space | `O(log n)` expected | `O(n)` |

The average bound assumes a reasonably balanced shape; this implementation
does not perform AVL or red-black rebalancing. In-order traversal outputs keys
in sorted order. Pre-order, post-order, and level-order traversals are included
in the interface, while the source currently provides the recursive traversal
implementations.

### Hash table

[`12-hashing/hashing.c`](./12-hashing/hashing.c) stores strings in buckets using
separate chaining. Its hash function scans the key, so hashing alone costs
`O(L)`.

| Operation | Expected with good distribution | Worst case |
|---|---:|---:|
| Find/insert/delete, excluding hashing | `O(1 + alpha)` | `O(n)` |
| Including string hashing/comparison | `O(L + alpha)` | `O(Ln)` |
| Space | `O(m+n)` | `O(m+n)` |

The quality of the result depends on the table size and the distribution of
keys. In production code, a stronger hash function, explicit ownership rules,
and resizing when the load factor grows would be appropriate.

### Max-heap

[`13-heap/heap.c`](./13-heap/heap.c) uses an array representation of a
max-heap. The largest key is at the root; children of index `i` are represented
using the usual heap index relationships.

| Operation | Complexity |
|---|---:|
| Build heap | `O(n)` |
| Get maximum | `O(1)` |
| Insert | `O(log n)` |
| Extract maximum | `O(log n)` |
| Heap sort | `O(n log n)` |
| Extra working space | `O(1)` |

This educational implementation uses a fixed `MAX_HEAP_SIZE`, so its practical
capacity is bounded even though the asymptotic heap operations are expressed
in terms of `n`.

### Graph

[`14-graph/graph.c`](./14-graph/graph.c) represents a graph with an array of
adjacency lists. It supports input-based adjacency lists, validated neighbor
input, a complete-graph generator, display, and recursive depth-first search.
The demonstration limits the number of vertices to `MAX`.

| Operation | Complexity |
|---|---:|
| Allocate vertex list | `O(V)` time and space |
| Build adjacency list from `E` entered edges | `O(V+E)` storage/work, excluding input retry costs |
| Build the complete graph | `O(V^2)` |
| DFS with adjacency lists | `O(V+E)` |
| DFS visited array | `O(V)` |

DFS is useful for reachability, connected-component exploration, cycle-related
analysis, and graph traversal. The current program starts DFS from a selected
vertex; it does not automatically restart DFS for every unvisited component.

## Algorithms

### Sorting

[`09-sorting/sorting.c`](./09-sorting/sorting.c) contains five in-place
comparison sorts. The table gives best, average, and worst running time, plus
auxiliary space.

| Algorithm | Best | Average | Worst | Extra space | Stable |
|---|---:|---:|---:|---:|---|
| Bubble sort | `O(n)` | `O(n^2)` | `O(n^2)` | `O(1)` | Yes |
| Selection sort | `O(n^2)` | `O(n^2)` | `O(n^2)` | `O(1)` | No |
| Insertion sort | `O(n)` | `O(n^2)` | `O(n^2)` | `O(1)` | Yes |
| Merge sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` | Yes |
| Quick sort | `O(n log n)` | `O(n log n)` | `O(n^2)` | `O(log n)` average, `O(n)` worst | No |

The quick-sort implementation chooses the first element as its pivot, which
explains its quadratic worst case for already unfavorable input orders. The
merge-sort implementation uses temporary storage while merging.

### Searching

[`10-searching/searching.c`](./10-searching/searching.c) provides:

| Algorithm | Required input | Best | Average/Worst | Extra space |
|---|---|---:|---:|---:|
| Linear search | None | `O(1)` | `O(n)` | `O(1)` |
| Iterative binary search | Sorted array | `O(1)` | `O(log n)` | `O(1)` |
| Recursive binary search | Sorted array | `O(1)` | `O(log n)` | `O(log n)` |

Binary search repeatedly halves the search interval, as described in CLRS.
Keeping the input sorted is a prerequisite; otherwise linear search is the
appropriate operation.

## Application: student list

[`applications/01-student-list/`](./applications/01-student-list/) applies a
singly linked list to student records containing a roll number, name, and
marks. It supports:

- creating and freeing a student list;
- adding a student at the tail while preventing duplicate roll numbers;
- looking up a student by roll number or name;
- checking whether a roll number exists;
- removing a student by roll number; and
- displaying the records.

Insertion at the tail is `O(1)` after the duplicate-roll-number check; because
that check scans the list, adding a record is `O(n)` in the current program.
Lookup and removal by roll number are `O(n)`, and storage is `O(n)`.

## Building and running

The projects include Code::Blocks project files (`.cbp`). Open the desired
project in Code::Blocks and build/run its `main.c`. For a standalone GCC build,
compile the implementation and driver together, for example:

```text
gcc -std=c11 -Wall -Wextra -pedantic 09-sorting/main.c 09-sorting/sorting.c -o sorting
./sorting
```

Replace the paths with the folder being studied. The repository currently
contains generated `bin/` and `obj/` outputs from the existing project builds;
the source of record is the `.c` and `.h` files.

## Reference

Cormen, T. H., Leiserson, C. E., Rivest, R. L., and Stein, C. **Introduction to
Algorithms**. The repository study topics correspond primarily to the chapters
on asymptotic analysis, divide-and-conquer, sorting, data structures, hashing,
binary search trees, heaps, and elementary graph algorithms.

- [Introduction to Algorithms (PDF)](https://www.cs.mcgill.ca/~akroit/math/compsci/Cormen%20Introduction%20to%20Algorithms.pdf)
