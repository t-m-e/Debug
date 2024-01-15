# Debug

Small header-only implementation of debug statements that can be enabled/disabled with environment variables.

## Example

For errors with normal execution:
```c
#include "debug.h"

int main() {
    DEBUG_INFO("Hello, World!");
    DEBUG_WARN("Hello, but spicy.");
    DEBUG_ERR("Hello, but handle error.");
    return 0;
}
```

Will output:
```
(file.c:4 INFO) Hello, World!
(file.c:5 WARN) Hello, byt spicy.
(file.c:6 ERR) Hello, but handle error.
```

For fatal errors:
```c
#include "debug.h"

int main() {
    DEBUG_FATAL("Hello, but Goodbye!");
    return 0;
}
```

Will output:
```
(file.c:4 FATAL) Hello, but Goodbye! | exiting.
```

For abortable errors:
```c
#include "debug.h"

int main() {
    DEBUG_ABORT("Hello, but die.");
    return 0;
}
```

Will output:
```
(file.c:4 ABORT) Hello, but die. | killing process.
```
