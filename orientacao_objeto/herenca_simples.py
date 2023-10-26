# herança simples - Relacoes entre classes
# associacao - usa, agragaçao - tem
# composicao - é dono de, Herença - é um

# heranca vs composicao

# Classe principal (Pessoa)
# --> super class, base class, parent class
# classes filhas (cliente)
# --> sub class, child class, derived class

class Pessoa:
    def __init__(self, nome, sobrenome):
        self.nome = nome
        self.sobrenome = sobrenome

    def falar_nome_classe(self):
        print(self.nome, self.sobrenome, self.__class__.__name__)


class Cliente(Pessoa):
    ...

class Aluno(Pessoa):
    ...

c1 = Cliente('Luiz', 'Otavio')
c1.falar_nome_classe()
a1 = Aluno('Maria', 'Helena')
a1.falar_nome_classe()

