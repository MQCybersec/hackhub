# Compile with
```bash
gcc file.c -o file -fno-stack-protector -z execstack -no-pie -m32 -Wno-implicit-function-declaration
```
![image](https://github.com/user-attachments/assets/f234a4a0-e537-40c3-8fdf-c45e8e5a46dd)

## Errors
```/usr/include/stdio.h:27:10: fatal error: bits/libc-header-start.h: No such file or directory```

Install 32bit gcc 
```bash
sudo apt update
sudo apt install gcc-multilib
```

## Additional reading
- https://tc.gts3.org/cs6265/2019/tut/tut01-warmup1.html
- https://github.com/Crypto-Cat/CTF/tree/main/pwn/binary_exploitation_101
- https://guyinatuxedo.github.io/

## challanges
- https://wargames.ret2.systems/deusx64
- https://pwn.college/
