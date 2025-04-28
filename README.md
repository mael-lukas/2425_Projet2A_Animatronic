<h1 align="center"> DEA : Dynamic Eagle Animatronic</h1>

<p align="center">An english version of this README file can be found below the french one</p>

<h2 align="center">Préambule</h2>
Depuis la Grêce antique et le mythe du géant de bronze Talos, les hommes ont toujours cherchés à créer des automates avec les moyens à leur disposition. Les animatroniques sont l'achèvement actuel de ce désir. Ce sont des poupées mécaniques plus ou moins réalistes dont le fonctionnement interne fait intervenir autant la mécanique que l'électronique.
Elles sont, depuis plusieurs décennies, et encore aujourd'hui principalement utilisées dans le domaine du divertissement au travers des parcs d'attractions, des films et des séries.

Dans le cadre d'un projet de deuxième année à l'école d'ingénieur française ENSEA ( École Nationale Supérieure de l'Électronique et de ses Applications), nous allons continuer la création d'une animatronique d'aigle royal démarrée au second semestre de l'année dernière.

# Sommaire 
  * #### Équipe et détail des tâches
  * #### Électronique et CAO
  * #### Modélisation & Impression 3D
  * #### Mécanique
  * #### Informatique
  * #### Résultat final
  * #### Points d'amélioration
  * #### Conclusion

<table>
  <tr>
    <td><img src="Gestion de projet/diagramme_architecture.png" alt="Diagramme d'architecture" width="500" height="400"></td>
    <td><img src="Gestion de projet/architecture_code.png" alt="Diagramme d'architecture du code" width="500" height="400"></td>
  </tr>
</table>

<h1 align="center">Équipe</h1>

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

Ce projet s'articule autour de plusieurs compétences techniques : informatique, électronique & CAO, modélisation & impression 3D et mécanique. Chacune ayant partagée entre différents membres de l'équipe.

   * Informatique

Cette partie a été majoritairement traitée par Maël avec également, de manière plus minoritaire, Vincent.
Dans cette partie nous allons voir comment tout le code nécessaire au bon fonctionnement du DEA se présente. En partant de simple envoies de PWM pour commander des servomoteurs à la programmation de moteurs plus complexes, en passant par l'allumage de LED neopxiel et de la communication Bluetooth.

   * Électronique & CAO

Cette partie concerne différentes sous compétences : la conception des PCB, la soudure de ceux-ci, les test associés et finalement le sertissage et cablâge. 
Comme notre projet inclus plusieurs PCBs, leur conception a été réalisée par Vincent (pour les PCBs du corps et du gant) et Romane (pour le PCB de la tête).
Les soudures CMS ont été réalisées par Maël et Romane, tandis que les soudures THT ont été effectuées par Vincent.
Le sertissage et le cablâge ont également été réalisé par Vincent.

   * Modélisation & Impression 3D

Cette partie a été essentiellement traitée par Sedrenn aidée de Romane et Vincent. L'objectif de celle-ci étant de modéliser et d'imprimer l'aigle en taille 1:1 ainsi que des caches pour protéger l'alimentation et les PCBs.

   * Mécanique

Cette partie concerne la gestion des différents moteurs qui a été faite par Maël pour l'implémentation du code, par Vincent pour le cablâge de ceux-ci et leur placement sur la structure de l'aigle mais également par Sedrenn et Romane pour la conception des pièces 3D permettant de faire les liaisons entre ceux-ci.

<h1 align="center">Électronique & CAO</h1>

Pour commencer, veuillez trouver ci-dessous le diagramme d'architecture qui nous a servis de base pour la création des PCB de ce projet:

<div align="center">
  <img src="Gestion de projet/diagramme_architecture.png" alt="Diagramme d'architecture" width="500" height="400">
</div>

Voici donc, le schematic et le routage du PCB principal de projet, le PCB du corps :

<table>
  <tr>
    <td><img src="Hardware/pcb/Body/schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Body/routage.png" alt="Routage" width="500" height="400"></td>
  </tr>
