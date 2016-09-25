#!/usr/bin/env python  
# coding=utf-8  
# Python使用的是2.7，缩进可以使用tab、4个空格或2个空格，但是只能任选其中一种，不能多种混用
import sys
fin = sys.stdin
N = int(fin.readline())

for i in xrange(N):
    # raw_input()里面不要有任何提示信息
    params = []
    line = fin.readline()
    a, b, c, d = line.split()
    nn = fin.readline().strip().split(',')
    print(a, b, c, d, nn)
