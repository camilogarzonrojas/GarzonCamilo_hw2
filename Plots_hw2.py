import numpy as np
import matplotlib.pyplot as plt

coeficientesW=["1.9","1.2","0.5","1.55"]
for i in range(4):
    u1,u2,u3,t=np.genfromtxt('datosOde'+str(i+1)+'.dat', unpack=True)
    fig, ax = plt.subplots(1,3, figsize=(9, 3), sharey=True)
    ax[0].plot(t,u1,"r",color="black")
    ax[0].set_title("Primer piso")	
    ax[1].plot(t,u2,"r",color="green")
    ax[1].set_title("Segundo piso")
    ax[2].plot(t,u3,"r",color="yellow")
    ax[2].set_title("Tercer piso")
    fig.suptitle("W = "+coeficientesW[i]+"sqrt(k/m)")
    plt.tight_layout(pad=2.4, w_pad=1.5, h_pad=1.0)
    fig.savefig("GarzonCamilo_U"+str(i+1)+"vsT.pdf")

