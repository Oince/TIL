# 멀티 프로세스(Multi process)

## fork
```
#include <unistd.h>

pid_t fork()
```
성공시 자식 프로세스의 pid 반환 (== 0)
