import sys

CMD = ["IN", "OUT", "LDA", "STA", "NOR", "SUB", "ADD", "JCC"]

prog = open(sys.argv[1]).read().splitlines()
intape = open(sys.argv[2])
outtape = open(sys.argv[3], "w")

PRECISION = 0xffff
REGS = [0,] * 8
PROGMEM = [0, ] * 32
pc = 0
carry = False

for i, cmd in enumerate(prog):
	cmd = cmd.split(":")[1]
	PROGMEM[i] = (int(cmd[:3], 2), int(cmd[3:], 2))

steps = 0

while True:
	steps += 1
	next_cmd = PROGMEM[pc][0]
	arg = PROGMEM[pc][1]
	print("%d: [%d] %s R%d Regs:%s CF:%d" % (steps, pc, CMD[next_cmd], arg, REGS, carry))
	pc += 1
	if next_cmd == CMD.index("IN"):
		num = int(intape.readline().strip().split(" ")[0])
		REGS[arg] = num & PRECISION
	if next_cmd == CMD.index("OUT"):
		outtape.write(str(REGS[arg]))
		outtape.write("\n")
	if next_cmd == CMD.index("LDA"):
		if arg == 0:
			# STOP opcode
			break
		REGS[0] = REGS[arg]
	if next_cmd == CMD.index("STA"):
		REGS[arg] = REGS[0]
	if next_cmd == CMD.index("NOR"):
		REGS[0] = ~(REGS[0] | REGS[arg]) & PRECISION
	if next_cmd == CMD.index("SUB"):
		REGS[0] -= REGS[arg]
		if REGS[0] < 0:
			carry = True
		REGS[0] &= PRECISION
	if next_cmd == CMD.index("ADD"):
		REGS[0] += REGS[arg]
		if REGS[0] > PRECISION:
			carry = True
		REGS[0] &= PRECISION
	if next_cmd == CMD.index("JCC"):
		if carry:
			pc = REGS[arg] & 0b11111
		carry = False
	if pc > 31:
		pc = 0
