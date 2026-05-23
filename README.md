# Projet-Bibliotheque-MEFM

 Description: Application de gestion de la bibliotheque universitaire prenant en compte deux types d'utilisateur, professeur ou etudiant. 
 Les utilisateurs peuvent ainsi emprunter et/ou rendre des livres, livres present dans des catalogues triés selon le titre ou l'auteur ou la categorie. 

 A savoir: 
    - un étudiant peut emprunter jusqu'a 3 livres et pendant une durée de deux minutes 
    - un professeur peut emprunter jusqu'a 5 livre et pendant une durée de 3 minute + peut ajouter des livres 


 livres.txt:
        Format : ID;Titre;Auteur;Categorie;0 ou 1 (etudiant ou professeur);durée de l'emprunt; Etat(vide ou emprunter)

 utilisateur.txt:
        Format: Identifiant; Mot de passe; statut (0=etudiant et 1=professeur);nombre d'emprunt

Architecture du code:
                     - 'donnee.h'   : constantes, structure et fonction de fonction de gestion de memoires et de regles 
                     - 'donnee.c'   : gestion de la memoire et creation de compte 
                     - 'metier.c'   : calculs des dates, régles d'emprunt et de verification
                     - 'interface.h': fonction d'affichage et du menus 
                     - 'interace.c' : affichage du menu et interaction avec l'utilisateur
                     - 'fichier.c'  : lecture et écriture des fichiers txt 
                     - 'main.c'     : fichier principal permet d'executer le tout 

Mode d'emploi: 
        - Dans la terminal : git clone https://github.com/ulkaaaaaaa/Projet-Bibliotheque-MEFM.git      //Récupère                                                              dans github les fichiers et crée un nouveau dossier avec
                             cd Projet-Bibliotheque-MEFM              //On se place dans le dossier
                             gcc main.c donnees.c fichiers.c metier.c interface.c -o bibliotheque      //On compile                                                                             le programme avec un nom ici bibliotheque
                             ./bibliotheque    //On lance le programme
         - La bibliothèque s'ouvre et il suffit alors de simplement suivre les instructions 




Repartition des taches: 

            Youssef: donnee.c; fichier.c
            Uliana : metier.c;readme; verification, unifier le code et securiser
            Jeanne : interface.c; main.c
            
Difficultés rencontrés:

La difficulté principal a été de se repartir le travail de maniere efficace, une personne les données, une les regles et l'autre l'interface, la difficulté a alors était de savoir par quoi et comment commencer. Par la suite chacun a essayer de coder de partie mais ça a crée des soucis vu qu'on s'etait pas mis d'accord sur ce que chaque fonction prennait en parametre et sur ce qu'elle renvoyé. Ainsi on a du reprendre certain code pour que ça compile bien.De plus pour l'interface le travail sur les couleurs étant nouveaux ne fut pas facile.

Solutions apportés:
Aprés les vacances voyant qu'on stagnait sur l'avancer on a prit le temps d'expliquer les avancées de chacun et on s'est mis d'accord sur la structure globale. De plus voyant que les descriptions commits n'étaient pas toujours regarder on a décidé de créer un groupe sur lequel chacun expliqué les changements apportés et c'est raison. Ce qui a permit d'avoir un meilleur aperçu sur le code globale et comment avancer


            
