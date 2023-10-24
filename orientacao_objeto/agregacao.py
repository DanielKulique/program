# Agregacao é uma forma mais especializada de associaçao entre dois ou mais objetos
# Seu ciclo de vida é independente 
# Objeto tem um ou muitos objetos

# Os objetos podem viver separadamente, mas pode
# se tratar de uma relacao onde um objeto precisa de
# outro para fazer determinada tarefa

class Carrinho: 
    def __init__(self):
        self._produtos = [] #criou uma lista de produtos

    def total(self):
        return sum([p.preco for p in self._produtos]) # metodo somar total dos produtos
    
    def listar_produtos(self): #metodo listar nome e preco de produtos
        print()
        for produto in self._produtos:
            print(produto.nome, produto.preco)
        print()
    
    def inserir_produtos(self, *produtos):  # metodo inserir novos produtos na lista
        for produto in produtos:
            self._produtos.append(produto)

class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

carrinho = Carrinho()
p1, p2 = Produto('Caneta', 1.39), Produto('Camiseta', 20)
carrinho.inserir_produtos(p1, p2)
carrinho.listar_produtos()
print(carrinho.total())