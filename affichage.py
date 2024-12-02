#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec  2 16:44:42 2024

@author: baptiste.guilleminot
"""

import numpy as np
import matplotlib.pyplot as plt
fig, (ax1,ax2) = plt.subplots(2,1, figsize=(8,8), sharex=True)
data = np.loadtxt("mag_energie.txt")
steps = data[:,0]
magnet = data[:,1]
énergie = data[:,2]
ax1.plot(steps, magnet, alpha=0.7)
ax2.plot(steps, énergie, alpha=0.7)
ax1.set_ylim(-1,1)
ax1.set_ylabel("Magnétisation")
ax2.set_ylabel("Énergie interne")
ax2.set_xlabel("Nombre de pas de l'algorithme")