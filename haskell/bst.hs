module Main where

data Tree t = Br t (Tree t) (Tree t) | Lf

insert :: Ord t => Tree t -> t -> Tree t
insert Lf x = Br x Lf Lf
insert tree@(Br v lt rt) x | x > v = Br v lt (insert rt x)
                           | x == v = tree
                           | x < v = Br v (insert lt x) rt

preorder :: Ord t => Tree t -> [t]
preorder Lf = []
preorder (Br v lt rt) = (preorder lt) ++ [v] ++ (preorder rt)

main = let xs = [10, 5, 6, 7, 8, 2, 4, 3, 1, 9] in
         let tree = foldl insert Lf xs in
           print (preorder tree)
