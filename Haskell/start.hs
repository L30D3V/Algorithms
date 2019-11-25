soma 1 = 1
soma n = soma(n - 1) + n

fatorial 1 = 1
fatorial n = fatorial(n-1) * n

guarda x | (x == 0) = 10
         | (x == 1) = 20
         | otherwise = 100

my_and :: Bool -> Bool -> Bool
my_and False _ = False
my_and _ False = False
my_and True True = True


data Pessoa = Pessoa {nome::Nome, idade::Idade, id::RG}
type Nome = String
type Idade = Integer
type RG = String

soma_idade :: [Pessoa] -> Integer