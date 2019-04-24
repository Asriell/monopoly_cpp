# THE Monopoly 

## Informations factuelles
par Tristan Damian 11509696, Matthieu Cherrier 11507416, Kevin Burdin 11507706


## Manuel
### Comment compiler ?
	- Aller a la racine de l'archive et ouvrir un terminal.
	- Ecrire "make".
	- Aller dans le dossier "bin" et ouvrir un terminal.

### Comment executer ?
	- Ecrire "./monopoly_txt" pour jouer a la version en mode texte.
	- Ecrire "./monopoly_sdl" pour jouer a la version en mode graphique.

### Regles du jeu :
	- Le jeu commence par vous demander combien de joueurs vous souhaitez incarner, ainsi que des 
	pseudos pour chacun d'entre eux.
	- La partie commence, chacun son tour, les joueurs devront lancer des des et progresseront sur 
	un plateau de 40 cases.
	- Chaque case etant differente, les joueurs auront devant eux un large choix d'actions, comme par
	exemple acheter une propriete, investir dans des maisons, payer des loyers ou meme aller en prison.
	- Mais attention, il faudra veiller sur sa cagnotte, car une fois qu'un joueur est ruine, il perd la partie.
	- Le dernier joueur en jeu gagne la partie !

	En mode graphique : A chaque fois qu'on appuie sur 'd', le pion d'un joueur avance d'un nombre aléatoire de cases

### Comment jouer ?
	Le jeu se joue integralement avec le clavier. Le programme vous indique sur quelle touche vous
	pouvez appuyer pour jouer. En effet, au debut du tour de chaque joueur le programme vous indique
	quelles actions vous pouvez entreprendre, les actions pouvant changer en fonction des cases.

### Les fonctionnalites du programme :

#### Le jeu en mode texte.
	Possibilite de selectionner le nombre de joueurs voulus, ainsi que le choix de pseudonymes.
	Gestion du tour de chaque joueur.
	Gestion des ressources de chaque joueur, a savoir sa cagnotte, ses proprietes avec le nombre
	de maisons achetees dessus et le nombre de cartes "libere de prison" en reserve.
	Gestion des achats de proprietes, de maisons, de compagnies...
	Gestion de la faillite des joueurs.
	Affichage regulier de toutes les informations pouvant aider le joueur dans ses choix (les actions
	possibles, les proprietes possedees, la position du joueur...)
	
#### Le jeu en mode graphique.
	Affichage des ressources du jeu, a savoir le plateau, les pions des joueurs.
	Affichage du deplacement des joueurs.
	Affichage sur le cote des caracteristiques de chaque joueur (cagnotte et cartes "libere de prison")


### Description de l'organisation de l'archive ###
#### La racine
	On y trouve le fichier "Makefile" qui servira a compiler le projet. Il y a egalement les dossiers "bin",
	 "data", "doc", "obj" et "src".
	 
```
	- Dans le dossier "src" on trouve les dossiers "sdl2" et "txt". Le dossier sdl2 contient le code
		 source du jeu en mode graphique, tandis que le dossier txt contient le code source du 
		jeu en mode texte.
	- Dans le dossier "obj" on trouve deux dossiers "sdl2" et "txt". Chacun d'entre eux contient des 
		fichiers objets.
	- Dans le dossier "doc" se trouvent les fichiers de documentation. Pour avoir une documentation 
		complete, aller dans le dossier "html" puis cliquer sur "index.html".
	- Dans le dossier "data" se trouvent tous les fichiers utilises par le programme et qui ne sont pas 
		des lignes de code. On y trouve principalement des images du jeu, mais aussi des polices.
	- Dans le dossier "bin" se situent les deux executables monopoly_sdl et monopoly_txt.

```


