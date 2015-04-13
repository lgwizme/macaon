**Voir aussi :** InstallationDeMacaon, TagsetTokenizer

# maca\_tokenizer #

Découpe les phrases d'un document en unités indivisibles.

| **Responsable** |AlejandroAcosta|
|:----------------|:--------------|
| **Langage** |C/Python|
| **Dernière version** |1.7|
| **Date** |05/06/2008|
| **URL** |[maca\_tokenizer-1.7](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.7.tar.gz)|

Avec l'installation de ce module, la librarie python 'pytok', contenant une seule fonction: 'lex' est aussi installée.

### Dépendances ###
  * Librairies et programmes externes
    * python-dev
    * [flex](http://flex.sourceforge.net/)
    * [PyXML](http://pyxml.sourceforge.net/) (optionelle)

### Commande ###
```
USAGE  : maca_tokenizer [OPTIONS]
OPTIONS:
    -h,--help             show this message
    -v,--verbose          print messages
    -i,--input <file>     read input from <file> (defualt is stdin)
    -o,--output <file>    wite output to <file> (default is stdout)
    -b,--batch <dir>      batch mode : (destructively) process files in <dir>
    -e,--element <name>   name of the element to tokenize (default is text)
    -t,--tokens <name>    name of the token element (default is token)
    -n,--no name[,name]*  don't output: id (<token> attribute)
                                        type (<token> attribute)
                                        pos (<token> attribute)
                                        count (<tokens> attribute)
                                        space (space tokens)
                                        space-id ('space' <token> attribute)
                                        unknown (unknown character tokens)
                                        timestamp (module timestamp)

eg. cat input.xml | maca_tokenizer -e text -t token -v -n id,space -v
```

## Entrée ##
Le tokenizer cherche les éléments 

&lt;text&gt;

 dans les 

&lt;sentence&gt;

s du document XML.

```
<!ELEMENT sentence (text)
          id ID #REQUIRED >

<!ELEMENT text (#PCDATA) >
```

## Sortie ##
Le tokenizer ajoute une liste de 

&lt;token&gt;

s  typés dans un élément 

&lt;tokens&gt;

 qui suit l'élément 

&lt;text&gt;

 dans les phrases du document.

```
<!ELEMENT sentence (text,tokens)
          id ID #REQUIRED >

<!ELEMENT text (#PCDATA) >

<!ELEMENT tokens (token+) >
<!ATTLIST tokens
          count CDATA #IMPLIED >

<!ELEMENT token (#PCDATA) >
<!ATTLIST token
          type CDATA #IMPLIED
          id ID #REQUIRED >
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|2008/06/05|1.7|[maca\_tokenizer-1.7.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.7.tar.gz)|
|2008/02/05|1.6|[maca\_tokenizer-1.6.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.6.tar.gz)|
|2007/10/16|1.5.2|[maca\_tokenizer-1.5.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.5.2.tar.gz)|
|2007/09/18|1.5.1|[maca\_tokenizer-1.5.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.5.1.tar.gz)|
|2007/06/22|1.5|[maca\_tokenizer-1.5.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.5.tar.gz)|
|2007/06/20|1.4|[maca\_tokenizer-1.4.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.4.tar.gz)|
|2007/05/29|1.3|[maca\_tokenizer-1.3.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.3.tar.gz)|
|2007/02/09|1.2.2|[maca\_tokenizer-1.2.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.2.2.tar.gz)|
|2006/12/16|1.2.1|[maca\_tokenizer-1.2.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_tokenizer-1.2.1.tar.gz)|
|2006/11/30|1.2|[macatokenizer-1.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/macatokenizer-1.2.tar.gz)|
|2006/09/27|1.1|[macatokenizer-1.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/macatokenizer-1.1.tar.gz)|

