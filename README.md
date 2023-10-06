# fibonacci
Generate the nth value of the Fibonacci sequence.  Compare the execution time between an iterative and recursive implementation.

You never know when you need to generate Fibonacci numbers. Always be prepared!

## Configure
Requires cmake and a c++ compiler  
```cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release```

## Build
`cmake --build build`

## Run
The application takes one command line input N.  For example: 
```
./fibonacci 12
Fibonacci recursion: 144 (7 microseconds)
Fibonacci iteration: 144 (6 microseconds)

./fibonacci 40
Fibonacci recursion: 102334155 (622080 microseconds)
Fibonacci iteration: 102334155 (17 microseconds)
```
