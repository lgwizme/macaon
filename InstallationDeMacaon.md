# Introduction #

Les modules s'installent séparément. Pour avoir des informations plus completes il est parfois utile de consulter la discribution de chaque module. Les informations renseignées dans cette page ne sont que des pistes générales.

**Attention** : Sachiez que vous pouvez tomber sur des nombreuses complications pendant l'installation de la chaîne. Faites attention aux dépendances et n'hésitez pas à contacter les développeurs et/ou à ajouter des "[issues](http://code.google.com/p/macaon/issues/list)".

# Détails #

Voici un schéma de dépendances:

![http://farm4.static.flickr.com/3662/3348352756_358b17521e_o.png](http://farm4.static.flickr.com/3662/3348352756_358b17521e_o.png)

## Préinstallation ##

Assurez vous que votre système possède les dépendances externes. Installez d'abord toute dépendance externe manquante. Pour l'instant, la chaîne à été installé avec succès sur les plate-formes:
  * linux : debian (sarge), fedora (core 6), centOS5
  * osx : tiger (sur une machine powerpc avec XCode et MacPorts)
  * unix : FreeBSD (6.2)

## Ordre recommandé ##

  1. Vérification des dépendances
  1. MacaCommon
  1. MacaLex
  1. MacaLexer
  1. MacaHmmTagger
  1. MacaAnaMorph
  1. MacaSegmenter
  1. MacaTokenizer
  1. [MacaNEMatcher](http://code.google.com/p/macaon/wiki/MacaNEMatcher)
  1. MacaChunker

## Module par module ##

Voici le sommaire des commandes d'installation pour chaque module. Notez qu'il y a des différences.

### MacaCommon ###
```
./configure
make
make install
```

### MacaLex ###
```
./configure
make
make install
```

### MacaLexer ###
```
./configure
make
make install
```

### MacaHmmTagger ###
```
./configure
make
make install
```

### MacaAnamorph ###
```
./configure
make
make install
```

### MacaSegmenter ###
```
./configure
make
make install
```

### MacaTokenizer ###
```
make
make install
```

### MacaNEMatcher ###
```
make
make install
```

### MacaChunker ###
```
./configure
make
make install
```

Si cela ne marche pas, essayez :
```
aclocal
autoconf
./configure
make
make install
```