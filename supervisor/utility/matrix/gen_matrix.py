#!/usr/bin/env python3
# -*- encoding=utf-8 -*-
import numpy as np

# addr = 0x80400000
# length = 128*128*4
n = 96
z = np.zeros((128,128), dtype=np.int32)
a = z.copy()
a[:n, :n] = np.random.randint(-1000, 1000, size=(n,n))
b = z.copy()
b[:n, :n] = np.random.randint(-1000, 1000, size=(n,n))
c = a @ b
print(a)
print(b)
print(c)

def printHex(f, i):
    if i < 0:
        i += 0x100000000
    f.write(f"{i:08x}\n")

def matrix_bytes(*matrices):
    return b"".join(matrix.astype("<i4", copy=False).tobytes(order="C") for matrix in matrices)

def write_binary(path, *matrices):
    with open(path, "wb") as f:
        f.write(matrix_bytes(*matrices))

def write_mif(path, *matrices):
    data = matrix_bytes(*matrices)
    with open(path, "w") as f:
        for offset in range(0, len(data), 4):
            word = int.from_bytes(data[offset:offset + 4], byteorder="little", signed=False)
            f.write(f"{word:032b}\n")

with open("matrix.in", "w") as f:
    # addr += 16
    # printHex(f, addr) # address of a
    # printHex(f, addr+length) # address of b
    # printHex(f, addr+length*2) # address of c
    # printHex(f, n)
    # value of a
    for row in a:
        for col in row:
            printHex(f, col)
    # value of b
    for row in b:
        for col in row:
            printHex(f, col)
    # initial value of c (all zeros)
    for row in z:
        for col in row:
            printHex(f, col)
with open("matrix.out", "w") as f:
    # value of c
    for row in c:
        for col in row:
            printHex(f, col)

# 1. 生成包含答案的二进制包 (四合一: a + b + z + c) -> 256KB
write_binary("matrix.bin", a, b, z, c)
write_mif("matrix.mif", a, b, z, c)

# # 2. 生成不含答案的纯输入包 (三合一: a + b + z) -> 192KB
# with open("matrix_no_ans.bin", "wb") as f:
#     a.tofile(f)
#     b.tofile(f)
#     z.tofile(f)
