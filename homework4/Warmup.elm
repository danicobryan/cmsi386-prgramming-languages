module Warmup exposing (..)
import Html exposing (Html, text)
import List exposing (map, foldr, filter)
import Array

{-- A function that accepts a number of U.S. cents and returns a tuple containing, respectively,
    the smallest number of U.S. quarters, dimes, nickels, and pennies that equal the given amount. --}

{-- A function that accepts a string and returns a new string equivalent to the argument
    but with all apostrophes and double quotes removed. --}


-- A function that returns a list of successive powers of a base starting at 1 and going up to some limit.


-- A function that returns the sum of the cubes of all of the odd integers in a list. Use map, filter, and foldr.

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds l =
  List.filter (\a -> a % a)(l)
  , List.map (\b -> b * b * b)(l)
  , List.foldr (l)(+)
  , List.take (1)(l)


{-- A function that returns the number of days between two dates,
    where the dates are given as strings in the format "YYYY-MM-DD". --}
