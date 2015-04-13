# Introduction #

Nous décrivons dans cette page un certain nombre de conventions du projet.

## Nommage ##

Les noms des modules, librairies, etc. utilisent le préfixe : `maca_`

## Options des modules ##

Les options standards pour les modules sont :
```
-V             affichage de la version
-h             affichage de l'aide
-v             affichage de messages en cours d'exécution
-i <fichier>   lire le fichier <fichier> en entrée
-o <fichier>   écrire la sortie dans le fichier <fichier>
```

## maca\_stamp ##

Tout module qui modifie un document macaon doit par défaut laisser une trace dans le fichier de son traitement sous la forme d'un `maca_stamp`.

La structure d'un `maca_stamp` est définie comme :
```
<!ELEMENT maca_stamp EMPTY>
<!ATTLIST maca_stamp
          module CDATA #REQUIRED
          version CDATA #REQUIRED
          timestamp CDATA #REQUIRED >
```

Les `maca_stamps` se trouvent sous l'élément `meta` d'un document macaon :
```
<meta>
   <maca_stamps>
      <maca_stamp module="maca_segmenter" timestamp="Fri Nov 24 18:57:23 2006" version="2.3"/>
      <maca_stamp module="maca_tokenizer" timestamp="Fri Nov 24 18:57:23 2006" version="1.1"/>
      <maca_stamp module="maca_nematcher" timestamp="Fri Nov 24 18:57:23 2006" version="1.4.2"/>
      <maca_stamp module="maca_lexer" timestamp="Mon Nov 27 18:24:13 2006" version="0.3"/>
      <maca_stamp module="maca_hmm_tagger" timestamp="Mon Nov 27 18:24:13 2006" version="0.4"/>
      <maca_stamp module="maca_chunker" timestamp="Mon Nov 27 18:30:54 2006" version="2.3b"/>
   </maca_stamps>
</meta>
```