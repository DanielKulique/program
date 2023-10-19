# parâmetro, recebemos a própria classe.

class Pessoa:
    ano = 2023 #atributo de classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade 
    
    @classmethod
    def metodo_de_classe(cls):
        print('hey')
    
    @classmethod
    def criar_com_50_anos(cls, nome):
        return cls(nome, 50)


p1 = Pessoa('João', 34)
p2 = Pessoa.criar_com_50_anos('Helena')

print(p2.nome, p2.idade)