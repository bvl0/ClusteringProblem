#!/usr/bin/env python3
import os
import re
import numpy as np
import pandas as pd
import subprocess

# Remove a notação científica
np.set_printoptions(suppress=True)

N_INPUT_FILES = 5
N_ITERATIONS = 50

entradas = []
for inputFile in range(0, N_INPUT_FILES):
    entradas.append(np.array([]))

k = {1: 2, 2: 4, 3: 5, 4: 5, 5: 10}

for i in range(N_ITERATIONS):
    for inputFile in range(1, N_INPUT_FILES + 1):
        print(f"Testando {inputFile}.txt pela {i + 1}ª vez")

        aux = subprocess.run(
            [
                "./trab1",
                f"./data/in/in-exemplos/{inputFile}.txt",
                f"{k[inputFile]}",
                f"./data/outAuto/{inputFile}.txt",
            ],
            stdout=subprocess.PIPE,
            universal_newlines=True,
        )
        y = aux.stdout

        floats = re.findall("\d+\.\d+", y)
        floats = [float(string) for string in floats]

        if i == 0:
            entradas[inputFile - 1] = np.array(floats)
        else:
            entradas[inputFile - 1] = np.vstack((entradas[inputFile - 1], floats))

medias = []
for inputFile in range(0, N_INPUT_FILES):
    medias.append(entradas[inputFile].mean(axis=0))

mediasNpArray = np.array(medias)
# print(medias)

df = pd.DataFrame(mediasNpArray)

stringsEntrada = []
for inputFile in range(1, N_INPUT_FILES + 1):
    stringsEntrada.append(f"Entrada {inputFile}")
df.index = stringsEntrada

df.columns = ["Leitura", "Distâncias", "Ordenação", "MST", "Agrupamento", "Escrita", "Total"]

print("\\begin{table}[h]", "\centering", sep=("\n"))
print(df.to_latex())
print("\end{table}")
