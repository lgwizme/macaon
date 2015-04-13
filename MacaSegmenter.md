**Voir aussi :** InstallationDeMacaon

# maca\_segmenter #

Découpage d'un document en paragraphes et phrases. A partir de la version 2.3 ce module permet aussi de passer de texte en UTF-8 à un document XML découpé en phrases, c'est le mode txt2xml (qui n'a donc pas besoin d'un document qui suit la DTD d'entrée).

| **Responsable** |AlejandroAcosta|
|:----------------|:--------------|
| **Langage** |C++|
| **Dernière version** |2.5|
| **Date** |10/31/2007|
| **URL** |[maca\_segmenter-2.5.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_segmenter-2.5.tar.gz)|

### Dépendances ###
  * Librairies et programmes externes
    * [xerces-c](http://xml.apache.org/xerces-c/) (XML)

### Commande ###
```
USAGE   : maca_segmenter [options]
OPTIONS :
   -h               show this message
   -V               show version info and exit
   -v               verbose mode (print messages)
   -d               print boundary word set and exit
   -i <file>        xml file to segment (default: stdin)
   -o <file>        xml output file (default: stdout)
   -a <file>        append word set file to defaults
   -r <file>        replace word set defaults with file contents
   -s <name>        segment section with name <name>
   -T               don't leave timestamp info
   -t               txt2txt mode
   -x               txt2xml mode

eg. maca_segmenter -i input.xml -a dico -s content > result.xml
    maca_segmenter -t < in.txt > out.txt 
    maca_segmenter -x < in.txt > out.xml 

A wordset file contains three sections listing: 2 letter words that can be
found at the end of a sentence, and 3 and 4 letter accepted abreviations.
The wordset file contains 1 word per line and three sections enclosed with
the following tags:

   <2CHAR></2CHAR> enclosing the list of two-letter words
   <3CHAR></3CHAR> enclosing the list of three-letter words
   <4CHAR></4CHAR> enclosing the list of four-letter words

```

## Entrée ##
```
<!ELEMENT section (#PCDATA) >
<!ATTLIST section
          analyze (YES|yes) #IMPLIED >
```
Avec l'option `-x` ce module accepte du texte (encodé en UTF-8) en entrée.

## Sortie ##
Le texte des sections à analyser est découpé en paragraphes et phrases qui contient le texte dans des éléments 'text'.

```
<!ELEMENT section (paragraph+) >

<!ELEMENT paragraph (sentence+) >

<!ELEMENT sentence (text)
          id ID #REQUIRED >

<!ELEMENT text (#PCDATA) >
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|2007/10/31|2.5|[maca\_segmenter-2.5.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_segmenter-2.5.tar.gz)|
|2006/12/20|2.4|[maca\_segmenter-2.4.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_segmenter-2.4.tar.gz)|
|2006/11/10|2.3|[macasegmenter-2.3.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/macasegmenter-2.3.tar.gz)|
|2006/11/03|2.2|[macasegmenter-2.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/macasegmenter-2.2.tar.gz)|
|2006/09/27|2.1|[segmenter-2.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/segmenter-2.1.tar.gz)|
|2006/05/01|2 |[segmenter-2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/segmenter-2.tar.gz)|