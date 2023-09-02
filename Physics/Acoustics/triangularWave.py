import numpy as np
import matplotlib.pyplot as plt


rectifications =50
frequency =37
Ttime  = 1000


amps = []
t = np.arange(0,1/frequency*Ttime,0.001)
for i in range(1,rectifications+1,2):
    a = np.cos((t*i))/(i**2)
    if len(amps) == 0:
        amps = a
    else:
        for i in range(len(amps)):
            amps[i]+=a[i]
plt.title("Square Wave With frequency of 37Hz")
plt.xlabel("Time "+ r'$\rightarrow$')
plt.ylabel("Amplitude "+ r'$\rightarrow$')
plt.plot(t,amps)
plt.show()