</table>

Ce PCB a eu le droit à plusieurs versions afin de l'améliorer à chaque ittération. La dernière en date est l'ajout de R1, une résistance de pull-up pour le protocol UART qui nous sert à commander les moteurs. Cependant, une fois ce nouveau PCB soudé et testé nous n'arrivions plus à communiquer avec les moteurs donc nous sommes repassé sur la version antérieure du PCB, qui elle est foncitonnel, où la résistance de pull-up est activée sur STM32CubeIDE.
Vous pouvez trouvez [ici](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Body/ProjetCorps.csv)la BOM de ce PCB.

Le second PCB que nous avons du réalisé est celui de la tête, vous constaterez qu'il n'a pas changé depuis [l'année dernière](https://github.com/mael-lukas/2324_Projet1AB_Animatronic) voici donc simplement son schematic, son routage et sa BOM :

<table>
  <tr>
    <td><img src="Hardware/pcb/Head/Schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Head/Routage.png" alt="Routage" width="500" height="400"></td>
  </tr>
</table>

[BOM](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Head/bom%20t%C3%AAte)

Il est à noter qu'avec plus de temps nous aurions suremenent modifier ce PCB car les besoins de notre projet ont changés, nous n'avons plus besoin de contrôler six servomoteurs mais par contre nous avons besoin d'une piste GPIO pour contrôler l'état haut ou bas de la pin XSDN du [TOF](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/vl53l1x-satel.pdf).

Le troisième et dernier PCB de projet est le PCB du gant qui se présente comme suit :


<table>
  <tr>
    <td><img src="Hardware/pcb/Gant/PCB_Gant/schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Gant/PCB_Gant/routage.png" alt="Routage" width="500" height="400"></td>
  </tr>
</table>

[BOM](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Gant/PCB_Gant/PCB_Gant.csv)

L'objectif avec ce PCB est de pouvoir commander les mouvements de l'aigle avec les mouvements de nos doigts et ce sans liaison filaire mais avec une liaison bluetooth grâce au module [HC05](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/HC-05%20Datasheet.pdf). Les empreintes de résistances en 1206 correspondent aux pads des [flex sensors](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/Flex_Sensor_Datasheet_v2019a-3304101.pdf) qui sont des résistances variables qui nous permmettent grâce aux circuits visibles sur le schematic d'avoir une tension seuil à partir de laquelle on peut activer tel ou tel mouvement de l'aigle.
Pour pouvoir fonctionner via une liaison Bluetooth nous alimentons le PCB grâce à une batterie Li-ion 1S et grâce à un module servant de Boost pour pouvoir amener une tension de +5V au pcb.

Ce PCB pourrait avoir des versions plus évoluées notamment vis à vis des circuits des [flex sensors](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/Flex_Sensor_Datasheet_v2019a-3304101.pdf) qui peuvent être largement améliorer afin de par exemple pouvoir changer la tension seuil désirée avec des potentiomètres à la place des résistances.

Ce PCB permet également le contrôle du volume du haut parleur grâce à l'encodeur rotatif présent dessus. Pour revenir rapidement sur cette partie "haut parleur", l'objectif est de pouvoir jouer des sons grâce à un haut parleur présents entre les pattes de l'aigle en fonction de la distance avec la personne en face de lui grâce au [TOF](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/vl53l1x-satel.pdf).Par exemple, si je me trouve à un mètre de l'oiseau il me dira "Bonjour" par contre si je m'approche à dix centimètres de celui-ci il me dira "Recule".

Pour finir cette partie, vous pouvez voir ci-dessous quelques photos des PCB réaliés. Vous constaterez qu'ils sont chacun entourés d'un support fait en impression 3D. Ces supports ne sont pas nécessaire in fine mais ils permettent d'éviter les risques en empéchant les collisions malheureuses entre les PCB, ce qui pourrait amener des problèmes si cela se passe lorsqu'ils sont en fonctionnement.


<h1 align="center">Modélisation & Impression 3D</h1>


Maintenant que nous avons commencé à parler de modélisation 3D il est temps d'attaquer totalement cette partie. En effet, nous avons décidés d'imprimer l'aigle entièrement en 3D en le vidant bien sûr à l'intérieur afin de pouvoir y placer notre matériel. Nous avons séparés cette modélisation en 3 parties : la tête, les ailes et le reste.

## Tête
C'est sans aucun doute la partie la plus compliquée de cette modélisation car il faut la travailler pour faire en sorte que le bec et les paupières de l'aigle soit amovibles et contrôlables par des servomoteurs. Voici, ci-dessous le modèle 3D et l'impression de celle-ci.


<div align="center">
  <img src="Hardware/Mecanique/head/photos/head_full.png" alt="modélisation tête" width="500" height="400">
</div>


Le modèle 3D a été repris d'un modèle existant, puis il a du être modifié afin notamment de vider l'intérieur, pour permettre le placement des moteurs, mais aussi de rendre la bouche et les paupières ammovibles.

<table>
  <tr>
    <td><img src="Hardware/Mecanique/head/photos/head_left.png" alt="tête gauche" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/head_right.png" alt="tête droite" width="500" height="400"></td>
  </tr>
</table>

<table>
  <tr>
    <td><img src="Hardware/Mecanique/head/photos/mouth.png" alt="bouche" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/paupiere_left.png" alt="paupière gauche" width="250" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/paupiere_right.png" alt="paupière droite" width="250" height="400"></td>
  </tr>
</table>

## Ailes
À l'opposé de la tête, c'est la modééisation la plus simple de projet car elle consiste seulement en la réalisation de pièces permettant d'approximer les os de l'aigle avec des emplacements pour les moteurs de l'épaule et du coude. À cela il faut ajouter les modules rouges que vous pourrez voir ci-après qui permettent la pose des plumes.

<table>
  <tr>
    <td><img src="Hardware/Mecanique/ailes/photos/humérus.png" alt="humerus" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison coude.png" alt="coude" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison cubitus - main.png" alt="cubitus" width="400" height="300"></td>
  </tr>
</table>

<table>
 <tr>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison moteur-squelette.png" alt="moteur squelette" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison moteurs.png" alt="moteurs" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/radius.png" alt="radius" width="400" height="300"></td>
 </tr>
</table>

## Corps
Au vu du temps disponible, nous avons juste eu le temps de travailler la cage toracique de l'oiseau et donc nous avons délaissé la queue et les pattes qui n'ont pas d'autres utilités à part apporter de l'esthétique au projet, là où l'abdomen possède, lui, un réel intérêt. En effet, il nous permet de ranger à l'intérieur l'ensemble de notre électronique et de notre câblage afin que le projet ne laisse, dans l'idéal, rien apparaître de l'extérieur si tenté un câble d'alimentation.

<table>
  <tr>
    <td><img src="Hardware/Mecanique/body/partie droite.png" alt="droite" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/body/partie gauche.png" alt="gauche" width="500" height="400"></td>
  </tr>
</table>

L'impression du corps à due se faire en quatres parties car nous avions une coontrainte de temps : les impressiosns ne peuvent pas durer plus de 12h et les dimensions des imprimantes 3D qui sont trop petites pour notre modélisation. En effet, les plus grandes imprimantes 3D que nous pssédons sont des Creality K1 Max qui permettent de réaliser des impressions en 300x300x300 or le corps de l'oiseau tend plutôt sur du 350x400x200. De plus, pour l'assemblage de ces quatres parties, au vu du temps mis à disposition pour ce projet nous n'avons pas pu prévoir de moyen d'emboîter et de désemboiter cette partie. Pour que le tout se tienne nous avons donc pris le partit de coller les différentes parties avec un pistolet à colle.


<h1 align="center">Mécanique</h1>


Nous avons rapidement abordé la question des moteurs dans la partie précédente mais pour l'aborder un peu plus en profondeur, nous utilisons deux références de moteurs pour ce projet, les [FS90](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/FS90.pdf) et les [XL430](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/XL430-W250-T.pdf). Les premiers sont des servomteur 180° permettant le choix d'une position sur un plage de 180° par l'envoi d'une PWM. Nous les utilisons pour commander le bec et les yeux de l'aigle car cela ne requiert que par de force. De l'autre côté, les XL430 nous servent pour les mouvement plus complexes et surtout qui demandent plus de force. En effet, nous utilisons six de ces moteurs pour réaliser les ailes de l'oiseau, sur chaque aile nous avons deux XL430 qui sont utilisés pour reproduire l'épaule et le troisième pour reproduire ce que nous pourrions appeler le coude. 

Vous l'avez peut-être remarquez sur les photos ci-dessus mais toutes les pièces liants les XL430 ont été réalisées en impression 3D à l'exceptio de la pièce liant les deux moteurs de l'épaule. En effet, nous avions également fait une première version de cette pièce en impression 3D mais le problème était qu'elle doit pouvoir soutenir tout le poids de l'aile. Cela a causé la destruction de la version 3D de la pièce lorsqu'i fallut tester les mouvements de l'aile. Pour pallier à cela nous avons commander la pièce en métal aurpès du fournisseur et c'est donc cette pièce que vous pouvez voir sur les photos ci-dessous:

<table>
  <tr>
    <td><img src="Hardware/Mecanique/body/pièce métal moteur.jpg" alt="pièce métal droite" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/body/pièce métal moteur 2.jpg" alt="pièce métal gauche" width="500" height="400"></td>
  </tr>
</table>

<h1 align="center">Informatique</h1>


Cependant, tout cela ne pourrait pas fonctionner sans code. Voici, ci-dessous le diagramme d'architecture du code:

<div align="center">
  <img src="Gestion de projet/architecture_code.pdf" alt="architecture code" width="500" height="400">
</div>

Nous allons traiter chaque partie de code de gauche à droite d'après ce diagramme en commençant tout d'abord par le code pour la communication bluetooth entre le STM32G474RET6 et le STM32G431KBT6.

Il faut cependant noter que nous n'avons cependant pas eu le temps de le tester correctement.

Pour le code du TOF, cette partie a été particulièrement compliquée pour nous et avions finis par la laisser un peu de côté au profit d'autres parties mais finalement nous avons pu avoir accès à une librairie écrite par M. Fiack et disponible sur son github. En adaptant cette librairie au processeur que nous utilisons nous avons pu faire fonctionner le TOF correctement. 

Les XL4430 sont sans aucun doute la partie la plus complexe de tout le projet, même au bout de tant de temps à travailler dessus nous avons toujours des problèmes dont nous ne comprenons pas la présence. En particulier, lorsque l'exact même code fonctionnait une semaine auparavant.

Les LED neopixel sont quant à elles une partie assez simple que nous avions réussi à faire fonctionner par l'envoi de PWM avant de passer à une version plus avancée grâce à une librairie de M. Fiack qui utilise le DMA.

Finalement, le code du module est surement la partie qui nous a été le plus simple à réalisée et qui nous permet, avec le module suivant : https://www.gotronic.fr/art-module-mp3-uart-mp3player-38215.htm de pouvoir jouer n'importe quel son présent sur la carte micro SD.

<h1 align="center">Résultat final</h1>

Finalement à la fin de ce projet nous avons pu obtenir les résultats suivant :
* contrôle total des LED via DMA
* Audio fonctionnel (Haut parleur + module mp3)
* Moteurs XL430 et FS90 tous fonctionnels
* Modélisations et impressions finalisées
* PCB fonctionnels
* code fonctionnel

CI-dessous vous pouvez télécharger une vidéo avec l'actionnement des 6 moteurs XL430 ainsi que des photos du rendu final de l'aigle:

[Voir la vidéo](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Gestion%20de%20projet/moteurs%20fonctionnels.mp4)

<table>
  <tr>
    <td><img src="Gestion de projet/final1.jpg" alt="final 1" width="700" height="400"></td>
    <td><img src="Gestion de projet/final2.jpg" alt="final 2" width="700" height="400"></td>
  </tr>
</table>


<h1 align="center">Points d'amélioration</h1>


 Comme vous avez pu le voir le rendu des modélisations 3D n'est vraiment satisfaisant, ce qui devait être un aigle vacille visuellement entre un vautour et un aigle et un dindon.
 Il faudrait donc pour la suite de projet prévoir une refonte totale de l'apparence de l'oiseau quitte à même refaire une base et abandonner l'actuelle en métal.
 De plus, nous n'avons pas réussi à utiliser correctement le capteur de distance, en partie du au fait que le PCB sur lequel il doit être branché date du projet 2324 et qu'il   
 comporte un nombre d'erreurs assez importante. 
 De plus, le PCB du corps mériterait aussi quelques ajustement, notamment au niveau des valeurs et tailles des composants pour qu'ils s'adaptent à ceux que nous avons à l'école.
 Il faudrait également refaire une partie du câblage qui était manquante ou mal faîte à la fin du projet.
 À toutes ces améliorations s'en ajouteront d'autres qui en découlent.
 
<h1 align="center">Conclusion</h1>

Malgré le fait que ce projet n'a pas pu être complété au bout d'un an et demi de travail nous sommes conscient qu'il nous a permis à tous de nous améliorer de façon exponentielle dans chacun des aspects que ce projet à pu couvrir. Nous pensons donc continuer à travailler dessus afin de le finir dans une version bien meilleure version à compter de Septembre durant ce qui sera notre 3ème et dernière annèe à l'ENSEA.

************************************************************************************************************************************************************************************

<h1 align="center">ENGLISH VERSION</h1>

************************************************************************************************************************************************************************************

<h2 align="center">Preamble</h2>
Since ancient Greece and the myth of the bronze giant Talos, humans have always sought to create automatons with the means at their disposal. Animatronics are the current culmination of this desire. They are more or less realistic mechanical dolls whose internal functioning involves both mechanics and electronics.
For several decades, and still today, they are mainly used in the entertainment industry through theme parks, films, and series.

As part of a second-year project at the French engineering school ENSEA (École Nationale Supérieure de l'Électronique et de ses Applications), we will continue the creation of a golden eagle animatronic started in the second semester of last year.

# Table of Contents 
  * #### Team and Task Details
  * #### Electronics and CAD
  * #### 3D Modeling & Printing
  * #### Mechanics
  * #### Computer Science
  * #### Final Result
  * #### Points for Improvement
  * #### Conclusion

<table>
  <tr>
    <td><img src="Gestion de projet/diagramme_architecture.png" alt="Architecture Diagram" width="500" height="400"></td>
    <td><img src="Gestion de projet/architecture_code.png" alt="Code Architecture Diagram" width="500" height="400"></td>
  </tr>
</table>

<h1 align="center">Team</h1>

Team members: 
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

* #### Supervised by Nicolas Papazoglou
    * [Github](https://github.com/DBXYD?tab=overview&from=2024-05-01&to=2024-05-29)
    * [Linkedin](https://www.linkedin.com/in/nicolas-papazoglou-38382646/?originalSubdomain=fr)
 
* #### Supervised by Laurent Fiack
    * [Github](https://github.com/lfiack)
    * [Linkedin](https://fr.linkedin.com/in/laurent-fiack-1b1415124)

We invite you to consult our [GitHub from last year](https://github.com/mael-lukas/2324_Projet1AB_Animatronic), where you can find all the foundations on which we based this project.

This project is built around several technical skills: computer science, electronics & CAD, 3D modeling & printing, and mechanics. Each area was divided among different team members.

   * Computer Science

This part was mainly handled by Maël, with some minor contributions from Vincent.
In this section, we will see how all the code necessary for the proper functioning of the DEA is organized. Starting from simple PWM signals to control servomotors, to programming more complex motors, and including the control of neopixel LEDs and Bluetooth communication.

   * Electronics & CAD

This part concerns different sub-skills: PCB design, soldering, associated testing, and finally crimping and cabling.
As our project includes several PCBs, their design was carried out by Vincent (for the body and glove PCBs) and Romane (for the head PCB).
The SMD soldering was done by Maël and Romane, while the THT soldering was carried out by Vincent.
Crimping and cabling were also performed by Vincent.

   * 3D Modeling & Printing

This part was mainly handled by Sedrenn, aided by Romane and Vincent. The goal was to model and print the eagle at a 1:1 scale as well as protective covers for the power supply and PCBs.

   * Mechanics

This part concerns the management of the different motors, which was done by Maël for the code implementation, by Vincent for the wiring of the motors and their placement on the eagle structure, and also by Sedrenn and Romane for the design of the 3D printed parts used to link everything together.

<h1 align="center">Electronics & CAD</h1>

To start, please find below the architecture diagram that served as the basis for the PCB creation for this project:

<div align="center">
  <img src="Gestion de projet/diagramme_architecture.png" alt="Architecture Diagram" width="500" height="400">
</div>

Here are the schematic and routing of the main project PCB, the body PCB:

<table>
  <tr>
    <td><img src="Hardware/pcb/Body/schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Body/routage.png" alt="Routing" width="500" height="400"></td>
  </tr>
</table>

This PCB underwent several versions to improve it with each iteration. The latest version added R1, a pull-up resistor for the UART protocol used to control the motors. However, once this new PCB was soldered and tested, we could no longer communicate with the motors, so we reverted to the previous functional version of the PCB, where the pull-up resistor is activated via STM32CubeIDE.
You can find the [BOM here](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Body/ProjetCorps.csv) for this PCB.

The second PCB we had to create is the head PCB, which has not changed since [last year](https://github.com/mael-lukas/2324_Projet1AB_Animatronic). Therefore, here is simply its schematic, routing, and BOM:

<table>
  <tr>
    <td><img src="Hardware/pcb/Head/Schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Head/Routage.png" alt="Routing" width="500" height="400"></td>
  </tr>
</table>

[BOM](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Head/bom%20t%C3%AAte)

It should be noted that, with more time, we would probably have modified this PCB because our project needs have changed: we no longer need to control six servomotors, but we do need a GPIO track to control the high or low state of the XSDN pin of the [TOF](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/vl53l1x-satel.pdf).

The third and final project PCB is the glove PCB, which is presented as follows:

<table>
  <tr>
    <td><img src="Hardware/pcb/Gant/PCB_Gant/schematic.png" alt="Schematic" width="500" height="400"></td>
    <td><img src="Hardware/pcb/Gant/PCB_Gant/routage.png" alt="Routing" width="500" height="400"></td>
  </tr>
</table>

[BOM](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Hardware/pcb/Gant/PCB_Gant/PCB_Gant.csv)

The goal with this PCB is to control the eagle's movements using our finger motions without a wired connection, but through Bluetooth communication via the [HC05](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/HC-05%20Datasheet.pdf) module. The 1206 resistor footprints correspond to the pads of the [flex sensors](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/Flex_Sensor_Datasheet_v2019a-3304101.pdf), which are variable resistors. Thanks to the circuits shown in the schematic, we can detect a threshold voltage that triggers specific eagle movements.

To function via Bluetooth, the PCB is powered by a 1S Li-ion battery, and a boost module is used to bring the voltage up to +5V for the PCB.

This PCB could evolve further, especially regarding the circuits for the [flex sensors](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/Flex_Sensor_Datasheet_v2019a-3304101.pdf), which could be improved significantly, for example, by allowing adjustable threshold voltages using potentiometers instead of fixed resistors.

The PCB also enables control of the speaker volume through the rotary encoder present on it. Speaking of the "speaker" part, the goal here is to play sounds using a speaker located between the eagle's legs, depending on the distance from the person in front of it via the [TOF sensor](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/vl53l1x-satel.pdf).  
For instance, if I am one meter away, the eagle will say "Hello", whereas if I move to ten centimeters, it will say "Back off."

To conclude this section, you can see below a few photos of the assembled PCBs. You will notice that each one is surrounded by a 3D-printed protective support. These supports are not strictly necessary but help avoid risks by preventing accidental collisions with the PCBs, which could cause malfunctions during operation.

<h1 align="center">3D Modeling & Printing</h1>

Now that we have started talking about 3D modeling, it's time to fully dive into this part. Indeed, we decided to entirely 3D-print the eagle, making it hollow inside to accommodate our hardware.  
We divided the modeling into three parts: the head, the wings, and the body.

## Head
This is undoubtedly the most complex part of the modeling because it must be adapted so that the eagle’s beak and eyelids are movable and controllable via servomotors. Below are the 3D model and the printed version.

<div align="center">
  <img src="Hardware/Mecanique/head/photos/head_full.png" alt="Head Model" width="500" height="400">
</div>

The 3D model was based on an existing model but was modified, particularly to hollow out the inside to place the motors, and to make the beak and eyelids movable.

<table>
  <tr>
    <td><img src="Hardware/Mecanique/head/photos/head_left.png" alt="Head Left" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/head_right.png" alt="Head Right" width="500" height="400"></td>
  </tr>
</table>

<table>
  <tr>
    <td><img src="Hardware/Mecanique/head/photos/mouth.png" alt="Mouth" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/paupiere_left.png" alt="Left Eyelid" width="250" height="400"></td>
    <td><img src="Hardware/Mecanique/head/photos/paupiere_right.png" alt="Right Eyelid" width="250" height="400"></td>
  </tr>
</table>

## Wings
Contrary to the head, this was the simplest part to model. It only involved creating parts to approximate the eagle’s bones and include mounts for the shoulder and elbow motors.  
Additionally, there are small red modules that allow the attachment of the feathers.

<table>
  <tr>
    <td><img src="Hardware/Mecanique/ailes/photos/humérus.png" alt="Humerus" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison coude.png" alt="Elbow" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison cubitus - main.png" alt="Cubitus" width="400" height="300"></td>
  </tr>
</table>

<table>
 <tr>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison moteur-squelette.png" alt="Motor-Skeleton Link" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/liaison moteurs.png" alt="Motor Links" width="400" height="300"></td>
    <td><img src="Hardware/Mecanique/ailes/photos/radius.png" alt="Radius" width="400" height="300"></td>
 </tr>
</table>

## Body
Given the limited time, we only managed to model the eagle’s ribcage.  
The tail and legs were omitted as they are mainly aesthetic, whereas the torso has a practical role: it houses all the electronics and wiring to ensure that ideally, no cables are visible externally (except the power cable).

<table>
  <tr>
    <td><img src="Hardware/Mecanique/body/partie droite.png" alt="Right Part" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/body/partie gauche.png" alt="Left Part" width="500" height="400"></td>
  </tr>
</table>

The body was printed in four parts due to time constraints (no prints over 12h allowed) and because the available 3D printers were too small.  
Our largest printers, the Creality K1 Max, allow prints up to 300x300x300 mm, but the eagle's body was closer to 350x400x200 mm.  
Additionally, due to time limitations, we could not design interlocking assembly parts, so the four sections were simply glued together using a hot glue gun.

<h1 align="center">Mechanics</h1>

We briefly mentioned the motors earlier, but to go deeper:  
We used two motor types: [FS90](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/FS90.pdf) and [XL430](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Datasheets/XL430-W250-T.pdf).  
The FS90 are small 180° servomotors controlled by PWM signals, used for light-duty tasks such as controlling the beak and eyelids.  
The XL430, on the other hand, are more powerful and were used for heavier movements such as the wings, where strength is necessary.  
Each wing uses three XL430 motors: two for the shoulder and one for the elbow.

You may have noticed in the previous photos that all the parts connecting the XL430s were 3D-printed, except for the part linking the two shoulder motors.  
Initially, this was also 3D-printed, but it broke during testing due to the stress.  
Thus, we ordered a metal replacement from the supplier, as shown below:

<table>
  <tr>
    <td><img src="Hardware/Mecanique/body/pièce métal moteur.jpg" alt="Metal Motor Part Right" width="500" height="400"></td>
    <td><img src="Hardware/Mecanique/body/pièce métal moteur 2.jpg" alt="Metal Motor Part Left" width="500" height="400"></td>
  </tr>
</table>

<h1 align="center">Computer Science</h1>

However, all of this would not work without code. Below is the architecture diagram of the code:

<div align="center">
  <img src="Gestion de projet/architecture_code.pdf" alt="architecture code" width="500" height="400">
</div>

We will address each part of the code from left to right according to this diagram, starting first with the code for Bluetooth communication between the STM32G474RET6 and the STM32G431KBT6.

It should be noted, however, that we did not have time to properly test it.

As for the TOF code, this part was particularly complicated for us, and we ended up leaving it aside in favor of other parts, but eventually, we were able to access a library written by Mr. Fiack and available on his GitHub. By adapting this library to the processor we are using, we were able to get the TOF working correctly.

The XL4430 motors are undoubtedly the most complex part of the entire project. Even after so much time working on them, we still encounter issues that we do not understand. In particular, the exact same code worked a week ago.

The neopixel LEDs, on the other hand, are quite simple, and we were able to get them working by sending PWM signals before moving to a more advanced version using a library by Mr. Fiack that utilizes DMA.

Finally, the code for the MP3 module was probably the simplest part for us to develop. With this module: https://www.gotronic.fr/art-module-mp3-uart-mp3player-38215.htm, we were able to play any sound on the micro SD card.

<h1 align="center">Final Result</h1>

At the end of this project, we were able to achieve the following results:
* Full control of the LEDs via DMA
* Functional audio (Speaker + MP3 module)
* Functional XL430 and FS90 motors
* Finalized models and prints
* Functional PCBs
* Functional code

Below you can download a video showing the operation of the 6 XL430 motors, as well as photos of the final rendering of the eagle:

[View the video](https://github.com/mael-lukas/2425_Projet2A_Animatronic/blob/main/Gestion%20de%20projet/moteurs%20fonctionnels.mp4)

<table>
  <tr>
    <td><img src="Gestion de projet/final1.jpg" alt="final 1" width="700" height="400"></td>
    <td><img src="Gestion de projet/final2.jpg" alt="final 2" width="700" height="400"></td>
  </tr>
</table>

<h1 align="center">Points for Improvement</h1>

As you can see, the 3D modeling results are not really satisfactory. What was supposed to be an eagle visually fluctuates between an eagle, a vulture, and a turkey. Therefore, for the continuation of the project, it would be necessary to redesign the appearance of the bird, possibly even remaking the base and abandoning the current metal one. Furthermore, we were not able to use the distance sensor properly, partly due to the fact that the PCB it should be connected to dates from the 2324 project and contains quite a few significant errors. Additionally, the PCB for the body would also require some adjustments, particularly in terms of the values and sizes of components to make them fit those we have at school. The wiring also needs to be redone, as it was missing or poorly done by the end of the project. Many more improvements will come as a result of these.

<h1 align="center">Conclusion</h1>

Although this project could not be completed after a year and a half of work, we are aware that it allowed all of us to improve exponentially in each of the aspects that this project covered. Therefore, we plan to continue working on it to finish it in a much better version starting in September during what will be our 3rd and final year at ENSEA.
