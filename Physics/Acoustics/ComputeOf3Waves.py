import numpy as np
import matplotlib.pyplot as plt
#Graph Values:
time = 20
t1 = np.arange(0,time*np.pi,0.01)
a1= np.sin(t1)
t2 = np.arange(0,time*np.pi,0.01)
a2 = (np.cos((t2/2)+np.pi/2))/2
t3 = np.arange(0,time*np.pi,0.01)
a3 = (np.sin((t3/1.5)-np.pi/4))/1.5
Time = 30
Ft1 = np.arange(0,Time*np.pi,0.01)
Fa1= np.sin(Ft1*2)
Ft2 = np.arange(0,Time*np.pi,0.01)
Fa2 = (np.cos((Ft2/2)+np.pi/2))/2
Ft3 = np.arange(0,Time*np.pi,0.01)
Fa3 = (np.sin((Ft3/1.5)-np.pi/4))/1.5
a4= []
for i in range(0,len(Fa1)):
    a4.append((Fa1[i]+Fa2[i]+Fa3[i])/3)
#Assigning Graphs its Position
figure,axis = plt.subplots(3,2)
axis[0,0].plot(t1,a1,color='r')
axis[0,0].set_title("Graph - 1")
axis[0,0].set_xlabel('Time'+ r'$\rightarrow$')
axis[0,0].set_ylabel('Amplitude'+ r'$\rightarrow$')
axis[0,0].axhline(y=0,color='k')
axis[0,0].axvline(x=0,color='k')
axis[0,1].plot(t2,a2,color='g')
axis[0,1].set_title("Graph - 2")
axis[0,1].set_xlabel('Time'+ r'$\rightarrow$')
axis[0,1].set_ylabel('Amplitude'+ r'$\rightarrow$')
axis[0,1].axhline(y=0,color='k')
axis[0,1].axvline(x=0,color='k')
axis[1,0].plot(t3,a3,color='b')
axis[1,0].set_title("Graph - 3")
axis[1,0].set_xlabel('Time'+ r'$\rightarrow$')
axis[1,0].set_ylabel('Amplitude'+ r'$\rightarrow$')
axis[1,0].axhline(y=0,color='k')
axis[1,0].axvline(x=0,color='k')
axis[2,0].plot(Ft3,a4,color='y')
axis[2,0].set_title("Combination of 3 Graphs")
axis[2,0].set_xlabel('Time'+ r'$\rightarrow$')
axis[2,0].set_ylabel('Amplitude'+ r'$\rightarrow$')
axis[2,0].axhline(y=0,color='k')
axis[2,0].axvline(x=0,color='k')
axis[1,1].plot(t1,a1,color='r',label='Graph 1')
axis[1,1].plot(t2,a2,color='g',label='Graph 2')
axis[1,1].plot(t3,a3,color='b',label='Graph 3')
axis[1,1].set_xlabel('Time'+ r'$\rightarrow$')
axis[1,1].set_ylabel('Amplitude'+ r'$\rightarrow$')
axis[1,1].set_title("Representing 3 Waves")
axis[1,1].axhline(y=0,color='k')
axis[1,1].axvline(x=0,color='k')
axis[1,1].legend()
plt.subplots_adjust(left=0.05, bottom=0.05, right=0.98, top=0.97, wspace=0.11, hspace=0.26)
plt.show()
print(t1)
print(a1)
