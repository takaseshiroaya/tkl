# -*- coding: utf-8 -*-


f_fuji = open("./data/fujisawa_tsuugakuro_20170201.txt", encoding="utf8")
#f_kana = open("./local/crossings_kanagawa2.csv")
f_kana = open("./local/kanagawa_test.csv")



import numpy as np
import matplotlib.pyplot as plt


fuji = np.loadtxt(f_fuji, delimiter=",", skiprows=1, usecols=(1,2,3))
print(np.amax(fuji[:,1]),np.amax(fuji[:,2]),np.amin(fuji[:,1]),np.amin(fuji[:,2]))

#print(fuji)
"""
plt.scatter(fuji[:,1],fuji[:,2],s=5, marker="o")
plt.grid(True)
plt.show()
"""


kana = np.loadtxt(f_kana, delimiter=",", usecols=(0,1,2))
print(np.amax(kana[:,1]),np.amax(kana[:,2]),np.amin(kana[:,1]),np.amin(kana[:,2]))


"""
plt.scatter(kana[:,1],kana[:,2],s=1, marker="o")
plt.grid(True)
plt.show()
"""