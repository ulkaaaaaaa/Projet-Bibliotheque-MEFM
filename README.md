# Projet-Bibliotheque-MEFM

 Description: Application de gestion de la bibliotheque universitaire prenant en compte deux types d'utilisateur, professeur ou etudiant. 
 Les utilisateurs peuvent ainsi emprunter et ou rendre des livres, livres present dans des catalogues triés selon le titre ou l'auteur ou la     categorie. 

 A savoir: - un étudiant peut emprunter jusqu'a 3 livres et pendant une durée de deux minutes 
           - un professeur peut emprunter jusqu'a 5 livre et pendant une durée de 3 minute + peut ajouter des livres 

Architecture du code:
                     - 'donnee.h'   : constantes, structure et fonction de fonction de gestion de memoires et de regles 
                     - 'donnee.c'   : gestion de la memoire et creation de compte 
                     - 'metier.c'   : calculs des dates, régles d'emprunt et de verification
                     - 'interface.h': fonction d'affichage et du menus 
                     - 'interace.c' : affichage du menu et interaction avec l'utilisateur
                     - 'fichier.c'  : lecture et écriture des fichiers txt 
                     - 'main.c'     : fichier principal permet d'executer le tout 




            
