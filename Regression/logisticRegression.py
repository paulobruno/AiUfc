import numpy as np


# importacao de dados

with open('pima-indians-diabetes.data') as txt:
    A = [[float(x) for x in line.split(",")] for line in txt]
txt.close()


# configuracao das matrizes de treinamento e teste

npA = np.array(A) # cria array numpy de A

nrows = len(npA)
onesCol = np.ones((nrows,1)) # cria coluna de um's
npA = np.append(onesCol, npA, axis=1) # adiciona coluna de um's

np.random.shuffle(npA) # embaralha as linhas
npA = np.split(npA, 2) # divide a matriz em duas

Xtraining = npA[0] # primeira matriz eh a de treinamento
Xtest = npA[1] # segunda eh a de testes


# treinamento

nrows = len(Xtraining)
ncols = len(Xtraining[0])

Ytraining = Xtraining[:,ncols-1] # y recebe a ultima coluna da matriz de dados

Xtraining = np.delete(Xtraining, ncols-1, 1) # apaga a coluna y de x
XtrainingT = Xtraining.transpose()

a = np.dot(XtrainingT, Xtraining)
a = np.linalg.inv(a)
a = np.dot(a, XtrainingT)
a = np.dot(a, Ytraining)


# configuracao do teste

nrows = len(Xtest)
ncols = len(Xtest[0])

Ytest = Xtest[:,ncols-1] # y recebe a ultima coluna da matriz de dados
Xtest = np.delete(Xtest, ncols-1, 1) # apaga a coluna y de x


# execucao

newY = np.dot(Xtest, a)

E = Ytest - newY

Esquare = np.multiply(E, E)

output = open('errorOutput.txt', 'w')
np.savetxt(output, Esquare)
output.close()

print Ytest
print newY
print np.average(Esquare)
#print E
#print Esquare
