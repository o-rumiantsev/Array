# Array

This is an attempt to improve arrays in C++. Not only make it look like JS arrays, but partly save its advantage - direct access to its elements.

# Mechanism

`Array` class wraps a singly linked list, which nodes has two fields: `slice` and `next`. `slice` is a C/C++ array.
The constructor of an `Array` takes one argument - `size`. This is the size of one slice, which contains in one list node.
When user want to use more memory, there will be allocated one more array and push it to the list.


```
                             Array class
    
         List   o —---------------> o —-----------> o
                |                   |               |
Memory [ ... | |x|x|x|x| | | ... | |x|x|x|x| | ... |x|x|x|x| | ...  ]
                 slice               slice           slice
```


So here is an example of how it works:
```javascript
Array arr (10); // Initialize an array with size 10
                // Internal list has one node.

//  do something
...
//  10 elements became not enough

arr[10] = some_value; // There has allocated one more array on 10 elements inside
                      // Internal list has two nodes now.
                      

```

# Features

###  `push()`
```javascript

// arr [1, 2, 3, 4, 5, 6, 7, 8, 9]

arr.push(10);

// arr [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

```

### `pop()`
```javascript

// arr [1, 2, 3, 4]

int last = arr.pop();

// last = 4, arr [1, 2, 3]

```

### `map()`
```javascript

// arr [1, 2, 3, 4]

Array double_arr = arr.map([](int item) { return item * 2; });

// double_arr [2, 4, 6, 8], arr [1, 2, 3, 4]

```

### `filter()`
```javascript

// arr [1, 2, 3, 4]

Array filtered = arr.filter([](int item) { return item % 2 == 0; });

// filtered [2, 4], arr [1, 2, 3, 4]

```
