**Voir aussi :** InstallationDeMacaon, MacaCommon, MacaLex

# maca\_lexer #

Regroupe les atomes en mots du lexique du lefff.

| **Responsable** |AlexisNasr|
|:----------------|:---------|
| **Langage** |C |
| **Dernière version** |0.15|
| **Date** |26/11/2007|
| **URL** |[maca\_lexer-0.15.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.15.tar.gz)|

### Dépendances ###
  * Librairies Macaon
    * MacaCommon
    * MacaLex
  * Librairies et programmes externes
    * [libxml2](http://xmlsoft.org/)
    * [glib2](http://www.gtk.org/)

### Commande ###
```
usage: maca_lexer [options]
OPTIONS :
      -h            : print this message
      -V            : show version
      -i <file>     : xml input file (default is stdin)
      -o <file>     : xml output file (default is stdout)
      -v            : verbose mode
      -m <integer>  : maximum tokens in word (default = 6)
      -n <integer>  : number of solutions (default = 1)
```

## Entrée ##

```
<!ELEMENT sentence (tokens) >

<!ELEMENT tokens (token|ne)+ >
<!ATTLIST tokens >

<!ELEMENT token (#PCDATA) >
<!ATTLIST token
          type CDATA #IMPLIED
          id ID #REQUIRED >

<!ELEMENT ne (token+) >
<!ATTLIST pos CDATA #IMPLIED
          type CDATA #REQUIRED >
```

## Sortie ##

```
<!ELEMENT sentence (tokens,words) >

<!ELEMENT tokens (token|ne)+ >

<!ELEMENT token (#PCDATA) >
<!ATTLIST token
          type CDATA #IMPLIED
          id ID #REQUIRED >

<!ELEMENT ne (token+) >
<!ATTLIST pos CDATA #IMPLIED
          type CDATA #REQUIRED >

<!ELEMENT words (word+) >
<!ATTLIST words
          count CDATA #IMPLIED >

<!ELEMENT word (form) >
<!ATTLIST word
          id ID #REQUIRED
          tokens IDREFS #REQUIRED
          lex_id CDATA #IMPLIED >

<!ELEMENT form (#PCDATA) >
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|26/11/2007|0.15|[maca\_lexer-0.15.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.15.tar.gz)|
|06/11/2007|0.14|[maca\_lexer-0.14.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.14.tar.gz)|
|17/10/2007|0.12|[maca\_lexer-0.12.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.12.tar.gz)|
|25/09/2007|0.11|[maca\_lexer-0.11.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.11.tar.gz)|
|10/09/2007|0.10|[maca\_lexer-0.10.tar.gz](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/macaon/maca_lexer-0.10.tar.gz)|
|25/06/2007|0.8|[maca\_lexer-0.8.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.8.tar.gz)|
|22/06/2007|0.7|[maca\_lexer-0.7.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.7.tar.gz)|
|18/06/2007|0.6|[maca\_lexer-0.6.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.6.tar.gz)|
|28/05/2007|0.5|[maca\_lexer-0.5.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.5.tar.gz)|
|20/11/2006|0.3|[maca\_lexer-0.3.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.3.tar.gz)|
|15/11/2006|0.2|[maca\_lexer-0.2.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_lexer-0.2.tar.gz)|
|27/09/2006|0 |[lexer-0.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/lexer-0.tar.gz)|