**Voir aussi :** InstallationDeMacaon, TagsetLefff, MacaCommon

# maca\_hmm\_tagger #

Etiquetage morpho-syntaxique fondé sur un modele statistique trigramme.

| **Responsable** |AlexisNasr|
|:----------------|:---------|
| **Langage** |C |
| **Dernière version** |0.14|
| **Date** |26/11/2007|
| **URL** |[maca\_hmm\_tagger-0.14.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_hmm_tagger-0.14.tar.gz)|

### Dépendances ###
  * Librairies Macaon
    * MacaCommon
  * Librairies et programmes externes
    * [libxml2](http://xmlsoft.org/)
    * [glib2](http://www.gtk.org/)

### Commande ###
```
usage: maca_hmm_tagger [options]
OPTIONS :
      -h            : print this message
      -V            : show version
      -i <file>     : xml input file
      -o <file>     : xml output file (default is stdout)
      -v            : verbose mode
```

## Entrée ##
```
<!ELEMENT sentence (words) >

<!ELEMENT words (word*) >

<!ELEMENT word (form) >
<!ATTLIST word
          lex_id CDATA #REQUIRED >

<!ELEMENT form (#PCDATA) >
```

## Sortie ##

```
<!ELEMENT sentence (words) >

<!ELEMENT words (word*) >

<!ELEMENT word (form,pos+) >
<!ATTLIST word
          lex_id CDATA #REQUIRED >

<!ELEMENT form (#PCDATA) >

<!ELEMENT pos EMPTY >
<!ATTLIST pos
          type  CDATA #REQUIRED >
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|26/11/2007|0.14|[maca\_hmm\_tagger-0.14.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_hmm_tagger-0.14.tar.gz)|
|06/11/2007|0.13|[maca\_hmm\_tagger-0.13.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_hmm_tagger-0.13.tar.gz)|
|25/09/2007|0.12|[maca\_hmm\_tagger-0.12.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_hmm_tagger-0.12.tar.gz)|
|10/09/2007|0.11|[maca\_hmm\_tagger-0.11.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_hmm_tagger-0.11.tar.gz)|
|22/11/2006|0.4|[maca\_hmm\_tagger-0.4.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_hmm_tagger-0.4.tar.gz)|
|20/11/2006|0.3|[maca\_hmm\_tagger-0.3.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_hmm_tagger-0.3.tar.gz)|
|15/11/2006|0.2|[maca\_hmm\_tagger-0.2.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_hmm_tagger-0.2.tar.gz)|
|27/09/2006|0 |[tagger-0.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/tagger-0.tar.gz)|