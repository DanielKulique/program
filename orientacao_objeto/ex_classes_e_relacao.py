# exercicio com classes
# 1 - Crie uma classe Carro
# 2 - Crie uma classe motor 
# 3 - Crie uma classe Fabricante
# 4 - faça a ligacao entre Carro e Tem Motor
# um motor pode ser de varios carros
# 5 - Faca a ligacao entre Carro e Fabricante
# Um fabricante pode fabricar varios carros
# Exiba o nome do carro, motor e fabricante na tela

class Carro:
    def __init__(self, nome):
        self.nome = nome
        self._motor = None
        self._fabricante = None
    
    @property
    def motor(self):
        return self._motor 
    
    @motor.setter
    def motor(self, valor):
        self._motor = valor
    
    @property
    def fabricante(self):
        return self._fabricante
    
    @fabricante.setter
    def fabricante(self, valor):
        self._fabricante = valor

class Motor:
    def __init__(self, nome):
        self.nome = nome
    
class Fabricante:
    def __init__(self, nome):
        self.nome = nome

fusca = Carro('Fusca')
volkswagen = Fabricante('Volkswagen')
motor_1_0 = Motor('1.0')
fusca.fabricante = volkswagen
fusca.motor = motor_1_0
print(fusca.nome, fusca.fabricante.nome, fusca.motor.nome)

fiat_uno = Carro('fiat_uno')
fiat = Fabricante('fiat')
motor_1_0 = Motor('1.0')
fiat_uno.fabricante = fiat
fiat_uno.motor = motor_1_0
print(fiat_uno.nome, fiat_uno.fabricante.nome, fiat_uno.motor.nome)
