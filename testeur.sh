# Testeur automatique.

tester() {
    # $1 : le programme à tester
    # $2 : le fichier de test à utiliser

    # Initialiser les variables pour le test
    prog="$1"	# le programme à tester
    test="$2"	# le fichier de test à utiliser
    result="$test".result	# les résultats obtenus
    expected="$test".expected	# les résultats attendus

    # Lancer du test
    "$prog" "$test" > "$result"

    # Afficher les résultats
    echo -n "$prog $test... "
    if diff "$expected" "$result" > /dev/null 2>&1 ; then
	echo ok
    else
	echo KO
    fi
    rm "$result"
}

tester ./interpreteur-lca-recursive exemple1.lca
tester ./interpreteur-lca-iterative exemple1.lca
tester ./interpreteur-th exemple1.th
