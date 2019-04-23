import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import ifft, fft, fftfreq

#Se cargan y almacenan los datos de los archivos
x1,y1=np.genfromtxt('signal.dat', unpack=True) #Archivo con ondas separadas
x2,y2=np.genfromtxt('signalSuma.dat', unpack=True) #Archivo con la suma de las ondas

#Se hacen subplots de los datos originales
plt.figure()
fig,ax=plt.subplots(2,1,figsize=(10,10))
ax[0].plot(x1,y1,c='purple')
ax[1].plot(x2,y2,c='black')

ax[0].set_xlabel('x')
ax[0].set_ylabel('y')
ax[1].set_xlabel('x')
ax[1].set_ylabel('y')

ax[0].set_title('Signal')
ax[1].set_title('Signal Suma')
plt.savefig('GarzonCamilo_signal.pdf')
plt.close()


#Se define la implementacion propia de la transformada discreta de Fourier
pi=np.pi
def Fourier(y):
    N=len(y)
    fase=[]
    for k in range(N):
        s=0+0j
        for n in range(N):
            s+=y[n]*np.exp(-(2j*pi*k*n)/N)
        fase.append(s)
    return np.array(fase)


#Grafica para signal.dat
dx=x1[1]-x1[0]
fase=Fourier(y1)
freq=np.fft.fftfreq(len(y1),dx)
FR=np.sqrt(np.real(fase)**2+np.imag(fase)**2)

#Grafica para signalSuma.dat
dx2=x2[1]-x2[0]
fase2=Fourier(y2)
freq2=np.fft.fftfreq(len(y2),dx2)
FR2=np.sqrt(np.real(fase2)**2+np.imag(fase2)**2)

plt.figure()
plt.plot(freq,FR,c='red',label='Signal')
plt.plot(freq2,FR2,c='yellow',label='Signal Suma')
plt.legend(loc=0)
plt.xlim(-800,800)
plt.xlabel('Frecuencia')
plt.ylabel('Amplitud')
plt.title('Transformada de Fourier de Signal y Signal Suma')
plt.savefig('GarzonCamilo_TransformadasFourier.pdf')
plt.close()


#Espectrogramas
plt.figure()
plt.specgram(y1,Fs=2,NFFT=256,noverlap=128)
plt.xlabel('Tiempo')
plt.ylabel('Frecuencia')
plt.title('Espectrograma de Signal')

plt.figure()
plt.specgram(y2,Fs=2,NFFT=256)
plt.xlabel('Tiempo')
plt.ylabel('Frecuencia')
plt.title('Espectrograma de Signal Suma')


#Se almacenan los datos de temblor.txt
datos_temblor=np.genfromtxt('temblor.txt',skip_header=4)
t=np.linspace(-5000,5000,90001)

#Se grafican los datos del temblor
plt.figure()
plt.plot(t,datos_temblor,c='c')
plt.title('Datos del temblor')
plt.xlabel('Tiempo')
plt.ylabel('Amplitud')
