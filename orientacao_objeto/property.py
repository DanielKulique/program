# @property -- um getter no modo pythonico
# getter -- um metodo para obter um atributo
# cor - get_cor()
# modo pythonico - modo do Python de fazer coisas
# @property é uma propriedade do objeto, ela é metodo que se comporta como um atributo

# geralmente é usada nas seguintes situaçoes : como getter, 
# para evitar quebra de codigo cliente, habilitar setter ou executar açoes ao obter uma atributo
# codigo cliente - é o codigo que usa o seu codigo

class Caneta:
    def __init__(self, cor):
        self.cor_tinta = cor

    #def get_cor(self):
    #   print('GET COR')
    #   return self.cor_tinta
    
    @property
    def cor(self):
        return self.cor_tinta

caneta = Caneta('Azul')
print(caneta.cor)
