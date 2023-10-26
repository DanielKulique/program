#super é a super classe na sub classe
# Classe principal (Pessoa)
# --> super class, base class, parent class
# Classes filhas (Cliente)
# -> sub class, child class, derived class

class MinhaString(str):
    def upper(self):
        print('CHAMOU UPPER')
        return super().upper()
        

string = MinhaString('Luiz')
print(string.upper())