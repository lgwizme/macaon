**Voir aussi :** InstallationDeMacaon, MacaLex, MacaCommon

# maca\_anamorph #

Ce module utilise le lefff et ajoute des traits morphologiques aux mots en fonction de leur forme et de leur partie du discours.

| **Responsable** |AlexisNasr|
|:----------------|:---------|
| **Langage** |C |
| **Dernière version** |0.5|
| **Date** |28/05/2007|
| **URL** |[maca\_anamorph-0.5](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_anamorph-0.5.tar.gz)|

### Dépendances ###
  * Librairies Macaon
    * MacaCommon
    * MacaLex
  * Librairies et programmes externes
    * [libxml2](http://xmlsoft.org/)

### Commande ###
```
usage: maca_anamorph [options]
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

<!ELEMENT words (word+) >
<!ATTLIST words
          count CDATA #IMPLIED >

<!ELEMENT word (form,pos+) >
<!ATTLIST word
          lex_id CDATA #IMPLIED >

<!ELEMENT form (#PCDATA) >

<!ELEMENT pos EMPTY >                                                                      
<!ATTLIST pos                                                                                  
          type  CDATA #REQUIRED >         
```

## Sortie ##
Le module ajoute à chaque 

&lt;pos&gt;

 des 

&lt;word&gt;

s du lexique les 

&lt;lemma&gt;

s associés et les trait morphologiques correspondants.
```
<!ELEMENT sentence (words) >                                                                   
                                                                                               
<!ELEMENT words (word+) >                                                                      
<!ATTLIST words                                                                                
          count CDATA #IMPLIED >                                                               
                                                                                               
<!ELEMENT word (form,pos+) >                                                                   
<!ATTLIST word                                                                                                                                        
          lex_id CDATA #IMPLIED >                                                                
                                                                                               
<!ELEMENT pos (lexeme*) >                                                                      
<!ATTLIST pos                                                                                  
          type  CDATA #REQUIRED >                                                               
                                                                                               
<!ELEMENT lexeme (morpho*) >                                                                   
<!ATTLIST lexeme                                                                               
          lemma CDATA #REQUIRED >                                                              
                                                                                               
<!ELEMENT morpho EMPTY >                                                                       
<!ATTLIST morpho                                                                               
          mode CDATA #IMPLIED                                                                  
          person CDATA #IMPLIED                                                                
          number CDATA #IMPLIED                                                                
          gender CDATA #IMPLIED                                                                
          tense CDATA #IMPLIED                                                                 
          type CDATA #IMPLIED                                                                  
          case CDATA #IMPLIED >                                                                
                                                                                               
<!ELEMENT form (#PCDATA) >   
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|20/11/2006|0.3|[maca\_anamorph-0.3.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_anamorph-0.3.tar.gz)|
|15/11/2006|0.2|[maca\_anamorph-0.2.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/maca_anamorph-0.2.tar.gz)|
|27/09/2006|0.0|[anamorph-0.tar.gz](http://www.lif-sud.univ-mrs.fr/~nasr/macaon/anamorph-0.tar.gz)|





