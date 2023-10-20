#encapsulamento (modificadores de acesso, public, protected, private) não há em python. É apenas convençoes
#sem underline = public
    #usado em qualquer lugar
#um unnderline = protected
    #nao deve ser usado fora da classe ou de subclasses
#dois underline = private 
    #"name mangling (desfiguraçao de nomes)"
    #só deve ser usado na classe que foi declarado

class Foo:
    def __init__(self):
        self.public = 'isso é publico'
        self._protected = 'isso é protegido'
        self.__private = 'isso é privado'

    def metodo_publico(self):
        self._metodo_protected()
        print(self._protected) 
        return 'metodo publico'
    
    def _metodo_protected(self):
        print('_metodo_protected')
        return '_metodo_protected'
    
f = Foo()
print(f.metodo_publico())