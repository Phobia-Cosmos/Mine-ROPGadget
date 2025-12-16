
```sh
gcc mini_rop.c -o mini_rop \
    -O0 \
    -fno-stack-protector \
    -no-pie \
    -z execstack

gcc mini_rop.c -o mini_rop

```

固定地址 ELF
没有 canary
没有 PIE
gadget 密度极低（非常利于理解）


gcc 默认加了什么？

| 组件                  | 来源    |
| ------------------- | ----- |
| `_start`            | glibc |
| `__libc_start_main` | glibc |
| `.interp`           | 动态链接  |
| `.dynamic`          | 动态链接  |
| `.got / .plt`       | 动态符号  |
| ELF 对齐 padding      | ld    |
| 调试 / ABI 信息         | gcc   |
