import numpy as np
np.set_printoptions(suppress=True)
t = int(input())
while t>0 :
	t = t - 1
	n = int(input())
	tmp = (n+1)/2
	tmp = tmp * tmp
	tmp = tmp*2 - 1
	ans = tmp * (tmp-2) * (tmp-4)
	print(ans)