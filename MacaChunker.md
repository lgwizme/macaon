**Voir aussi :** InstallationDeMacaon, TagsetChunker, GrammairesChunker

# maca\_chunker #

Permet de définir et utiliser une cascade de transducteurs déterministes pour regrouper des symboles et construire une analyse syntaxique superficielle d'une séquence d'étiquettes morpho-syntaxiques.

| **Responsable** |AlejandroAcosta|
|:----------------|:--------------|
| **Langage** |C++|
| **Dernière version** |2.3.1|
| **Date** |2006/12/20|
| **Distribution** |[maca\_chunker-2.3.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_chunker-2.3.1.tar.gz)|

## Dépendances ##
  * Librairies et programmes externes
    * automake
    * Perl
    * sh
    * [flex](http://flex.sourceforge.net/)
    * [xerces-c](http://xml.apache.org/xerces-c/) (XML)

## Commande ##
```
USAGE   : maca_chunker [options]
OPTIONS :
   -h               print this message
   -V               show version
   -v               verbose mode (print messages)
   -i <file>        xml input file (default is stdin)
   -o <file>        xml output file (default is stdout)
   -T               don't leave timestamp info
   -s               display stats on exit

eg. maca_chunker -i in.xml -o out.xml -v

```

## Entrée ##
Un document avec des phrases découpées en mots associés à des parties du discours.

```
<!ELEMENT sentence (words) >

<!ELEMENT words (word*) >

<!ELEMENT word (pos) >
<!ATTLIST word
          id ID #REQUIRED >

<!ELEMENT form (#PCDATA) >

<!ELEMENT pos EMPTY >
<!ATTLIST pos
          tag  CDATA #REQUIRED >
```

## Sortie ##

```
<!ELEMENT sentence (words,chunks) >

<!ELEMENT words (word*) >

<!ELEMENT word (pos) >
<!ATTLIST word
          id ID #REQUIRED >

<!ELEMENT pos EMPTY >
<!ATTLIST pos
          tag  CDATA #REQUIRED >

<!ELEMENT chunks (chunk+) >
<!ATTLIST chunks 
          count CDATA #IMPLIED  
          higher CDATA #IMPLIED > 

<!ELEMENT chunk (chunk*) >
<!ATTLIST chunk
          height (0|1|2|3|4|5|6|7|8|9) 
          type CDATA #REQUIRED         
          subtype CDATA #IMPLIED       
          head IDREF #REQUIRED         
          id ID #REQUIRED >
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|2006/12/20|2.3.1|[maca\_chunker-2.3.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_chunker-2.3.1.tar.gz)|
|2006/09/29|2.1|[chunker-2.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-2.1.tar.gz)|
|2006/09/06|2 |[chunker-2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-2.tar.gz)|
|2006/05/17|1.5.2|[chunker-1.5.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-1.5.2.tar.gz)|
|2006/05/03|1.5.1|[chunker-1.5.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-1.5.1.tar.gz)|
|2006/02/02|1.5|[chunker-1.5.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-1.5.tar.gz)|
|2005/10/27|1.1|[chunker-1.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-1.1.tar.gz)|
|2005/10/14|1.0|[chunker-1.0.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/chunker-1.0.tar.gz)|



