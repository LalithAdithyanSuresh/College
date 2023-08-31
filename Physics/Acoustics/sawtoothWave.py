import numpy as np
import matplotlib.pyplot as plt


rectifications = 1000
frequency =37
Ttime  = 1000

amps = []
t = np.arange(0,1/frequency*Ttime,0.001)
for i in range(1,rectifications+1):
    #a = np.sin((t*i))/i   # i(sin(frequency * time))
    a = (np.sin((t*i))*(-1**(i-1)))/i   # i(sin(frequency * time))
    if len(amps) != 0:
        for i in range(len(amps)):
            amps[i]+=a[i]
    else:
        amps = a
plt.title("SawTooth WAve With frequency of 37Hz")
plt.xlabel("Time "+ r'$\rightarrow$')
plt.ylabel("Amplitude "+ r'$\rightarrow$')
plt.axhline(y=0,color='k')
plt.axvline(x=0,color='k')
plt.plot(t,amps)
plt.show()
