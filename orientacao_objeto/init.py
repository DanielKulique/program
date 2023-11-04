# class - classes são moldes para criar novos objetos

# as classes geram novos objetos (instancias) que 
# podem ter seus proprias atributos e metodos

# Os objetos gerados pela classe podem usar seus dados
# internos para realizar varias ações

# por convencao, usamos PascalCase para nomes de classos

class Pessoa:
    def __init__(self, nome, sobrenome):
        self.nome = nome
        self.sobrenome = sobrenome

p1 = Pessoa('Luiz', 'Otavio')

p2 = Pessoa('Maria', 'Joana')

print(p1.nome)
print(p1.sobrenome)

print(p2.nome)
print(p2.sobrenome)