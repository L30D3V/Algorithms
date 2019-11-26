-- Lista 02
-- Atividade 02

import Data.Char

type Nome   = String
type Idade  = Integer
type RG     = String
data Pessoa = Pessoa {nome::Nome, idade::Idade, id::RG}

somaIdade = foldr ((+) . idade) 0

-- Atividade 03
instance Ord Pessoa where p <= p1 = idade p <= idade p1
minIdade (a:b) = nome $ foldr min ((a . idade) b)

-- Atividade 06
joinr:: Eq a => a -> [a] -> [a]
joinr x [] = [x]
joinr x xs  | x == head xs = xs
            | otherwise = [x] ++ xs

remdupsr:: Eq a => [a] -> [a]
remdupsr [] = []
remdupsr (y:ys) = foldr joinr [y] ys

-- Atividade 07
import Data.Map (fromListWith, toList)

contaAdjs :: Ord a => [a] -> [Int, a]
contaAdjs xs = toList (fromListWith (+) [(x, 1) | x <- xs])