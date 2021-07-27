import sys
import matplotlib.pyplot as plt
import numpy as np

ypoints = np.array([])

f = open(sys.argv[1],"r")
len = 1
for x in f:
    ypoints = np.append(ypoints,int(x))
    len=len+1
f.close()

xpoints = np.arange(start=1, stop=len, step=1)

plt.plot(xpoints, ypoints)
plt.xlabel('No. of. Updates')
plt.ylabel('congestion window(cw)')
plt.title(sys.argv[3])
plt.savefig(sys.argv[2],dpi=300,bbox_inches='tight')
