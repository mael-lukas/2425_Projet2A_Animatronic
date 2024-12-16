# 2425_Projet2A_Animatronic
Projet ENSEA 2A Animatronic

# DEA : Dynamic Eagle Animatronic

Depuis la Grêce antique et le mythe du géant de bronze Talos les hommes ont toujours cherchés à créer des automates avec les moyens à leur disposition. Les animatroniques sont l'achèvement actuel de ce désir. Ce sont des poupées mécaniques plus ou moins réalistes dont le fonctionnement interne fait intervenir autant de la mécanique que de l'électronique.
Elles sont depuis plusieurs décennies et encore aujourd'hui principalement utilisées dans le domaine du divertissement au travers des parcs d'attraction, des films et des séries.

Dans le cadre d'un projet de deuxième année à l'école d'ingénieur ENSEA supervisé par [M.Papazoglou](https://github.com/DBXYD?tab=overview&from=2024-05-01&to=2024-05-29) et [M.Fiack](https://github.com/lfiack) nous allons continuer une animatronique d'aigle.

<table>
  <tr>
    <td><img src="Gestion de projet/architecture_code.png" alt="Diagramme d'architecture du code" width="500" height="400"></td>
    <td><img src="Gestion de projet/diagramme_architecture.png" alt="Diagramme d'architecture" width="500" height="400"></td>
  </tr>
</table>

