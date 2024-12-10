#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec  2 16:44:42 2024

@author: baptiste.guilleminot
"""

import numpy as np
import matplotlib.pyplot as plt
fig, (ax1,ax2) = plt.subplots(2,1, figsize=(8,8), sharex=True)
data1 = np.loadtxt("mag_energieT_1.txt")
data12 = np.loadtxt("mag_energieT_12.txt")
data08 = np.loadtxt("mag_energieT_08.txt")
ax1.plot(data1[:300,0], data1[:300,1], label='T=1', alpha=0.7)
ax2.plot(data1[:300,0], data1[:300,2], label='T=1', alpha=0.7)
ax1.plot(data12[:300,0], data12[:300,1], label='T=1.2', alpha=0.7)
ax2.plot(data12[:300,0], data12[:300,2], label='T=1.2', alpha=0.7)
ax1.plot(data08[:300,0], data08[:300,1], label='T=0.8', alpha=0.7)
ax2.plot(data08[:300,0], data08[:300,2], label='T=0.8', alpha=0.7)
ax1.set_ylim(-1,1)
ax1.set_ylabel("Magnétisation")
ax2.set_ylabel("Énergie interne")
ax2.set_xlabel("Nombre de pas de l'algorithme (1e4)")
ax1.legend()
ax2.legend()
plt.show()