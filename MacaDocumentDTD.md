# Introduction #

Décrit un document avec toutes les annotations que les modules Macaon peuvent faire.

| **Dernière version** |0.2.2|
|:----------------------|:----|
| **Date** |2007/02/13|
| **URL** |[maca\_document.dtd](http://www.linguist.jussieu.fr/~aacosta/macaon/dtds/maca_document.dtd)|

## La DTD ##

Cette DTD contient des nombreux commentaires.

```
<!-- 
maca_document-0.2.2.dtd
AA 2007/02/13
Parce que cette description est plus facile à interpréter que l'union des schemas de sortie des modules. 
-->

<!-- 
I. Le "haut" du document
-->

<!ELEMENT document (meta?,content?)>
<!ATTLIST document
          filename CDATA #IMPLIED >

<!ELEMENT meta (maca_stamps?,universe?)>

<!-- Traces du traitement par les différentes modules. -->
<!ELEMENT maca_stamps (maca_stamp+)>

<!ELEMENT maca_stamp EMPTY>
<!ATTLIST maca_stamp
          module CDATA #REQUIRED
          version CDATA #REQUIRED
          timestamp CDATA #REQUIRED >

<!ELEMENT content (head?,body?)>
<!ATTLIST content
          type CDATA #IMPLIED >
 <!-- Le contenu de "head" est volontairement laissé indéfini dans cette DTD, il peut varier en fonction du type du
 document de base. -->

<!ELEMENT body (section*)>

<!ELEMENT section (paragraph+)>
<!ATTLIST section
          id ID #REQUIRED
          name CDATA #IMPLIED
          analyze (yes|no) #IMPLIED > 
 <!-- id :: forme : sn + #. eg, "sn1" NB. A partir de ce point, les IDs des éléments qui se trouvent sous cet élément 
utilisent cet ID comme préfixe. -->
<!-- analyze :: L'intérêt de cet attribut est de permettre de ne pas analyser certaines sections d'un document. Ce qui 
est particulièrement utile pour les sections qui ne contiennent pas du "discours" mais un contenu différent, comme 
une bibliographie. -->

<!ELEMENT paragraph (sentence+)>
<!ATTLIST paragraph
          id ID #REQUIRED >
<!-- id :: forme : sectionID + p + #. eg, "sn1p1" -->


<!--
II. La partie qui concerne les annotations (principalement) morpho-syntaxiques qui ont une portée qui ne dépasse 
pas le niveau de la phrase.
-->

<!ELEMENT sentence (text,tokens?,words?,chunks?) >
<!ATTLIST sentence
          id ID #REQUIRED >
<!-- id :: forme : paragraphID + s + #. eg, "sn1p1s3" -->

<!ELEMENT text (#PCDATA)>

 <!-- Unités indivisibles -->
<!ELEMENT tokens (token|ne)+>
<!ATTLIST tokens
          count CDATA #IMPLIED >

<!ELEMENT token (#PCDATA)>
<!ATTLIST token
          type CDATA #IMPLIED
          id ID #REQUIRED >

<!-- Entités nommées -->
<!ELEMENT ne (token+)>
<!ATTLIST ne
          id ID #REQUIRED
          pos CDATA #REQUIRED
          type CDATA #REQUIRED
          referent IDREF #IMPLIED >
<!-- id :: forme : sentenceID + t + #. eg, "sn1p1s3t4" -->
<!-- pos :: ou #IMPLIED (et laisser le taggeur deviner si elle n'apparait pas ici)? --><!-- La question qui concerne le 
niveau de description des entités nommées est encore ouverte. Dans ce schema, les entités nommées ne peuvent 
être que des séquences insécables de tokens. Dans l'avenir, elles pourraient passer à un autre niveau (des words ou 
chunks), ou apparaître à plusieurs niveaux. -->

<!-- mots -->
<!ELEMENT words (word+) >
<!ATTLIST words
          count CDATA #IMPLIED >

<!ELEMENT word (form,pos) >
<!ATTLIST word
          id ID #REQUIRED
          tokens IDREFS #REQUIRED
          lex_id CDATA #IMPLIED
          type CDATA #IMPLIED >
<!-- id :: forme : sentenceID + w + #. eg, "sn1p1s3w2" -->
<!-- tokens :: Cet attribut a été proposé pour avoir une manière d'accéder à la chaîne de caractères originale à partir
 des mots. La définition d'un word a changée depuis et elle a intégré l'élément "form", qui contient cette chaîne. Cet 
attribut pourrait donc disparaître. -->
<!-- lexid :: Reste à voir si cet attribut doit être mentionné dans un schema de validation, ou bien si "le cacher", 
étant donné qu'il s'agit d'une annotation qui concerne une implémentation précise. -->

<!ELEMENT form (#PCDATA) >

<!-- partie du discours -->
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
<!-- type :: 2006/11/17 AA ne sait pas à quoi il correspond cet attribut. -->

<!ELEMENT chunks (chunk+)>
<!ATTLIST chunks 
          count CDATA #IMPLIED  
          higher CDATA #IMPLIED >
<!-- higher :: Cet attribut permet à un module de traitement de connaître la profondeur de la structure de chunks la 
plus profonde. Pour l'instant, il n'y a aucun module proposé qui ait besoin de cette information. L'attribut pourrait 
donc disparaître dans le futur. -->

<!ELEMENT chunk (chunk*) >
<!ATTLIST chunk
          id ID #REQUIRED
          type CDATA #REQUIRED         
          head IDREF #IMPLIED
          height (0|1|2|3|4|5|6|7|8|9) #IMPLIED
          function CDATA #IMPLIED
          referent IDREF #IMPLIED >
<!-- id :: forme : sentenceID + c + #. eg, "sn1p1s3c7" -->
<!-- height :: Cet attribut permet à un module de traitement de connaître la profondeur de la structure de chunks -->


<!--
III. Cette partie concerne les annotations sur les entites de l'univers, leur déclaration et les liens de corréférece.
-->

<!ELEMENT universe (referents?,reference_links?)>

<!ELEMENT referents (referent+)>

<!ELEMENT referent EMPTY>
<!ATTLIST referent
          id ID #REQUIRED
          type CDATA #IMPLIED
          external_id IDREF #IMPLIED >
<!-- forme : e + #. eg, "e1" -->
<!-- eg. "idENTITY_007-James_Bond" Tout comme 'lexid' cet attribut fait référence à une ressource externe. Reste à
 voir s'il devrait donc apparaître dans une définition générique du schema de validation de document. -->

<!ELEMENT reference_links (ref_link+) >
<!ATTLIST reference_links
          count CDATA #IMPLIED >

<!ELEMENT ref_link EMPTY >
<!ATTLIST ref_link
          id ID #REQUIRED
          type CDATA #REQUIRED
          source IDREF #REQUIRED
          antecedent IDREFS #REQUIRED
          referent IDREF #IMPLIED >
<!-- id :: forme : l + #. eg, "l5" -->
```

## Historique des révisions ##

| **Date** | **Version** | **URL** |
|:---------|:------------|:--------|
|2007/02/13|0.2.2|[maca\_document-0.2.2.dtd](http://www.linguist.jussieu.fr/~aacosta/macaon/dtds/maca_document-0.2.2.dtd)|
|2006/11/17|0.2.1|[maca\_document-0.2.1.dtd](http://www.linguist.jussieu.fr/~aacosta/macaon/dtds/maca_document-0.2.1.dtd)|
|2006/11/17|0.2|[macadocument-0.2.dtd](http://www.linguist.jussieu.fr/~aacosta/macaon/dtds/maca_document-0.2.dtd)|
|2005/11/16|0.1|[macadocument-0.1.dtd](http://www.linguist.jussieu.fr/~aacosta/macaon/dtds/maca_document-0.1.dtd)|



