#include <stdio.h>
#include <unistd.h>

void gadget1() {
    asm("nop");
}

void gadget2(long a, long b) {
    printf("a=%ld b=%ld\n", a, b);
}

void vulnerable() {
    char buf[64];
    read(0, buf, 200);   // 明显的栈溢出
}

int main() {
    gadget1();
    gadget2(1, 2);
    vulnerable();
    return 0;
}

