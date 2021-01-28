# tp2
Ce sujet faisant appels aux connaissances sur les pointeurs était quelque peu plus compliqué que le précédent.
Nous avons avancé dans ce sujet jusqu'à la question 6 (exclus).
nous avons réalisé quelques choix techniques dans ce sujets:

 - Les objets contenus dans la liste de produit des clients sont  passés par valeurs (deep copy) des objets contenus dans la liste de produit du magasin. les raisons sont les suivantes:
	 - on peut modifier les produit dans la liste client sans modifier les produits de la liste du magasin
	 - cela permet donc de préciser une quantité de produit souhaité par l'utilisateur
 - les fonctions de recherches d'éléments renvoient les pointeurs des objets de la listes mais sont privées
	 - le renvoi des pointeurs permet une modification simple des objets
	 - la mise en privée permet d'éviter les modification non souhaitées des objets 

