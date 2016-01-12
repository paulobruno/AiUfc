# ITALO PEREIRA DE SOUSA            344083
# PAULO BRUNO DE SOUSA SERAFIM      354086
# RAPHAELL DYEGO CRUZ VAZ           333491


import numpy as np
import math


#Importando dados
with open('pima-indians-diabetes.data') as txt:
	A = [[float(x) for x in line.split(",")] for line in txt]
txt.close()


# configuracao das matrizes de treinamento e teste

X = np.array(A) # converte array simples para array numpy de A

nrows = len(X)
ncols = len(X[0])

onesCol = np.ones((nrows,1)) # cria coluna de um's
X = np.append(onesCol, X, axis=1) # adiciona coluna de um's

np.random.shuffle(X) # embaralha as linhas

Y = X[:, ncols] # Y eh a ultima coluna da matriz
X = np.delete(X, ncols, 1) # delete a coluna Y da matriz

X = (X - np.mean(X)) / np.std(X) # normalizacao


# divisao das matrizes de treinamento e teste

X = np.split(X, 2) # divide a matriz X em duas
Xtraining = X[0] # primeira metade eh de treinamento
Xtest = X[1] # segunda eh de testes

Y = np.split(Y, 2) # analogo
Ytraining = Y[0]
Ytest = Y[1]


# treinamento

nrows = len(Xtraining)
ncols = len(Xtraining[0])

a = np.ones(ncols) # cria vetor linha de um's
aT = a.transpose()

alpha = 0.01

for i in range(0, 100):
	for j in range(0, nrows):
		
		Ynew = np.dot(Xtraining[j], aT)
		h = 1 / (1 + math.exp(-Ynew))
		
		aT = aT + alpha * (Ytraining[j] - h) * h * (1 - h) * Xtraining[j] 
		
		
# execucao dos testes

count = 0
nrows = len(Xtest)

for i in range (0, nrows):
	result = np.dot(Xtest[i], aT)
	
	if (result > 0):
		YtestNew = 1	
	else:
		YtestNew = 0
		
	if(Ytest[i] == YtestNew):
		count += 1


print "Percentage of success: " + str("%.2f" % ((float(count) / float(nrows)) * 100)) + "%"
