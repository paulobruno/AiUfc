# ITALO PEREIRA DE SOUSA            344083
# PAULO BRUNO DE SOUSA SERAFIM      354086
# RAPHAELL DYEGO CRUZ VAZ           333491


import numpy as np


# importacao de dados

with open('housing.data') as txt:
    A = [[float(x) for x in line.split()] for line in txt]
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


# divisao das matrizes de treinamento e teste

X = np.split(X, 2) # divide a matriz X em duas
Xtraining = X[0] # primeira metade eh de treinamento
Xtest = X[1] # segunda eh de testes

Y = np.split(Y, 2) # analogo
Ytraining = Y[0]
Ytest = Y[1]


# treinamento

XtrainingT = Xtraining.transpose()

a = np.dot(XtrainingT, Xtraining)
a = np.linalg.inv(a)
a = np.dot(a, XtrainingT)
a = np.dot(a, Ytraining)


# execucao

newY = np.dot(Xtest, a)

Error = Ytest - newY
ErrorRelative = Error / Ytest
ErrorSquare = np.multiply(Error, Error)
ErrorSquareRelative = np.multiply(ErrorRelative, ErrorRelative)

print "Mean Squared Error: " + str("%.4f" % (np.average(ErrorSquare)))
print "Mean Squared Relative Error: " + str("%.4f" % (np.average(ErrorSquareRelative)))


# saida em arquivo

output = open("linearRegressionResults.txt", "w")
np.savetxt(output, zip(Ytest, newY, ErrorSquare), fmt="%.4f")
output.close()
