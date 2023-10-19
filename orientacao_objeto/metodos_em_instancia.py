# metodos em instancias de classes python
# hard coded - É algo escrito diretamento no codigo.

class Carro:
    def __init__(self, nome='sla'): #metodo init sempre retorna none
        self.nome = nome

    def acelerar(self):
        print(f'{self.nome} está acelerando...')

fusca = Carro('Fusca')
print(fusca.nome)
fusca.acelerar()

celta = Carro('Celta')
print(celta.nome)
celta.acelerar()