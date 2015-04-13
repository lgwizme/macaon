## Introduction ##

AlejandroAcosta essaie de garder une version à jour des modules de MACAON installée sur picpus. Il y aura prochainement aussi des scripts divers pour l'utilisation de MACAON (eg. lancer tous les modules sur un repértoire de fichiers à traiter).

## Commande ##

Pour le traitement d'une phrase en ligne de commande (le résultat est écrit dans le fichier _resultat.xml_):
```
picpus$ echo "Je suis une phrase écrite le 5 février"
Je suis une phrase écrite le 5 février
picpus$ echo "Je suis une phrase écrite le 5 février" |
maca_segmenter -x |
maca_tokenizer |
maca_nematcher |
maca_lexer -i - |
maca_hmm_tagger -i - |
maca_anamorph -i - |
maca_chunker -o resultat.xml 
```

Pour le traitement d'un fichier (le fichier texte est _entree.txt_, le résultat est écrit dans le fichier _resultat.xml_):
```
picpus$ maca_segmenter -x -i entree.txt |
maca_tokenizer |
maca_nematcher |
maca_lexer -i - |
maca_hmm_tagger -i - |
maca_anamorph -i - |
maca_chunker -o resultat.xml 
```

NB. Dans tous les cas, faites bien attention à utiliser un encodage UTF-8.

## Autres scripts installés ##

Ces scripts ne font pas partie de MACAON :
  * iule\_xml\_clean (enlève les retours à la ligne ajoutés dans les Elements Text traités avec libxml2)
```
iule_xml_clean -i mon_fichier.xml -o resultat.xml
```
  * iule\_xml\_modify\_structure (simplifie la lecture des documents cf. MacaView)
```
iule_xml_modify_structure -i mon_fichier.xml -o resultat.xml
```
  * iule\_macaon\_txt (est un pipe de `sh`, alors pas d'options)
```
cat mon_texte.txt | iule_macaon_txt > resultat.xml
```
