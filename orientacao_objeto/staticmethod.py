# metodos dentro da classe sem acesso ao self ou cls.
# são funçoes dentro da classe.

class Classe:
    @staticmethod
    def funcao_que_esta_na_classe(*args, **kwargs):
        print('Oi', args, kwargs)

c1 = Classe()
c1.funcao_que_esta_na_classe(1,2,3)