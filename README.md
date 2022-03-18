# Structure
- *include* has all the includes
- *src* has the source codes
- *lib* has the compiled library file

# Using the library

- `#include <dbconnection.h>` in your c++ program
- Suppose your file is called *main.cpp*, you can compile like this,

```bash
g++ -std=c++14 main.cpp -o main -I./include -L./lib -ldbf
```
