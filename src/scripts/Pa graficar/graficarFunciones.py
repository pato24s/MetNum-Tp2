import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

arr = np.genfromtxt("SEPIAFATFAST")
x = [row[0] for row in arr]
y = [row[1] for row in arr]

# arro3 = np.genfromtxt("SEPIALENTO")
# d = [row[0] for row in arro3]
# e = [row[1] for row in arro3]


arrr = np.genfromtxt("SEPIALENTO")

w = [row[0] for row in arrr]
z = [row[1] for row in arrr]


# a = np.arange(2048*2048)
# b = 600*a


fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(x,y,'b', label= 'ASM- SIMD')
pylab.plot(w,z,c='g', label = 'ASM - SIN SIMD')
#pylab.plot(d,e,c='r', label= 'Co3')

#pylab.plot((a),(b), c='r', label ='f(X)=1024x')
# plt.errorbar(w, z, np.std(desvio))
ax1.set_title("SEPIA")    
ax1.set_xlabel('Cantidad de pixeles de la imagen')
ax1.set_ylabel('Cantidad de ciclos de Clock')
ax1.set_yscale('log', basey=2)
ax1.set_xscale('log', basex=2)


#ax1.plot(np.log2(x),np.log2(y), c='r', label='EL CHACHO ARRIBAS')
# pylab.plot((x),(y), c='r', label='ASM')
# pylab.plot(w,z, c='b',label='C')
leg = ax1.legend()

leg = plt.legend( loc = 'upper left')

plt.show()