[Diagramme d'architecure du code](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Gestion%20de%20projet/architecture_code.png)
[Diagramme d'architecure](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Gestion%20de%20projet/diagramme_architecture.png)


# Equipe
Membres de l'équipe : 
* #### Vincent Fernandes
    * [Github](https://github.com/FernandesVincent)
    * [Linkedin](https://www.linkedin.com/in/vincent-fernandes-0981552a6/)
* #### Maël Lukas
    * [Github](https://github.com/mael-lukas)
    * [Linkedin](https://www.linkedin.com/in/mael-lukas/)
* ##### Romane Ponthieu
    * [Github](https://github.com/Romanepnth)
    * [Linkedin](https://www.linkedin.com/in/romane-ponthieu/)
* #### Sedrenn Labrousse
    * [Github](https://github.com/Sedrennl)
    * [Linkedin](https://www.linkedin.com/in/sédrenn-labrousse-24b2a5295/)

* #### Supervisé par Nicolas Papazoglou
    * [Github](https://github.com/DBXYD?tab=overview&from=2024-05-01&to=2024-05-29)
    * [Linkedin](https://www.linkedin.com/in/nicolas-papazoglou-38382646/?originalSubdomain=fr)
 
* #### Supervisé par Laurent Fiack
    * [Github](https://github.com/lfiack)
    * [Linkedin](https://fr.linkedin.com/in/laurent-fiack-1b1415124)

Nous vous invitons à consulter notre [github de l'année dernière](https://github.com/mael-lukas/2324_Projet1AB_Animatronic), dans lequel vous pourrez trouver toutes les bases sur lesquelles nous avons démarré ce projet.

# Journal de bord

## Séance 1
   Cette séance, étant la première, nous a servit à définir les nouveaux objectifs de notre projet : nous voulons finaliser complètement notre aigle, c'est-à-dire finir la modélisation 3D, et finir le code. De plus, nous voulons ajouter des noyvelles fonnctionnalités à notre aigle : nous voulons le faire crier en fonction de la distance de l'utilisateur, et nous voulons qu'il s'illumine. Pour y voir plus clair, nous avons effectué une première version du diagramme d'architecture. Afin de nous organiser au mieux au vu du temps disponible pour ce projet, nous nous sommes directement répartit différentes tâches à réaliser durant les semaines qui suivent.
   * #### Modélisation 3D de l'aigle
        * [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse)
   * #### Programmation 
        * [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas)
   * #### Conception des différents PCB
        * [Romane](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#romane-ponthieu)
        * [Vincent](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#vincent-fernandes)
    

## Séance 2
   Durant cette séance nous avons affiné notre diagramme d'architecture.

   Nous avons repris les PCB que nous avions conçus l'année dernière, nous en avions 3. Nous avons commencé à chercher aux solutions que nous allons utiliser pour pouvoir effectuer toutes les fonctionnalités que nous voulons avec notre aigle. Nous avons cherché les composants dont nous allons avoir besoin par la suite afin d'effectuer une commande pour tous les composants dont nous ne disposons pas à l'école. 
   Pendant ce temps, [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) a avancé sur la modélisation 3D et [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) a continué le code qu'il avait commencé l'année dernière.

   
## Séance 3
   À cette étape du projet nous avons choisis de changer de microprocesseur, afin d'en utiliser un ayant assez de PIN pour effectuer toutes les fonctionnalités que nous souhaitons. Nous avons donc commencé à concevoir les nouveaux PCB dont nous allons avoir besoin en fonction de ce microprocesseur.
  En parallèle de cela, [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) a continué le code des moteurs qu'il avait commencé et [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) a commencé à concevoir le squelette de l'animatronic.

   
## Séance 4
   Cette séance a permis la finalisation des schematic des 3 [PCB](https://github.com/mael-lukas/2324_Projet1AB_Animatronic?tab=readme-ov-file#pcb) crées sous Kicad et ainsi le passage à l'étape PCB editor pour les membres affectés à cette partie du projet.
   Pendant ce temps [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) a finalisé une première version du code des moteurs XL430 et [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) a finalisé le squelette de l'aigle.

![Squelette de l'aigle](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/M%C3%A9canique/squelette%20aigle.png)

   
## Séance 5
   Durant cette séance, nous avons effectuer une première présentation du projet à nos professeurs, qui ont pu nous guider et voir notre avancée.
   Par la suite, M.Papazoglou et M. Fiack ont pu vérifier les 3 [PCB](https://github.com/mael-lukas/2324_Projet1AB_Animatronic?tab=readme-ov-file#pcb) et nous faire des retours pour que l'on puisse corriger nos erreurs et effectuer des nouvelles modifications.
   M. Fiack a aussi revu les codes des moteurs avec [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) et il a pu corriger tous les problèmes qu'il rencontrait.


## Séance 6
   Au cours de cette séance nous avons reçu les commandes de composants ainsi que les PCB.  [Vincent](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#vincent-fernandes) et [Romane](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#romane-ponthieu) ont donc pu soudé les PCB durant ces 4 heures.
   En parralèle à cela, [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) a commencé à modéliser des liaisons permettant de fixer les moteurs qui vont faire bouger les ailes sur le squelette.
  [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas), quant à lui, a commencé le code permettant de programmer le ruban néopixel.

   
## Séance 7
   Au cours de cette séance, nous avons effectuer une deuxième présentation du projet à M. Papazoglou et M. Fiack, dans lequel nous avons fait un point sur ceque nous avions fini et cequ'il nous restait à faire. 
   Ensuite, [Romane](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#romane-ponthieu) et [Vincent](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#vincent-fernandes) se sont réorientés sur de nouveaux sujets : Romane va aider [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) pour la modélisation 3D de l'aigle et Vincent va s'occuper du code du TOF.
   
   Pendant ce temps [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) a imprimé une première liaison moteur-squelette et l'a testée par la suite. [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) a continué le code du ruban néopixel, en effectuant des premiers tests.

   <table>
  <tr>
    <td><img src="Hardware/Mécanique/liaison moteur-squelette.png" alt="liaison moteur-squelette" width="400" height="300"></td>
  </tr>
</table>

   
## Séance 8
   Au cours de cette séance, [Vincent](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#vincent-fernandes) a continué le code permettant de faire fonctionner le TOF et [Maël](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#ma%C3%ABl-lukas) l'a aidé.
   D'un autre côté, [Sedrenn](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#sedrenn-labrousse) et [Romane](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#romane-ponthieu) ont réfléchi à un mécanisme permettant d'effectuer les mouvements de l'aigle d'un aigle.

 <table>
  <tr>
    <td><img src="Hardware/Mécanique/mécanisme ailes aigles.png" alt="mécanisme ailes aigles" width="400" height="300"></td>
  </tr>
</table>


   
## Séance 9
  Durant cette séance nous avons réalisé une première présentation orale du projet DEA. De plus, nous avons eu les impression 3D des nouvelles et dernières versions du cache de l'alimentation ainsi que de la tête de l'aigle, toutes deux présentées ci-dessous:

<table>
  <tr>
    <td><img src="Etude oiseau /Modelisation3D/cachev2.jpg" alt="cachev2" width="500" height="400"></td>
    <td><img src="Etude oiseau /Modelisation3D/tetev2.jpg" alt="tetev2" width="500" height="400"></td>
  </tr>
</table>

  
## Séance 10
   
   Au cours de cette dernière séance, nous avons assemblé la tête de l'aigle avec les différents PCB crée au cours des séance précédentes afin de permettre une ouverture et une fermeture du bec ainsi que le mouvement des paupières, ce que nous avons réussi comme en témoigne [la vidéo de démonstration du projet](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#rendu-final).

   Pour faire un bilan de ce projet revenons à la base de celui-ci et comparons le à notre rendu final. Au début du projet notre objectif était de réaliser un animatronique d'aigle capable de différents mouvements de la tête ainsi que des ailes, cependant dans notre [rendu final](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#rendu-final) nous avons seulement réussi à avoir la tête dans laquelle le bec et la paupière bougent. Cette différence s'explique par la difficulté liée à l'ambition d'un tel projet, en effet il y a eu plusieurs difficultés dans ce projet tel que des problèmes au niveau des PCB (problèmes de soudure, d'inversion de placement de SDA et SLC entre deux PCB et autres) ou encore sur la création de librairies pour la partie programmation et des modélisations 3D qui ont nécessitées plusieurs versions pour être opérationnelles. 
   Malgré tout cela, l'ensemble du groupe est fier et heureux d'avoir réussi à obtenir ce [résultat](https://github.com/mael-lukas/2324_Projet1AB_Animatronic/tree/main?tab=readme-ov-file#rendu-final) et ce projet ne s'arrête pas ici puisque, en effet, le groupe dans son ensemble a décidé de poursuivre ce projet durant la deuxième année de notre cursus afin de finir ce qui était prévu initialement. 
   Cependant, nous avons décidé de ne pas nous arrêter à ce que nous avions prévu et nous commencons déjà à réfléchir à des améliorations pour le DEA tel que:
   1. Un speaker dans le bec de l'aigle lié à un capteur de distance pour changer ce que l'aigle dit en fonction de la distance avec son interlocuteur.
   2. Un système permettant de contrôler les mouvements de l'aigle en fonction des mouvement de la main de l'utilisateur.
   3. Une application permettant de changer la vitesse des moteurs, la couleur des LED des yeux et de jouer certaines séquences de mouvement de l'aigle.

Ces idées ne sont encore que des réflexions et seront amennées a évoluées au cours de l'année qui arrive.
