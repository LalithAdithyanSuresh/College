import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


rectifications =200
frequency =37
Ttime  = 1000


amps = []
t = np.arange(0,1/frequency*Ttime,0.001)
for i in range(1,rectifications+1,2):
    a = np.sin((t*i))/i
    if len(amps) == 0:
        amps = a
    else:
        for i in range(len(amps)):
            amps[i]+=a[i]
amps /= int(rectifications/2)

plt.plot(t,amps)
plt.show()
