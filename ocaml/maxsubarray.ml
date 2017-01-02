let rec maxsubarray arr =
  match arr with
    []      -> raise (Failure "empty list")
  | [x]     -> (x, x)
  | (x::xs) ->
      let sum, maxsum = maxsubarray xs in
        let newsum = sum + x in
          ((max 0 newsum), (max maxsum newsum))

let main () =
  let sum, maxsum = maxsubarray [-2; 1; -3; 4; -1; 2; 1; -5; 4] in
    print_int maxsum ; print_newline ()

;;

main ()
