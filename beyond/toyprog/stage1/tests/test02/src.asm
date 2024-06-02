# GCD algorithm

# def gcd(a, b):
#     while a != b:
#         if a > b:
#             a = a - b
#         else:
#             b = b - a
#     return a

# A few notes on the implementation:
# [Begin]:
# 	TMP = B - A
# 	if carry is set [it means A>B]:
#       [Branch1]
#   	A = A - B
#   	jmp Begin
#   TMP2 = TMP - 1
#	if carry is set [it means A == B]:
#		[Branch 2]
#		out a
#		stop
#	[otherwise, A < B]
#	b = TMP [because it is B-A]
#   jmp Begin

# jmp = two jcc in row

#  Variable/register assignment R1 = A, R2 = B, R3 = TMP, R4 = 1 [constant]

# Jump offsets:
# R5 = [Begin] address
# R6 = [Branch1] address
# R7 = [Branch2] address

IN R4 # Constant 1
IN R5 # Jump table - begin address
IN R6 # Jump table - branch1 address
IN R7 # Jump table - branch2 address
IN R1 # Input number A
IN R2 # Input number B

# [Begin]
SUB R0 # [Begin] entry point. Clear TMP
LDA R2 # TMP=A
SUB R1 # TMP=B-A is in R1
JCC R6 # If carry, jump to Branch1
STA R3 # we might need TMP value in the future
SUB R4 # decrement accumulator by 1
JCC R7 # if carry, jump to Branch2

LDA R3 # we need previous TMP
STA R2 # B = TMP now

SUB R0 # simulate JMP to beginning by: R0 = R0-R0
SUB R4 # then R0 = R0 - 1 (carry set!)
JCC R5 

# [Branch1]
LDA R1 # [Branch1] entry point. R1 = A
SUB R2 # R1 = A - B
STA R1 # R2[A] = A - B

SUB R0 # simulate JMP to Begin
SUB R4
JCC R5

# [Branch2]
OUT R1 # [Branch2] entry point. Variable A holds the answer
STOP # that's it folks!




