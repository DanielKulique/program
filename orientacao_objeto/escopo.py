# escopo da classe e de métodos da classe

class Animal:
    def __init__(self, nome):
        self.nome = nome

        variavel = 'valor'
        print(variavel)
    

    def comendo(self, alimento):
        return f'{self.nome} esta comendo {alimento}'
    

leao = Animal(nome='Leao')
print(leao.nome)
print(leao.comendo('Maca'))