# lemin

Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière (représenté par des salles passées en paramètres) par n fourmis.

L'algorythme implémenté est un BFS (Breadth-first search), qui effectue un parcours en largeur.

Plus de détails sur BFS : https://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur

Sujet complet : https://github.com/argirin/lemin/blob/master/lem-in.fr.pdf

# Usage

Compiler le projet avec la commande "make".

Utiliser l'executable "./lemin" fourni dans le dossier ressources.

Executer "./lemin < votre_map_de_test"

Le résultat s'affichera ensuite, ce sera le chemin le plus court où envoyer les fourmis en fonctions des salles passées en paramètre.
