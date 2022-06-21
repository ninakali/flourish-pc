import netpbmfile


def get_bitmap(array, idx):
	bitmap = []
	idx = idx - 32
	offx = (idx % 16) * 4
	offy = int(idx / 16) * 6
	for i in range(offy, offy+6):
		b0, b1, b2, b3 = array[i][offx:offx+4]
		print("0b%d%d%d%d0000," % (b0, b1, b2, b3))




header = """PROGMEM const unsigned char font4x6[] = {
4,6,32,"""

t = netpbmfile.NetpbmFile("font4x6.pbm")
blob = t.asarray()

print(header)

for i in range(32, 128):
	info = "// %d - [%s]" % (i, chr(i))
	print(info)
	get_bitmap(blob, i)

print("};")
