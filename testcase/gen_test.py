import random 
def gen_test():
	a = []
	for i in range(1000000):
		r=round(random.uniform(0, 100), 5)
		a.append(r)
	return a
def write(filename, arr):
    	f = open(filename, "w")
    	print(*arr, file = f, sep = "\n")
    	f.close()
for i in range(0, 10):
	a = gen_test()
	if i == 0:
		a=sorted(a)
	elif i == 1:
		a=sorted(a)
		a.reverse()    	
	write("testcase{}.txt".format(i + 1), a)