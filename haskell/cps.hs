module Main where

add_cps :: Int -> Int -> (Int -> r) -> r
add_cps x y = \k -> k (x + y)

mul_cps :: Int -> Int -> (Int -> r) -> r
mul_cps 0 _ = \k -> k 0
mul_cps _ 0 = \k -> k 0
mul_cps x 1 = \k -> k x
mul_cps x y = \k -> mul_cps x (y-1) $ \s -> add_cps s x $ k

main = mul_cps 8 9 print
