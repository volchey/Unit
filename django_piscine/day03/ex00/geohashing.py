import antigravity, sys

def geohash():
	if (len(sys.argv) != 4):
		print("Wrong argument count")
		return

	antigravity.geohash(float(sys.argv[1]), float(sys.argv[2]), sys.argv[3].encode('utf-8'))

if __name__ == '__main__':
	geohash()
