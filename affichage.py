#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec  2 16:44:42 2024

@author: baptiste.guilleminot
"""

import numpy as np
import matplotlib.pyplot as plt

## Affichage un graphe

fig, (ax1,ax2) = plt.subplots(2,1, figsize=(8,8), sharex=True)
data = np.loadtxt("mag_energie.txt")
steps = data[:,0]
magnet = data[:,1]
énergie = data[:,2]
ax1.plot(steps, magnet, alpha=0.7)
ax2.plot(steps, énergie, alpha=0.7)
ax1.set_ylim(-1.2,1.2)
ax1.set_ylabel("Magnétisation")
ax2.set_ylabel("Énergie interne")
ax2.set_xlabel("Champ magnétique")
fig.suptitle('Cycle d\'hystérésie du modèle d\'Ising')
plt.show()

##Affichage courbes differentes temperatures
fig, (ax1,ax2) = plt.subplots(2,1, figsize=(8,8), sharex=True)

data08 = np.loadtxt("mag_energie08.txt")
steps08 = data08[:,0]
magnet08 = data08[:,1]
énergie08 = data08[:,2]

data1 = np.loadtxt("mag_energie1.txt")
steps1 = data1[:,0]
magnet1 = data1[:,1]
énergie1 = data1[:,2]

data12 = np.loadtxt("mag_energie12.txt")
steps12 = data12[:,0]
magnet12 = data12[:,1]
énergie12 = data12[:,2]

ax1.plot(steps08, magnet08, label="T/Tc=0.8", alpha=0.7)
ax2.plot(steps08, énergie08, label="T/Tc=0.8", alpha=0.7)

ax1.plot(steps1, magnet1, label="T/Tc=1", alpha=0.7)
ax2.plot(steps1, énergie1, label="T/Tc=1", alpha=0.7)

ax1.plot(steps12, magnet12, label="T/Tc=1.2", alpha=0.7)
ax2.plot(steps12, énergie12, label="T/Tc=1.2", alpha=0.7)

ax1.set_ylim(-1.2,1.2)
ax1.set_ylabel("Magnétisation")
ax1.legend()
ax2.set_ylabel("Énergie interne")
ax2.set_xlabel("Champ magnétique")
fig.suptitle('Cycle d\'hystérésie du modèle d\'Ising')
plt.show()










