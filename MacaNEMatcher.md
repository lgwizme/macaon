**Voir aussi :** InstallationDeMacaon

# maca\_nematcher #

Utilise  des expressions régulières et des dictionnaires fournis par l'utilisateur pour regrouper des unités indivisibles en entités typées (date, oraganisation, personne, lieu, ...) dites "entités nommées".

| **Responsable** |AlejandroAcosta|
|:----------------|:--------------|
| **Langage** |Python|
| **Dernière version** |2.0|
| **Date** |18/01/2008|
| **URL** |[maca\_nematcher-2.0](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-2.0.tar.gz)|

L'accès à un dictionnaire dans une base de données MySQL n'est pas encore configurable en ligne de commande et restera cachée jusqu'à ce qu'elle puisse être mieux implémentée.

### Dépendances ###
  * Librairies et programmes externes
    * [PyXML](http://pyxml.sourceforge.net/)
    * [MySQLdb](http://sourceforge.net/projects/mysql-python) (optionnelle)

## Commande ##
```
I. Using a configuration bundle
USAGE  : ./maca_nematcher [OPTIONS] config-bundle.tgz
OPTIONS:
    -h,--help            show this messaeg
    -V,--version         show version info and exit
    -v,--verbose         print messages (used twice: very verbose)
    -c,--chrono          print time stats
    -b,--batch <dir>     batch mode : process files in <dir>
    -i <file>            read input from <file> (default is stdin)
    -o <file>            write output to <file> (default is stdout)

eg. ./maca_nematcher -b /dir/to/process path/to/confBundle.tgz


II. Configuration in command (also accepts options above)
USAGE  : ./maca_nematcher [OPTIONS]
OPTIONS:
    -r <file>            load <file> describing regex ne patterns
    -d <file>            load <file> (several files can be loaded)
    -T                   don't leave timestamp info
    -D                   don't match default date patterns
    -w n                 size 'n' for the lookup window (default is 5)
    -I                   ignore sentences that don't contain <ne>s
    --pickle <file>      load dictionary pickle <file>   

eg. ./maca_nematcher -b /batch/dir -d noms.dict -r time.patt -w 9
```

## Entrée ##
La sortie de MacaTokenizer.

```
<!ELEMENT sentence (tokens) >

<!ELEMENT tokens (token+) >

<!ELEMENT token (#PCDATA) >
<!ATTLIST token
          type CDATA #IMPLIED
          id ID #REQUIRED >
```

## Sortie ##
Les séquences de 

&lt;token&gt;

s reconnues comme entités nommées sont rangées dans des éléments 

&lt;ne&gt;

.

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

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|18/01/2008|2.0|[maca\_nematcher-2.0.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-2.0.tar.gz)|
|20/09/2007|1.8|[maca\_nematcher-1.8.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.8.tar.gz)|
|09/07/2007|1.7.1|[maca\_nematcher-1.7.1.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.7.1.tar.gz)|
|26/06/2007|1.7|[maca\_nematcher-1.7.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.7.tar.gz)|
|15/03/2007|1.6|[maca\_nematcher-1.6.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.6.tar.gz)|
|26/02/2007|1.5|[maca\_nematcher-1.5.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.5.tar.gz)|
|13/12/2006|1.4.3|[maca\_nematcher-1.4.3.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_nematcher-1.4.3.tar.gz)|
|24/11/2006|1.4.2|[macanematcher-1.4.2.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/macanematcher-1.4.2.tar.gz)|