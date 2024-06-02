import sys

"""
Very tiny assembler program that converts our toy assembly
language into bits for the RAM
"""


CMD = ["IN", "OUT", "LDA", "STA", "NOR", "SUB", "ADD", "JCC", "STOP"]

inf = open(sys.argv[1]).read().split("\n")
outf = open(sys.argv[2], "w")

idx = 0

for line in inf:
	print(line)
	orig_line = line
	line = line.strip()
	if len(line) == 0:
		# empty string
		continue
	
	if line[0] == "#" or line[0] == "'":
		# comment
		continue

	outf.write(format(idx, '03d'))
	outf.write(":")

	line = line.split(" ")
	if line[0].isdigit():
		# ignore line numbers
		line.pop(0)
	cmd = CMD.index(line[0].upper())
	if line[0] != "STOP":
		outf.write(format(cmd, '03b'))
	if line[0] == "STOP":
		outf.write(format(CMD.index("LDA"), '03b'))
		outf.write("000")
	elif line[1] == "A":
		outf.write("000")
	else:
		# R0-R7
		reg = int(line[1][1])
		if reg < 0 or reg > 7:
			raise IndexError("Registers can only be R0-R7")
		outf.write(format(reg, '03b'))
	outf.write(":")
	outf.write(orig_line)
	outf.write("\n")
	idx += 1
	if idx > 32:
		raise IndexError("Ran out of program memory")

