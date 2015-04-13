# Introduction #

Le XML des documents MACAON peut être difficile à lire. C'est sur tout l'analyse en chunks qui échappe facilement à l'oeil. Il existe une manière d'avoir un meilleur apperçu (mais pas exhaustif) d'un document.

Essayez de voir : [exemple-0.2.xml](http://www.linguist.jussieu.fr/~aacosta/macaon/exemples/exemple-0.2.xml)

# Détails #

Il existe un module non officiel sur picpus (cf. VersionSurPicpus) : iule\_xml\_modify\_structure qui permet de créer des documents qui peuvent être visualisés de cette manière.

```
iule_xml_modify_structure -i in.xml -o out.xml
```

Si vous utilisez le navigatuer Safari vous pouvez voir la structure de l'exemple juste en ouvrant un fichier qui ait été filtré avec ce module (les informations du style se trouvent sur le web).

Si vous utilisez un autre navigateur il est possible (c'est le cas pour Firefox, par exemple) qu'il ne vous permette pas de pointer vers une feuille de style qui se trouve sur un serveur qui n'est pas celui de votre document XML. Dans ce cas

  * Créez un document MACAON avec une feille de style.
    * Utilisez iule\_xml\_modify\_structure, ou bien
    * Téléchargez [exemple-0.3.xml](http://www.linguist.jussieu.fr/~aacosta/macaon/exemples/exemple-0.3.xml)
  * Téléchargez [maca\_view-2.0.tar.gz](http://www.linguist.jussieu.fr/~aacosta/macaon/modules/maca_view-2.0.tar.gz)
  * Décompressez maca\_view dans le répertoire de vos fichiers MACAON (le résultat est un répertoire 'style')
  * Ouvrez un fichier MACAON avec votre navigateur

NB. Pour produire des fichiers qui pointent vers une feuille de style en local, utilisez
```
iule_xml_modify_structure -l -i in.xml -o out.xml
```

Pour plus de détails contactez AlejandroAcosta.