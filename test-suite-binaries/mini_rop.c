#include <unistd.h>

void vuln()
{
    char buf[16];
    read(0, buf, 64); // 栈溢出
}

int main()
{
    vuln();
    return 0;
}
