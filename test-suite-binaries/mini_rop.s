.global _start

.section .text
_start:
    sub $0x20, %rsp        # 手动“造一个栈帧”
    mov %rsp, %rsi         # buf = rsp
    mov $0x40, %rdx        # size = 64
    mov $0, %rdi           # fd = stdin
    mov $0, %rax           # sys_read
    syscall                # read(0, rsp, 64)

    leave                  # ← ROP gadget 核心
    ret
